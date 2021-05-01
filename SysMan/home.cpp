#include "home.h"
#include "./ui_home.h"

Home::Home(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::Home)
{
	ui->setupUi(this);
	audio = new Audio(ui->Devices, ui->Sinks);
}


Home::~Home()
{
	delete ui;
}

void Home::closeEvent(QCloseEvent* event)
{
	qDebug() << "Destroying sinks";
	audio->reset();
}
