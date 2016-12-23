#ifndef SCALEWIN_H
#define SCALEWIN_H
#include  "qwidget.h"
#include <deque>
#include <vector>
#include "qevent.h"
#include "qpainter.h"
#include "ui_scaleWin.h"
#include "commonFunc.h"
using std::deque;
using std::vector;
namespace Ui{
	class scaleWin;
}
class scaleWin : public QWidget
{
	Q_OBJECT
public:
	explicit scaleWin(QWidget *parent = 0);
	~scaleWin();
private:
	void setXYcord();
public:
	void paintEvent(QPaintEvent *evp) override;
	void showGrid();	//显示网格
	QString ByteArrayToHexstring(QByteArray str);
protected:
	void changeEvent(QEvent	*e) override;
	void closeEvent(QCloseEvent *e) override;

signals:
	void ret();

private:
	QPainter *painter;
	QRect rect;
	deque<int> que_points;
	QPoint point[2];
	QPoint initPoint;

	//坐标信息
	int column;
	int height;
	int width;
	unsigned gridnum;	//坐标精度
	int *pointtmp;

	//画笔信息
	int m_pen_width;
	int m_result_pen_width;

	//参数信息
	int N;
	float VALY;
	int *num;
	bool stopFlag;
	Ui::scaleWin *ui;

	public slots:
	//传递数据给放大屏幕的控件
	void showScaleData(deque<int>);

	private slots:
	void grabwindow();
	void stopshow();
	void showret();
public:
	void judgeColor(quint16 fid, QBrush& brush);
};
#endif