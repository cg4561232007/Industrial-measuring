#include "mainMenu.h"
#define WIRED false
#define WIRELESS true
extern bool wire = WIRED;
extern bool iswaveshow;

mainMenu::mainMenu(QWidget *parent) :
QWidget(parent),
ui(new Ui::mainMenu)
{
	ui->setupUi(this);
	ui->wiredbt->setChecked(false);
	ui->wirelessbt->setChecked(false);
	connect(ui->commbt, SIGNAL(clicked()), this, SLOT(showComm()));
	connect(ui->showhisbt, SIGNAL(clicked()), this, SLOT(showHis()));
	connect(ui->autocheckbt, SIGNAL(clicked()), this, SLOT(showAutoCheck()));
	connect(ui->fixcheckbt, SIGNAL(clicked()), this, SLOT(showFixCheck()));
	connect(ui->plotbt, SIGNAL(clicked()), this, SLOT(showPlot()));
	connect(ui->returnbt, SIGNAL(clicked()), this, SLOT(showret()));
	connect(ui->setButton, SIGNAL(clicked()), this, SLOT(showSet()));
	connect(ui->wiredbt, SIGNAL(clicked()), this, SLOT(setWire()));
	connect(ui->wirelessbt, SIGNAL(clicked()), this, SLOT(setWire()));

	m_childWidget = nullptr;
	m_childWidgetH = nullptr;
	m_childWidgetPlot = nullptr;
	m_childWidgetFix = nullptr;
	m_childWidgetAuto = nullptr;
	svdata = nullptr;
}

mainMenu::~mainMenu()
{
	delete ui;
	if (m_childWidget != nullptr)
		delete m_childWidget;
	if (m_childWidgetH != nullptr)
		delete m_childWidgetH;
	if (m_childWidgetAuto != nullptr)
		delete m_childWidgetAuto;
	if (m_childWidgetFix != nullptr)
		delete m_childWidgetFix;
	if (m_childWidgetPlot != nullptr)
		delete m_childWidgetPlot;
	if (svdata != nullptr)
		delete svdata;
}

void mainMenu::showComm(){
	if (m_childWidget != nullptr){
		m_childWidget->show();
		this->hide();
		return;
	}
	m_childWidget = new Serial_port;
	connect(m_childWidget, SIGNAL(ret()), this, SLOT(appear()));
	m_childWidget->show();
	handle = new mthread;
	svdata = new solvedata(handle);
	svdata->setpal(g_pal);

	handle->start(QThread::NormalPriority);
	qDebug() << "*QThread* handle:-----handle is running in-----: " << handle << QThread::currentThread();
	connect(handle, SIGNAL(sendhandledata()), svdata, SLOT(testdata()));
	this->hide();
}

void mainMenu::showHis(){
	if (m_childWidgetH != nullptr){
		m_childWidgetH->show();
		this->hide();
		return;
	}
	m_childWidgetH = new history();
	connect(m_childWidgetH, SIGNAL(ret()), this, SLOT(appear()));
	m_childWidgetH->show();
	this->hide();
}

void mainMenu::showAutoCheck(){
	if (m_childWidgetAuto != nullptr){
		m_childWidgetAuto->show();
		this->hide();
		return;
	}
	m_childWidgetAuto = new showwave();
	connect(m_childWidgetAuto, SIGNAL(ret()), this, SLOT(appear()));
	if (svdata != nullptr)
	{
		connect(svdata, SIGNAL(sendSVdata(vector<deque<int>>, int, vector<int>, vector<int>, vector<vector<int>>)),
			m_childWidgetAuto, SLOT(getSVdata(vector<deque<int>>, int, vector<int>, vector<int>, vector<vector<int>>)));
		connect(m_childWidgetAuto, SIGNAL(sendStop()), this, SLOT(getStop()));
		connect(m_childWidgetAuto, SIGNAL(sendResume()), this, SLOT(getResume()));
	}
	m_childWidgetAuto->show();
	iswaveshow = true;
	this->hide();
}

void mainMenu::showFixCheck(){
	if (m_childWidgetFix != nullptr){
		m_childWidgetFix->show();
		this->hide();
		return;
	}
	m_childWidgetFix = new fixCheck();
	connect(m_childWidgetFix, SIGNAL(ret()), this, SLOT(appear()));
	if (svdata != nullptr)
	{
		connect(svdata, SIGNAL(sendSVdata(vector<deque<int>>, int, vector<int>, vector<int>, vector<vector<int>>)),
			m_childWidgetFix, SLOT(getSVdata(vector<deque<int>>, int, vector<int>, vector<int>, vector<vector<int>>)));
		connect(m_childWidgetFix, SIGNAL(sendStop()), this, SLOT(getStop()));
		connect(m_childWidgetFix, SIGNAL(sendResume()), this, SLOT(getResume()));
		if (m_childWidget != nullptr)
			connect(m_childWidgetFix, SIGNAL(sendFre(QByteArray)),
			m_childWidget, SLOT(sendfixfre(QByteArray)));
	}
	m_childWidgetFix->show();
	iswaveshow = true;
	this->hide();
}

void mainMenu::showPlot(){
	if (m_childWidgetPlot != nullptr){
		m_childWidgetPlot->show();
		this->hide();
		return;
	}
	m_childWidgetPlot = new effLine();
	connect(m_childWidgetPlot, SIGNAL(ret()), this, SLOT(appear()));
	m_childWidgetPlot->show();
	this->hide();
}

void mainMenu::showSet()
{
	m_settings = new setting();
	connect(m_settings, SIGNAL(transpal(QMap<QString, QString> &)), this, SLOT(setpal(QMap<QString, QString>&)));
	m_settings->show();
}

void mainMenu::showret(){
	emit ret();
	this->hide();
}

void mainMenu::appear(){
	this->show();
}

void mainMenu::setWire(){
	if (ui->wiredbt->isChecked()){
		ui->wirelessbt->setEnabled(true);
		wire = WIRED;
		ui->wiredbt->setEnabled(false);
		qDebug() << "WIRED";
	}
	else if (ui->wirelessbt->isChecked()){
		ui->wiredbt->setEnabled(true);
		wire = WIRELESS;
		ui->wirelessbt->setEnabled(false);
		qDebug() << "WIRELESS";
	}
}

void mainMenu::getStop()
{
	handle->threadpause();
}

void mainMenu::getResume()
{
	handle->threadresume();
}

void mainMenu::setpal(QMap<QString, QString>& pal)
{
	g_pal = pal;
}
