#include "setupWindow.h"
#include "qtextedit.h"
#include "qlayout.h"
#include "qdatetime.h"
#include "qcoreapplication.h"
setupWindow::setupWindow(QWidget *parent):
QMainWindow(parent),
ui(new Ui::setupWindow)
{
	ui->setupUi(this);
	connect(ui->enterBt, SIGNAL(clicked()), this, SLOT(showMainWindow()));
}

setupWindow::~setupWindow()
{
	delete ui;
}

void setupWindow::showMainWindow()
{
	mu.show();
	connect(&mu, SIGNAL(ret()), this, SLOT(appear()));
	this->hide();
}

void setupWindow::appear(){
	this->show();
}