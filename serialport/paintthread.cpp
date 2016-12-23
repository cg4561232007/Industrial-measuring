#include "paintthread.h"
#include "qdebug.h"
#include <vector>
#include <string>
#include <list>

using std::string;
using std::vector;
using std::list;

#define SLEEP_TIME 100
#define WIDTH 1200
#define HEIGHT 700
#define INITIAL_X 40
#define INTTIAL_Y 40
#define D1 80
#define D2 60
#define D3 50
#define D4 40
#define PI 3.14159265358979323846

extern const int DATA_ARRAY_SIZE;

paintthread::paintthread(QObject *parent) :
QThread(parent)
{
	stoped = false;
	lockstate = false;
	rect = QRect(0, 0, WIDTH, HEIGHT);
	height = rect.height();
	width = rect.width();
	m_pen_width = 2;
	m_result_pen_width = 2;

	//参数设置
	gridnum = 10;
	N = 1;
	VALY = 0.5;
	VAL = 1;
	column = DATA_ARRAY_SIZE;

	//数据点信息
	num = new int[DATA_ARRAY_SIZE];	
	pixmap = new QPixmap(WIDTH, HEIGHT);
	painter = new QPainter(pixmap);

	sum1 = new int[column / N];
	sum2 = new int[column / N];
	sum3 = new int[column / N];
	sum4 = new int[column / N];

	//初始化状态
	p_switch_state = NORMAL_WAVE;
	p_flagGrid = true;
	p_clearFlag = false;
	p_stopFlag = false;
	p_sinFlag = false;
	ableDraw = false;

}

paintthread::~paintthread()
{
	delete pixmap;
	delete []num;
}

void paintthread::run()
{
	forever{
	QMutexLocker locker(&mutex);
	pause.lock();
	if (stoped){
		stoped = false;
		pause.unlock();
		break;
	}

		//算法:画出逐渐向左移动的正弦波
		//将数据点放在一个maxsize为WIDTH的deque<int>中
		int dsize = que_points.size();
		if (ableDraw){
			if (dsize <= WIDTH){
				que_points.insert(que_points.end(), &num[0], &num[DATA_ARRAY_SIZE]);
			}
			else
			{
				int overpnum = dsize - WIDTH;
				qDebug() << "overnum :" << QString::number(overpnum);
				auto quebegin = que_points.begin();
				quebegin = que_points.erase(quebegin, quebegin + overpnum);
				qDebug() << "after erase que_points size :" << QString::number(que_points.size());

				if (que_points.size() != WIDTH)
				{
					qDebug() << "wrong size after erase!";
					return;
				}
			}
		}

		//在pixmap上画图
		pixmap->fill(Qt::black);
		painter->begin(pixmap);	//设置画板为pixmap上

		if (p_flagGrid){
			showGrid();
		}

		painter->setPen(QPen(Qt::yellow));
		painter->drawLine(QPoint(0, 500), QPoint(width, 500));


		//reset波形
		if (p_clearFlag)
		{
			painter->end();
			p_clearFlag = false;
			p_sinFlag = 0;
			qDebug() << "------------------------clearflag triggeres!-----------------------------";
		}

		if (p_sinFlag){
			painter->setPen(QPen(QPen(Qt::white, m_pen_width, Qt::SolidLine)));
			showSin();
		}

		switch (p_switch_state){
		case NORMAL_WAVE:
			painter->setPen(QPen(QPen(Qt::white, m_pen_width + 1, Qt::SolidLine)));
			showReal();
			break;

		case  SLIDE_AVG:
			painter->setPen(QPen(Qt::red, m_result_pen_width, Qt::SolidLine));
			slideavg();
			break;

		case MID_AVG:
			painter->setPen(QPen(Qt::green, m_result_pen_width, Qt::SolidLine));
			midavg();
			break;

		case ADD_WEIGHT_AVG:
			painter->setPen(QPen(Qt::yellow, m_result_pen_width, Qt::SolidLine));
			addWeightavg();
			break;

		case MATH_AVG:
			painter->setPen(QPen(Qt::blue, m_result_pen_width, Qt::SolidLine));
			mathavg();
			break;

		case MFITER:
			break;

		case SIN_WAVE:
			break;

		case BAN:
			break;

		default:
			break;
		}
		painter->end();

		emit pixmapReady(pixmap);

		qDebug() << "-------------- paintthrad is running -------------" << currentThread();
		qDebug() << "painter is drawing in paintthread! " << currentThread();
		msleep(SLEEP_TIME);
		pause.unlock();
	}
}

void paintthread::setXYcord()
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

void  paintthread::showGrid()
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

void paintthread::getstop(bool flag)
{
	p_stopFlag = flag;
	qDebug() << "paintthread: ---------------getstop---------------"<<flag;
}

void paintthread::getsin(bool flag)
{
	p_sinFlag = flag;
	qDebug() << "paintthread: ---------------getsin---------------" << flag;
}

void paintthread::getstate(SWITCH_STATE flag)
{
	p_switch_state = flag;
	qDebug() << "paintthread: ---------------getstate---------------" << flag;
}

void paintthread::getclear(bool flag)
{
	p_clearFlag = flag;
	qDebug() << "paintthread: ---------------getclear---------------" << flag;
}

void paintthread::getgrid(bool flag)
{
	p_flagGrid = flag;
	qDebug() << "paintthread: ---------------getgrid---------------" << flag;
}

void paintthread::showSin()
{
	float tmp;

	//画板的原点在左上角，正y是宽，正x是长，将原点移到刻度上的y=0处.
	const int delta_y = 500;	//刻度为50，一格刻度十个像素.
	painter->drawLine(QPoint(0, delta_y), QPoint(rect.width(), delta_y));
	for (int t = 0; t< width; t++)
	{
		tmp = 2 * delta_y - (int(sin(t*PI / 100) * 160) + delta_y);	//得到关于新x轴：18刻度对应的真实波形.
		painter->drawPoint(QPoint(t, tmp));
	}
}

void paintthread::showReal()
{
	int startt = 0;
	for (int j = 0; j < que_points.size(); ++j)
	{
		//num[j] = int(2 * 500 - (int(sin(j*PI / 100 ) * 160) + 500));	//得到关于新x轴：18刻度对应的真实波形.
		painter->drawPoint(QPoint(startt, (height - que_points.at(j) / VALY)));
		qDebug() << "showReal:---------que_points--------- :"<<que_points.at(j);
		qDebug() << "normal wave drawing in showReal";
		startt += 2;
		if (startt>WIDTH || que_points.at(j) >= 65535){
			qDebug() << "normal wave drawing break:" << QString("que_points is %1").arg(que_points.at(j));
			break;
		}
	}
}

void paintthread::slideavg()
{
	qDebug() << "------slideavg------- :" << "slideavg has been triggered.";
	memset(sum2, 0, sizeof(int)*(column - N));

	int i, j, k;

	for (i = 0; i<column - N; i++)
	{
		for (j = 0; j<N; j++)
		{
			sum2[i] += num[j + i];
		}
		sum2[i] /= N;

		if (i>WIDTH || num[i] >= 65535)
			break;
	}

	i = 0;
	for (k = 0; k< column - N - 1; k++)
	{
		//painter->drawPoint(QPoint(i,(RECT_HEIGHT-sum2[k]/VALY-D2)));
		painter->drawLine(QPoint(i, (height - sum2[k] / VALY - D2)), QPoint(i + VAL, (height - sum2[k + 1] / VALY - D2)));
		i += VAL;
		if (i > WIDTH || num[i] >= 65535)
			break;
	}
}

void paintthread::mathavg()
{
	qDebug() << "------mathavg------- :" << "mathavg has been triggered.";
	memset(sum1, 0, sizeof(int)*column / N);

	int i, j, k, temp, x;
	temp = column / N;
	k = 0;
	x = 0;

	for (i = 0; i<temp; i++)
	{
		for (j = 0; j<N; j++, k++)
		{
			sum1[i] += num[k];
		}
		sum1[i] /= N;
	}

	i = 0;
	for (int n = 0; n<temp - 1; n++)
	{
		int start = 0;
		height = 100;
		for (int j = 0; j<column - 1; j++)
		{
			//painter->drawLine(QPoint(start,rect.height()-(sum1[j]+height)),QPoint(start+VAL,rect.height()-(sum1[j+1]+height)));
			painter->drawPoint(QPoint(start, num[j]));
			start += VAL;

			if (start>WIDTH)
				break;
		}
	}
}

void paintthread::addWeightavg()
{
	qDebug() << "------addWeigetavg------- :" << "addWeigetavg has been triggered.";
	int i, j, k;
	k = 0;
	int weights = 0;

	memset(sum4, 0, sizeof(int)*column / N);

	for (i = 1; i <= N; i++)
	{
		weights += i;
	}

	for (i = 0; i<column / N; i++)
	{
		if (i>WIDTH || num[k + N] >= 65535)
			break;
		for (j = 0; j<N; j++)
		{
			sum4[i] += num[k] * (j + 1);
			k++;
		}
		sum4[i] /= weights;
	}

	j = 0;
	for (k = 0; k<i - 1; k++)
	{
		painter->drawLine(QPoint(j, (height - sum4[k] / VALY - D4)), QPoint(j + VAL, (height - sum4[k + 1] / VALY) - D4));
		j += VAL;
	}
}

void paintthread::midavg()
{
	qDebug() << "------midavg------- :" << "midavg has been triggered.";
	if (N < 3)
		return;

	int i, j, k;
	int min, max;
	k = 0;
	min = 0;
	max = 0;

	memset(sum3, 0, sizeof(int)*column / N);

	for (i = 0; i<column / N; i++)
	{
		if (i>WIDTH || num[k + N] >= 65500)
			break;

		for (j = 0; j<N; j++)
		{
			if (min>num[k])
			{
				min = num[k];
			}
			else if (max<num[k])
			{
				max = num[k];
			}

			k++;
			sum3[i] += num[k];
		}

		sum3[i] -= min + max;
		sum3[i] /= N - 2;
	}
	j = 0;
	for (k = 0; k<i - 1; k++)
	{
		painter->drawLine(QPoint(j, (height - sum3[k] / VALY - D3)), QPoint(j + VAL, (height - sum3[k + 1] / VALY - D3)));
		j += VAL;
	}
}

void paintthread::getnum(int *number)
{
	QMutexLocker locker(&mutex);
	if (number[0]>1200 || number[0] < -200)
		return;
	this->num = number;
	ableDraw = true;
}

void paintthread::threadpause()
{
	this->pause.lock();
	this->lockstate = true;
	qDebug()<< currentThread() << QString("-----pause----- state :%1").arg(lockstate);
}

void paintthread::threadresume()
{
	this->pause.unlock();
	this->lockstate = false;
	qDebug() << currentThread() << QString("---resume--- state :%l").arg(lockstate);
}

void paintthread::stop()
{
	stoped = true;
}