#include "home.hpp"
#include "./ui_home.h"

Home::Home(QWidget *parent)
	: QMainWindow(parent)
	, ui(std::make_shared<Ui::Home>())
{
	ui->setupUi(this);
	audio = std::make_unique<Audio>(ui);
}

void Home::closeEvent(QCloseEvent* event)
{
	event->accept();
	qDebug() << "Destroying sinks";
	audio->reset();
}
