#ifndef AUDIO_H
#define AUDIO_H
#include <unordered_map>

#include <QProcess>
#include <QDebug>
#include <QPushButton>
#include <QRegularExpression>
#include <QFrame>

class Audio : public QObject
{
private:
    QStringList sinks{};
    QProcess audioController{};
    static constexpr int btnSize{20};

    std::unordered_map<std::string, QPushButton*> deviceButtons{};

public:
    std::string selected{};

private slots:
    void switchDevice(std::string device);

public:
    Audio(QFrame* deviceFrame);
};

#endif // AUDIO_H
