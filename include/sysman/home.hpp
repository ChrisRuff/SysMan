#ifndef HOME_H
#define HOME_H

// std
#include <memory> // unique_ptr, make_unique

// qt
#include <QMainWindow>
#include <QCloseEvent>

// source
#include "audio.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class Home; }
QT_END_NAMESPACE

class Home : public QMainWindow
{
	Q_OBJECT

private:
	Ui::Home* ui;
	std::unique_ptr<Audio> audio{nullptr};

public:
	Home(QWidget *parent = nullptr);
	~Home();

	void closeEvent(QCloseEvent* event) override;

};
#endif // HOME_H
