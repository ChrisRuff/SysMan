#ifndef AUDIO_H
#define AUDIO_H
#include <unordered_map>

#include <vector>
#include <QProcess>
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <QStringListModel>
#include <QListView>
#include <QRegularExpression>
#include <QFrame>

class Audio : public QObject
{
private:
	QStringList sinks{};
	QProcess audioController{};

	QListView* inputs;
	QListView* outputs;
	QStringListModel* in_model;
	QStringListModel* out_model;

	std::vector<int> sink_indexs{};

	std::unordered_map<QString, int> output_devices{};
	std::unordered_map<QString, int> input_devices{};

	QFrame* deviceFrame;
	QFrame* sinkFrame;
	static constexpr int btnSize{20};
	static constexpr int rate = 48000;
	const QString format{"s16le"};
	std::pair<int, QString> selected{};

	std::unordered_map<QString, QPushButton*> deviceButtons{};

public:
	void getInputs();
	void getOutputs();
	void getSources();

private slots:
	void switchDevice(std::pair<int,QString> device);
	void makeSink();
	void update();

public slots:
	void reset();

public:
	Audio(QFrame* deviceFrame, QFrame* sinkFrame);
};

#endif // AUDIO_H
