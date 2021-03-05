#ifndef HOME_H
#define HOME_H

#include <QMainWindow>

#include <audio.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
    Q_OBJECT

public:
    Home(QWidget *parent = nullptr);
    ~Home();

private:
    Ui::Home *ui;
    Audio* audio;
};
#endif // HOME_H
