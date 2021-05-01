#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include <QCloseEvent>

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

	void closeEvent(QCloseEvent* event) override;
private:
	Ui::Home *ui;
	Audio* audio;

};
#endif // HOME_H
