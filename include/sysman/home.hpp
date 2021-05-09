#ifndef HOME_H
#define HOME_H

// std
#include <memory> // unique_ptr, make_unique, shared_ptr, make_shared

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
	std::shared_ptr<Ui::Home> ui{nullptr};
	std::unique_ptr<Audio> audio{nullptr};

public:
	Home(QWidget *parent = nullptr);

	void closeEvent(QCloseEvent* event) override;

};
#endif // HOME_H
