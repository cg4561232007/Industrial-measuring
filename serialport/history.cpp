#include "history.h"
#include "commonFunc.h"
#include "qdir.h"
#include "qmessagebox.h"
#include "qdebug.h"
#include "qfiledialog.h"
#include "qtimer.h"
#include <fstream>
#include <sstream>

//显示区域设置
#define WIDTH 1200
#define HEIGHT 660
#define REC_WID 900
#define REC_HEI 650
#define INITIAL_X 115
#define INTTIAL_Y 45
#define PI 3.14159265358979323846
#define min(a,b) (a>b?b:a)
#define versa(a) ((~a+1)&2047)

history::history(QWidget *parent) :
QWidget(parent),
ui(new Ui::history)
{
	ui->setupUi(this);
	rect = QRect(0, 0, REC_WID, REC_HEI);
	height = rect.height();
	width = rect.width();
	stopFlag = false;
	VALY = 0.5;
	gridnum = 10;
	initPoint.setX(INITIAL_X);
	initPoint.setY(INTTIAL_Y);
	VAL = 1;	//每N个像素显示一个点，即坐标scale
	N = 1;
	connect(ui->retbt, SIGNAL(clicked()), this, SLOT(showret()));
	connect(ui->snapbt, SIGNAL(clicked()), this, SLOT(grabwindow()));
	connect(ui->stopbt, SIGNAL(clicked()), this, SLOT(stopshow()));

	ldtimer = new QTimer(this);
	connect(ldtimer, SIGNAL(timeout()), this, SLOT(timerShowHis()));
}

history::~history()
{
	delete painter;
}

void history::stopshow()
{
	if (!stopFlag)
	{
		stopFlag = true;
		ui->stopbt->setText(tr("&continue"));
	}
	else
	{
		stopFlag = false;
		ui->stopbt->setText(tr("&stopshow"));
	}
	qDebug() << "--------------sendstop--------------";
}

void history::paintEvent(QPaintEvent *qev)
{
	//设置画板画矩形
	painter = new QPainter(this);
	painter->setBrush(Qt::black);
	painter->translate(INITIAL_X, INTTIAL_Y);
	painter->drawRect(rect);
	painter->begin(this);	//设置画板为当前的widget上
	setXYcord();
	painter->end();
}

void history::setXYcord()
{
	//x
	painter->setPen(QPen(Qt::blue));
	for (int i = 0; i < rect.width() / 10; i++)
	{
		point[0].setX(i * 10);
		point[0].setY(height);
		point[1].setX(i * 10);
		point[1].setY(height - 1);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	painter->drawLine(QPoint(0, height), QPoint(width, height));
	//y
	painter->setPen(QPen(Qt::red));
	for (int i = height / 10; i > 0; i--)
	{
		point[0].setX(0);
		point[0].setY(i * 10);
		point[1].setX(1);
		point[1].setY(i * 10);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	painter->drawLine(QPoint(0, 0), QPoint(0, height));

	//x值
	int j = 1;
	QFont font("Arial", 6, QFont::Normal, true);
	painter->setPen(QPen(Qt::black));
	painter->setFont(font);
	for (int i = 10; i<width; i += 10)
	{
		painter->drawText(rect.x() + i - 2, height + 10, QString::number(j, 10));
		j++;
	}

	//y值
	j = height / 10;
	painter->setFont(font);
	for (int i = 0; i <= height; i += 10)
	{
		painter->drawText(rect.x() - 13, height - i + 3, QString::number((height) / 10 - 33 - j, 10));
		j--;
	}
}

/*************处理从handler线程中传来的sendData事件****************/
void history::testdata()
{
	qDebug() << "**********************************************";
	qDebug() << "------------------testdata------------------- ";
	drawPoints();
}

void history::drawPoints()
{
	setUpdatesEnabled(true);
	repaint();
}

void history::showret()
{
	emit ret();
	this->hide();
}


void history::judgeColor(quint16 fid, QBrush& brush)
{
	if (brush == Qt::yellow && fid > 272){
		brush = Qt::blue;
		return;
	}
	if (brush == Qt::blue && fid > 544){
		brush = Qt::red;
		return;
	}
	if (brush == Qt::red && fid > 816){
		brush = Qt::green;
		return;
	}
	if (brush == Qt::green && fid < 272){
		brush = Qt::yellow;
		return;
	}
}

void history::changeEvent(QEvent *e)
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

void history::closeEvent(QCloseEvent *e)
{
	this->close();
}

void history::grabwindow()
{
	commonFunc::grabwindow(this, "history");
	QMessageBox::information(this, tr("&screenshot"), QStringLiteral("截图成功！"));
}

void history::saveShowData()
{}

//loadfile之前需要暂停显示，否则que_points会一直更新成实时的
void history::loadfile()
{
	int j;
	QDir dir;
	dir.setCurrent(QCoreApplication::applicationDirPath());
	dir.cd("dataSave");
	QString path = "./";
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Select Files(*.txt)"),
		path,
		tr("txt files(*.txt)"));
	if (fileName.isNull())
	{
		QMessageBox::warning(this, tr("File Name Error!"), tr("File name cann't be null!"), QMessageBox::Ok);
	}
	else
	{
		std::ifstream fin(fileName.toLatin1().constData());
		std::string line, num;
		while (getline(fin, line, ' ')){
			std::istringstream copy(line);
			while (copy >> num){
				que_points.push_back(std::stoi(num, 0, 10));
			}
		}
		fin.close();
		drawPoints();
		ldtimer->start();
	}
}

void history::timerShowHis()
{
	int step = 50;
	if (que_points.size() >= WIDTH){
		qDebug() << "show history :quepoints size: " << que_points.size();
		auto begin = que_points.begin();
		begin = que_points.erase(begin, begin + step);
		drawPoints();
	}
	else{
		ldtimer->stop();
		qDebug() << "show history wave over!";
	}
}