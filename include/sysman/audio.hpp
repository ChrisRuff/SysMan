#ifndef AUDIO_H
#define AUDIO_H
// std
#include <unordered_map>
#include <vector>
#include <memory>
#include <filesystem>

// qt
#include <QProcess>
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QRegularExpression>
#include <QFrame>
#include <QFileDialog>

#include "./ui_home.h"

class Audio : public QObject
{
private:
	QStringList sinks{};
	QProcess audioController{};

	std::vector<int> sink_indexs{};

	// Frames for audio
	std::shared_ptr<QFrame> deviceFrame;
	std::shared_ptr<QFrame> sinkFrame;
	std::shared_ptr<QFrame> soundFrame;

	// Default devices vars
	std::pair<int, QString> selected{};
	std::unordered_map<QString, QPushButton*> deviceButtons{};

	// Audio mixing vars
	std::shared_ptr<QListView> inputs{};
	std::shared_ptr<QListView> outputs{};
	std::shared_ptr<QStringListModel> in_model{};
	std::shared_ptr<QStringListModel> out_model{};
	std::unordered_map<QString, int> output_devices{};
	std::unordered_map<QString, int> input_devices{};

	static constexpr int btnSize{20};
	static constexpr int rate{44100};
	const QString format{"s16le"};

	// Soundboard vars
	std::vector<std::unique_ptr<QPushButton>> sound_buttons{};
	std::vector<QString> files{};

public:
	void getInputs();
	void getOutputs();
	void getSources();

private slots:
	// Default device
	void switchDevice(std::pair<int,QString> device);

	// Mix audio
	void makeSink();
	void update();

	// Soundboard
	void add();
	void load();
	void save();
	void play(int i);

public slots:
	void reset();

public:
	Audio(std::shared_ptr<Ui::Home> audioFrame);
};

#endif // AUDIO_H
