#include "mwidget.h"
#include "qdebug.h"

#define SLEEP_TIME 200
#define WIDTH 1200
#define HEIGHT 700
#define INITIAL_X 40
#define INTTIAL_Y 40

mwidget::mwidget(QWidget *parent):
QWidget(parent)
{
	rect = QRect(0, 0, WIDTH, HEIGHT);
	height = rect.height();
	width = rect.width();

	pixmap = new QPixmap(WIDTH, HEIGHT);
	pixmap->fill(Qt::black);
	this->show();
	gridnum = 10;
}

mwidget::~mwidget()
{

}

void mwidget::paintEvent(QPaintEvent *qev)
{
	//设置画板画矩形
	painter = new QPainter(pixmap);
	painter->setBrush(Qt::black);
	painter->begin(pixmap);	//设置画板为pixmap上
	setXYcord();
	showGrid();
	painter->end();
	emit pixmapReady();
}

void mwidget::setXYcord()
{
	//x
	painter->setPen(QPen(Qt::blue));
	for (int i = 0; i < rect.width() / 10; i++)
	{
		point[0].setX(i * 10);
		point[0].setY(height);
		point[1].setX(i * 10);
		point[1].setY(height - 3);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	painter->drawLine(QPoint(0, height), QPoint(width, height));
	//y
	painter->setPen(QPen(Qt::red));
	for (int i = height / 10; i > 0; i--)
	{
		point[0].setX(0);
		point[0].setY(i * 10);
		point[1].setX(3);
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
		painter->drawText(rect.x() + i - 3, height + 10, QString::number(j, 10));
		j++;
	}

	//y值
	j = height / 10;
	painter->setFont(font);
	for (int i = 0; i <= height; i += 10)
	{
		painter->drawText(rect.x() - 13, height - i + 3, QString::number((height) / 10 - j - 20, 10));
		j--;
	}
}
/*
void  mwidget::drawGrid()
{
	if (flagGrid){
		ui->showgrid->setText(tr("disaplay"));
		flagGrid = false;
	}
	else{
		ui->showgrid->setText(tr("hide"));
		flagGrid = true;
	}
	repaint();	//调用repaint()函数来触发paintEvent.
}
*/

void  mwidget::showGrid()
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

QPixmap& mwidget::getpixmap()
{
	return *pixmap;
}

void mwidget::testwidget()
{
	qDebug() << "widget is excuting in :" << QThread::currentThread();
	setUpdatesEnabled(true);
	this->repaint();
}
