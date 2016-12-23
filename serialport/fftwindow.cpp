#include "fftwindow.h"
#include "ui_fftwindow.h"
#include "qdebug.h"
#define WIDTH 930
#define HEIGHT 500

fftwindow::fftwindow(QWidget *parent):
QMainWindow(parent),
ui(new Ui::fftwindowUi)
{
	ui->setupUi(this);
	rect = QRect(0, 0, WIDTH, HEIGHT);
	height = rect.height();
	width = rect.width();
	begin_point.setX(20);
	begin_point.setY(20);

}

fftwindow::~fftwindow()
{
	delete ui;
	
}

void fftwindow::paintEvent(QPaintEvent *evp)
{
	//设置画板画矩形
	painter = new QPainter(this);
	painter->setBrush(Qt::black);
	painter->translate(begin_point);
	painter->drawRect(rect);
	painter->fillRect(rect, QBrush(QColor(Qt::black), Qt::SolidPattern));
	painter->begin(this);
	showGrid();
	setXYcord();
	drawFFT();
	qDebug() << "FFT drawing...";
	queFFT.clear();
}

void fftwindow::setXYcord()
{
	//x
	painter->setPen(QPen(Qt::blue));
	for (int i = 0; i < width/ 10; i++)
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
		painter->drawText(rect.x() - 13, height - i + 3, QString::number((height) / 10 - 25 - j, 10));
		j--;
	}
}

void fftwindow::showGrid()
{
	//x
	QPen pen(Qt::darkGreen);
	painter->setPen(pen);
	point[0].setY(0);
	point[1].setY(height);

	for (int i = 0; i<rect.width() / 10; i++)
	{
		point[0].setX(i*10);
		point[1].setX(i*10);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	//y
	point[0].setX(0);
	point[1].setX(width);
	for (int i = height / 10; i >= 0; i--)
	{
		point[0].setY(i*10);
		point[1].setY(i*10);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
}

void fftwindow::fftGet(deque<float> que)
{
	qDebug() << "FFT res get.";
	for (const float a : que){
		this->queFFT.push_back(int(a));
	}
	setUpdatesEnabled(true);
	repaint();
}

void fftwindow::drawFFT()
{

	int start = 0;
	painter->setPen(QPen(QPen(Qt::white, 1, Qt::SolidLine)));
	for (int j = 0; j < queFFT.size(); ++j)
	{
		painter->drawPoint(QPoint(start, (height / 2 - queFFT.at(j))));
		qDebug() << "---------queFFT[" << j << "]------------" << queFFT.at(j);
		painter->drawLine(QPoint(start, (height / 2 - queFFT.at(j))), QPoint(start, height/2));
		start += 1;		
	}
}