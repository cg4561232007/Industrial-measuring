/*******************************change log**********************************/
//绘制有效值的窗口，绘制五条曲线的有效值.
#include "effLine.h"
#include "qdebug.h"
#include "qapplication.h"
#include "qdesktopwidget.h"
#include "qmessagebox.h"
#include "qdir.h"
#include "commonFunc.h"
#define WIDTH 1300
#define HEIGHT 700
#define INITIAL_X 200
#define INTTIAL_Y 60
#define PI 3.14159265358979323846

effLine::effLine(QWidget *parent):
QWidget(parent),
ui(new Ui::effLine)
{
	ui->setupUi(this);
	int desktop_width = QApplication::desktop()->width();
	int desktop_high = QApplication::desktop()->height();
	this->resize(desktop_width, desktop_high);
	//this->setWindowFlags(Qt::FramelessWindowHint); // hide title pannel
	ui->settingbt->move(QPoint(1500,50));
	ui->snapbt->move(QPoint(1500, 80));
	ui->retbt->move(QPoint(1500, 800));
	ui->label_2->setWordWrap(true);
	ui->label_2->setAlignment(Qt::AlignTop);
	ui->label->move(QPoint(desktop_width/2,desktop_high-100));

	//table widget
	QStringList headers;
	headers << QString::fromLocal8Bit(" 扫频范围 ") << QString::fromLocal8Bit(" 扫频方式 ") << QString::fromLocal8Bit(" 扫频点数 ")
		<< QString::fromLocal8Bit(" 当前频点 ") << QString::fromLocal8Bit(" 当前频率 ") << QString::fromLocal8Bit(" 幅度响应 ")
		<< QString::fromLocal8Bit(" 相频响应 ");
	ui->tb_Param->setRowCount(7);  
	ui->tb_Param->setColumnCount(1); 
	ui->tb_Param->setVerticalHeaderLabels(headers);
	ui->tb_Param->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("1 - 1000 kHZ")));
	ui->tb_Param->setItem(1, 0, new QTableWidgetItem(QString::fromLocal8Bit("线性")));
	ui->tb_Param->setItem(2, 0, new QTableWidgetItem("1000"));
	ui->tb_Param->setItem(3, 0, new QTableWidgetItem("200"));
	ui->tb_Param->setItem(4, 0, new QTableWidgetItem("200KHZ"));
	ui->tb_Param->setItem(5, 0, new QTableWidgetItem("2db"));
	ui->tb_Param->setItem(6, 0, new QTableWidgetItem("30"));
	ui->tb_Param->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tb_Param->resizeRowsToContents();

	QStringList horizon_headers;
	horizon_headers << QString::fromLocal8Bit("频率(KHZ)") << QString::fromLocal8Bit("幅频(dB)") << QString::fromLocal8Bit("相频(deg)");
	ui->tb_datas->setRowCount(1000);
	ui->tb_datas->setColumnCount(3);
	ui->tb_datas->setHorizontalHeaderLabels(horizon_headers);
	ui->tb_datas->resizeRowsToContents();
	ui->tb_datas->resizeColumnsToContents();
	ui->tb_datas->setEditTriggers(QAbstractItemView::NoEditTriggers);

	width = desktop_width * 4 / 5;
	height = desktop_high * 4 / 5;
	rect = QRect(0, 0, width, height);
	m_pen_width = 2;
	m_result_pen_width = 1;
	VAL = 1;	//每N个像素显示一个点，即坐标scale
	connect(ui->snapbt, SIGNAL(clicked()), this, SLOT(grabwindow()));
	connect(ui->retbt, SIGNAL(clicked()), this, SLOT(showret()));
}

effLine::~effLine()
{
	delete ui;
}

void effLine::paintEvent(QPaintEvent *qev)
{
	//设置画板画矩形
	painter = new QPainter(this);
	painter->setBrush(Qt::black);
	painter->translate(INITIAL_X, INTTIAL_Y);
	painter->drawRect(rect);
	painter->fillRect(rect, QBrush(QColor(0, 50, 200,127), Qt::SolidPattern));
	painter->begin(this);	//设置画板为当前的widget上
	painter->setPen(QPen(QPen(Qt::white, 1, Qt::SolidLine)));

	//draw the effective line
	
	painter->end();
}

void effLine::drawPoints()
{
	setUpdatesEnabled(true);
	repaint();
}

void effLine::grabwindow()
{
	commonFunc::grabwindow(this, "effLine");
	QMessageBox::information(this, tr("&screenshot"), QStringLiteral("截图成功！"));
}

void effLine::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void effLine::closeEvent(QCloseEvent *e){}
void effLine::showret()
{
	emit ret();
	this->hide();
}