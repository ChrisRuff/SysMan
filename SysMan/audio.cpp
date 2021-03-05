#include "audio.h"


// name: <alsa_output.usb-Kingston_HyperX_7.1_Audio_00000000-00.analog-stereo>
Audio::Audio(QFrame* AudioFrame)
{
    QRegularExpression sinkIdentifier = QRegularExpression("name: <.*>");
    QRegularExpression selectedSinkIdentifier = QRegularExpression("\\* index: [0-9]+");
    QRegularExpression sinkNameIdentifier = QRegularExpression("device.product.name = \".*\"");
    audioController.start("/usr/bin/pacmd", QStringList("list-sinks"));
    audioController.waitForFinished(); // will wait for 30 seconds

    QByteArray stdout = audioController.readAllStandardOutput();
    auto curMatch = selectedSinkIdentifier.match(stdout);
    int curSink = INT_MAX;
    if(curMatch.hasMatch())
    {
        qDebug() << curMatch.captured();
        curSink = std::stoi(curMatch.captured().toStdString().substr(9));
    }

    auto matches = sinkIdentifier.globalMatch(stdout);
    auto names = sinkNameIdentifier.globalMatch(stdout);
    int i = 0;

    while(matches.hasNext())
    {
        auto match = matches.next();
        auto nameMatch  = names.next();

        std::string name = nameMatch.captured().toStdString();
        std::string device = match.captured().toStdString();

        name = name.substr(23, name.length());
        name.erase(name.length()-1);
        device = device.substr(7, device.length());
        device.erase(device.length()-1);

        QPushButton* btn = new QPushButton(AudioFrame);
        btn->setGeometry(0, btnSize * i + 2*i, name.length() * 8, btnSize);
        btn->setText(QString::fromStdString(name));
        if(i == curSink)
        {
            btn->setStyleSheet("font-weight: bold;");
            selected = device;
        }
        connect(btn, &QPushButton::clicked, [=](){switchDevice(device);});

        deviceButtons.insert({device, btn});
        i++;
    }
}
void Audio::switchDevice(std::string device)
{
    if(deviceButtons[selected] != nullptr)
            deviceButtons[selected]->setStyleSheet(QString("font-weight: normal;"));
    if(deviceButtons[device] != nullptr)
            deviceButtons[device]->setStyleSheet(QString("font-weight: bold;"));

    qDebug() << "Switching to device: " << QString::fromStdString(device);
    audioController.start("/usr/bin/pacmd",
                            QStringList({"set-default-sink", QString::fromStdString(device)}));

    audioController.waitForFinished(); // will wait for 30 seconds
    selected = device;
}
