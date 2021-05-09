#include "audio.hpp"


// name: <alsa_output.usb-Kingston_HyperX_7.1_Audio_00000000-00.analog-stereo>
Audio::Audio(QFrame* deviceFrame, QFrame* sinkFrame) : deviceFrame(deviceFrame), sinkFrame(sinkFrame)
{
	// Find and set UI elements
	outputs = sinkFrame->findChild<QListView*>(QString("outputs"));
	inputs = sinkFrame->findChild<QListView*>(QString("inputs"));
	outputs->setSelectionMode(QAbstractItemView::ExtendedSelection);
	inputs->setSelectionMode(QAbstractItemView::ExtendedSelection);


	in_model = new QStringListModel(sinkFrame);
	out_model = new QStringListModel(sinkFrame);

	// Populate items
	getInputs();
	getOutputs();
	getSources();

	// Connect buttons
	connect(sinkFrame->findChild<QPushButton*>(QString("make_output")), &QPushButton::clicked, [=](){makeSink();});
	connect(sinkFrame->findChild<QPushButton*>(QString("reset")), &QPushButton::clicked, [=](){reset();});
	connect(sinkFrame->findChild<QPushButton*>(QString("refresh")), &QPushButton::clicked, [=](){update();});

}
void Audio::switchDevice(std::pair<int, QString> device)
{
	// Unbold the previously selected device
	if(deviceButtons[selected.second] != nullptr)
			deviceButtons[selected.second]->setStyleSheet(QString("font-weight: normal;"));

	// Bold the newly selected device
	if(deviceButtons[device.second] != nullptr)
			deviceButtons[device.second]->setStyleSheet(QString("font-weight: bold;"));

	qDebug() << "Switching to device: " << device.second;

	// Set the new device as the sink
	audioController.start("/usr/bin/pacmd",
							QStringList({"set-default-sink", device.second}));
	audioController.waitForFinished(); // will wait for 30 seconds

	// Store current device
	selected = device;
}

void Audio::getInputs()
{
	QRegularExpression inputsIdentifier = QRegularExpression("index: \\d+\\n\\tname: <alsa_input.*>(?s)(.*?)alsa\\.card_name = \"(.*?)\"");

	audioController.start("/usr/bin/pacmd", QStringList("list-sources"));
	audioController.waitForFinished(); // will wait for 30 seconds

	QByteArray stdout = audioController.readAllStandardOutput();
	auto matches = inputsIdentifier.globalMatch(stdout);

	input_devices = std::unordered_map<QString, int>{};

	while(matches.hasNext())
	{
		auto match = matches.next();
		input_devices.insert({match.captured().section('"', -2, -2),
				match.captured().section(' ', 1, 1).section('\n', 0, 0).toInt()});
	}
	QStringList inputStrings{};
	for(const auto& val : input_devices)
	{
		inputStrings << val.first;
	}
	in_model->setStringList(inputStrings);
	inputs->setModel(in_model);
}
void Audio::getSources()
{
	// Regex to find the name and index of each source device
	// These are things are like Spotify, or applications with audio
	QRegularExpression indexIdentifier = QRegularExpression("index: [0-9]+");
	QRegularExpression sourceIdentifier = QRegularExpression("application.name = \".*\"");

	// Get sources
	audioController.start("/usr/bin/pacmd", QStringList("list-sink-inputs"));
	audioController.waitForFinished(); // will wait for 30 seconds

	// Parse sources and find each match
	QByteArray stdout = audioController.readAllStandardOutput();
	auto indexs = indexIdentifier.globalMatch(stdout);
	auto names = sourceIdentifier.globalMatch(stdout);

	// Map for devices
	output_devices = std::unordered_map<QString, int>{};

	while(indexs.hasNext() && names.hasNext())
	{
		auto indexMatch = indexs.next();
		auto nameMatch  = names.next();
		
		// Insert each device in the map like this:
		// {Spotify: 5} -> Spotify is at index 5 of the sink inputs
		output_devices.insert({nameMatch.captured().section('"', 1, 1),
			indexMatch.captured().section(' ', 1, 1).toInt()});
	}

	// Fill output ListView
	QStringList outputStrings{};
	for(const auto& val : output_devices)
	{
		outputStrings << val.first;
	}
	out_model->setStringList(outputStrings);
	outputs->setModel(out_model);
}
void Audio::getOutputs()
{
	// Regex to extract info from commandline output
	QRegularExpression outputIdentifier = QRegularExpression("index: [0-9]+\\n\\tname: <.*>");
	QRegularExpression selectedOutputIdentifier = QRegularExpression("\\* index: [0-9]+");
	QRegularExpression outputNameIdentifier = QRegularExpression("alsa.card_name = \".*\"");

	// Get the audio sinks 
	audioController.start("/usr/bin/pacmd", QStringList("list-sinks"));
	audioController.waitForFinished(); // will wait for 30 seconds

	// Parse sinks retrieved from command line
	QByteArray stdout = audioController.readAllStandardOutput();
	auto curMatch = selectedOutputIdentifier.match(stdout);
	int curSink = INT_MAX;

	// If one sink is set to default sink mark it
	if(curMatch.hasMatch())
	{
		// Get value of index
		curSink = std::stoi(curMatch.captured().toStdString().substr(9));
	}

	// Find all sink names and indexs
	auto matches = outputIdentifier.globalMatch(stdout);
	auto names = outputNameIdentifier.globalMatch(stdout);

	int i = 0;
	while(matches.hasNext() && names.hasNext())
	{
		auto match = matches.next();
		auto nameMatch = names.next();

		// Get the index and the name from regex output
		int deviceIndex = match.captured().section(' ', 1, 1).section('\n', 0, 0).toInt();
		QString deviceName = match.captured().section(' ', 2, 2);

		// Get the card name(the device name is rather illegible so we'll use this for display)
		std::string name = nameMatch.captured().toStdString();

		// Isolate the card name from the regex output
		name = name.substr(18, name.length());
		name.erase(name.length()-1);

		// Remove <>
		deviceName.remove(0,1);
		deviceName.remove(deviceName.size()-1, 1);

		std::pair<int, QString> device = std::make_pair(deviceIndex, deviceName);

		// Add to devices frame 
		QPushButton* btn = new QPushButton(deviceFrame);
		btn->setGeometry(0, btnSize * i + 2*i, name.length() * 8, btnSize);
		btn->setText(QString::fromStdString(name));
		if(deviceIndex == curSink)
		{
			// Make the default sink bold and track it
			btn->setStyleSheet("font-weight: bold;");
			selected = std::make_pair(i, QString(deviceName));
		}

		// Pressing the button will switch to that device
		connect(btn, &QPushButton::clicked, [=](){switchDevice(device);});

		deviceButtons.insert({deviceName, btn});
		i++;
	}
}
void Audio::reset()
{
	// Remove all created sinks
	for(int sink : sink_indexs)
	{
		audioController.start("/usr/bin/pactl",
								QStringList({"unload-module", QString::number(sink)}));
		audioController.waitForFinished(); // will wait for 30 seconds
	}
}
void Audio::update()
{
	getSources();
	getInputs();
	getOutputs();
}

void Audio::makeSink()
{
	// Ensure the default sink is set
	if(selected.second.isEmpty())
		return;

	// Clear previously made sinks
	reset();

	// Make a null sink that will have the mic audio and apps(port to microphone)
	audioController.start("/usr/bin/pactl",
							QStringList({"load-module", "module-null-sink", 
								"sink_name=sysman", "sink_properties=device.description=SysMan-(App+Mic)-Sink", 
								"format="+QString(format), "rate="+QString::number(rate)}));
	audioController.waitForFinished(); // will wait for 30 seconds

	// Add sink to list of created sinks
	QByteArray stdout = audioController.readAllStandardOutput();
	sink_indexs.push_back(stdout.trimmed().toInt()); // Remove newline


	// Make a null sink that will have all applications on the client machine(port to headphones)
	audioController.start("/usr/bin/pactl",
							QStringList({"load-module", "module-combine-sink", 
								"sink_name=audio", "slaves=" + selected.second, "sink_properties=device.description=SysMan-Audio", 
								"format="+format, "rate="+QString::number(rate)}));
	audioController.waitForFinished(); // will wait for 30 seconds

	// Add sink to list of created sinks
	stdout = audioController.readAllStandardOutput();
	sink_indexs.push_back(stdout.trimmed().toInt()); // Remove newline


	// Store the index of the audio sink
	int audioIndex = stdout.trimmed().toInt(); // Remove newline

	// Set the audio sink as the default sink 
	audioController.start("/usr/bin/pacmd",
							QStringList({"set-default-sink", QString(audioIndex)}));
	audioController.waitForFinished(); // will wait for 30 seconds

	// Create a sink to join all app audio that will be sent to headphones AND the microphone
	audioController.start("/usr/bin/pactl",
							QStringList({"load-module", "module-combine-sink", "sink_name=apps", 
								"slaves=sysman,audio", "sink_properties=device.description=SysMan-Apps", 
							"format="+format, "rate="+QString::number(rate)}));
	audioController.waitForFinished(); // will wait for 30 seconds

	// Add sink to list of created sinks
	stdout = audioController.readAllStandardOutput();
	sink_indexs.push_back(stdout.trimmed().toInt()); // Remove newline

	// Go through each source(unselected too)
	for(const auto& device : output_devices)
	{
		// Move it's output to the app sink
		audioController.start("/usr/bin/pactl",
							QStringList({"load-module", "move-sink-input", device.first, "audio"}));
		audioController.waitForFinished(); // will wait for 30 seconds
	}


	// Go through each selected source(Spotify, Chrome...)
	QStringList sources;
	for(const QModelIndex& index : outputs->selectionModel()->selectedIndexes())
	{
		QString device = out_model->data(index).toString();
		sources.append(QString::number(output_devices[device]) + " " +  device);

		// Move it's output to the app sink
		audioController.start("/usr/bin/pactl",
							QStringList({"load-module", "move-sink-input", QString(output_devices[device]), "apps"}));
		audioController.waitForFinished(); // will wait for 30 seconds
	}


	// Go through each selected input (mics)
	QStringList mics;
	for(const QModelIndex& index : inputs->selectionModel()->selectedIndexes())
	{
		QString device = in_model->data(index).toString();
		mics.append(QString::number(input_devices[device]) + " " + device);

		// Make a loopback that will go to the sysman(Mic+App) null sink
		audioController.start("/usr/bin/pactl", QStringList{"load-module", "module-loopback", 
			"source="+QString::number(input_devices[device]), "sink=sysman", 
			"latency_msec=5", "format="+format, "rate="+QString::number(rate)});
		audioController.waitForFinished(); // will wait for 30 seconds

		// Add sink to list of created sinks
		stdout = audioController.readAllStandardOutput();
		sink_indexs.push_back(stdout.trimmed().toInt()); // Remove newline
	}
}
