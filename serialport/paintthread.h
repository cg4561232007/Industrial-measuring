#ifndef PAINTTHREAD_H
#define PAINTTHREAD_H

#include "qthread.h"
#include "qmutex.h"
#include "qpixmap.h"
#include "qpainter.h"
#include <deque>

using std::deque;

typedef enum{
	NORMAL_WAVE, SLIDE_AVG, MID_AVG, ADD_WEIGHT_AVG,
	MATH_AVG, MFITER, SIN_WAVE, BAN
} SWITCH_STATE;

class paintthread : public QThread
{
	Q_OBJECT
public:
	explicit paintthread(QObject *parent = 0);
	~paintthread();

	public slots:
	void stop();
	void threadpause();
	void threadresume();

	void setXYcord();
	void showGrid();
	void showSin();
	void showReal();
	void slideavg();
	void mathavg();
	void addWeightavg();
	void midavg();

protected:
	void run() override;

signals:
	void pixmapReady(QPixmap*);

private:
	volatile bool stoped;
	QMutex pause;
	QMutex mutex;

	QPainter *painter;
	QPixmap *pixmap;
	QRect rect;

	int gridnum;
	int height;
	int width;
	QPoint point[2];
	int *num;
	int *sum1, *sum2, *sum3, *sum4;
	int N;
	int VALY, VAL;
	int column;
	deque<int> que_points;

	//画笔信息
	int m_pen_width;
	int m_result_pen_width;

	SWITCH_STATE p_switch_state;	//状态
	bool p_flagGrid;
	bool p_clearFlag;
	bool p_stopFlag;
	bool p_sinFlag;
	bool ableDraw;

	public slots:
	//数据点传递
	void getnum(int *);
	void getstop(bool);
	void getsin(bool);
	void getstate(SWITCH_STATE);
	void getclear(bool);
	void getgrid(bool);

public:
	bool lockstate;
};

#endif