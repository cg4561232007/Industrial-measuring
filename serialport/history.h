#ifndef HISTORY_H
#define HISTORY_H
#include "ui_history.h"
#include "qwidget.h"
#include "qmainwindow.h"
#include "qpainter.h"
#include "clickLabel.h"
#include <deque>
using std::deque;
namespace Ui{
	class history;
}

class history : public QWidget
{
	Q_OBJECT
public:
	explicit history(QWidget *parent = 0);
	~history();

private:
	Ui::history *ui;

public:
	void paintEvent(QPaintEvent *evp) override;

private:
	void setXYcord();
public:
	void showGrid();
protected:
	void changeEvent(QEvent	*e) override;
	void closeEvent(QCloseEvent *e) override;

signals:
	void ret();

private:
	QPainter *painter;
	QPoint point[2];
	QPoint initPoint;

	//坐标信息
	QRect rect;
	int height;
	int width;
	unsigned gridnum;	//坐标精度
	//参数信息
	int N;
	float VALY;
	int VAL;
	int *num;
	QBrush default_brush = Qt::yellow;
	bool stopFlag;
	QTimer *ldtimer;
	deque<int> que_points;

	public slots:
	void drawPoints();	//将得到的数据处理成点
	void testdata();
	void judgeColor(quint16, QBrush&);
	void timerShowHis();
	void loadfile();

	private slots:
	void saveShowData();
	void grabwindow();
	void stopshow();
	void showret();
};

#endif