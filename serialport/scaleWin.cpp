#include "scaleWin.h"
#include "qdir.h"
#include "qmessagebox.h"
#include "qdebug.h"
//显示区域设置
#define WIDTH 1200
#define HEIGHT 660
#define REC_WID 1050
#define REC_HEI 500
#define INITIAL_X 40
#define INTTIAL_Y 50
#define PI 3.14159265358979323846
#define min(a,b) (a>b?b:a)
#define versa(a) ((~a+1)&2047)

scaleWin::scaleWin(QWidget *parent) :
QWidget(parent),
ui(new Ui::scaleWin)
{
	qRegisterMetaType<deque<int>>("deque<int>");
	ui->setupUi(this);
	rect = QRect(0, 0, REC_WID, REC_HEI);
	height = rect.height();
	width = rect.width();
	pointtmp = new int[width];		//横坐标点的个数,动态分配内存
	stopFlag = false;
	gridnum = 10;
	initPoint.setX(INITIAL_X);
	initPoint.setY(INTTIAL_Y);
	N = 1;
	connect(ui->retbt, SIGNAL(clicked()), this, SLOT(showret()));
	connect(ui->snapbt, SIGNAL(clicked()), this, SLOT(grabwindow()));
	connect(ui->stopbt, SIGNAL(clicked()), this, SLOT(stopshow()));
}

scaleWin::~scaleWin()
{
	delete painter;
	delete pointtmp;
}

void scaleWin::stopshow()
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

void scaleWin::paintEvent(QPaintEvent *qev)
{
	//设置画板画矩形
	painter = new QPainter(this);
	painter->setBrush(Qt::black);
	painter->translate(INITIAL_X, INTTIAL_Y);
	painter->drawRect(rect);
	painter->begin(this);	//设置画板为当前的widget上
	setXYcord();
	showGrid();

	int qz = que_points.size();
	if (qz == 0){
		qDebug() << "scaleque empty.";
		return;
	}
	int startt = 0;
	for (int j = 0; j <  qz - 1; ++j)
	{
		painter->setPen(QPen(QPen(Qt::yellow, 2, Qt::SolidLine)));
		painter->drawPoint(QPoint(startt, (REC_HEI / 2 - que_points.at(j) / 0.5)));
		startt +=2;
	}
	painter->end();
}

void scaleWin::setXYcord()
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
		painter->drawText(rect.x() - 13, height - i + 3, QString::number((height) / 10 - 25 - j, 10));
		j--;
	}
}

void scaleWin::showGrid()
{
	//x
	QPen pen(Qt::darkGreen);
	painter->setPen(pen);
	point[0].setY(0);
	point[1].setY(height);

	for (int i = 0; i<rect.width() / gridnum; i++)
	{
		point[0].setX(i*gridnum);
		point[1].setX(i*gridnum);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	//y
	point[0].setX(0);
	point[1].setX(width);
	for (int i = height / gridnum; i >= 0; i--)
	{
		point[0].setY(i*gridnum);
		point[1].setY(i*gridnum);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
}

void scaleWin::showret()
{
	this->hide();
	emit ret();
}

void scaleWin::showScaleData(deque<int> scaleque)
{
	que_points = scaleque;
	setUpdatesEnabled(true);
	repaint();
}

void scaleWin::judgeColor(quint16 fid, QBrush& brush)
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

void scaleWin::changeEvent(QEvent *e)
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

void scaleWin::closeEvent(QCloseEvent *e)
{
	this->close();
}

void scaleWin::grabwindow()
{
	commonFunc::grabwindow(this, "scaleWin");
	QMessageBox::information(this, tr("&screenshot"), QStringLiteral("截图成功！"));
}