#ifndef EFFLINE_H
#define EFFLINE_H
#include "qwidget.h"
#include "ui_effLine.h"
#include "ui_showwave.h"
#include "qpainter.h"
#include "qprogressdialog.h"
using namespace std;
namespace Ui{
	class effLine;
}

class effLine : public QWidget
{
	Q_OBJECT
public:
	explicit effLine(QWidget *parent = 0);
	~effLine();

private:
	Ui::effLine *ui;

public:
	void paintEvent(QPaintEvent *evp) override;

protected:
	void changeEvent(QEvent	*e) override;
	void closeEvent(QCloseEvent *e) override;

private:
	QPainter *painter;
	vector<int> vec_points;
	QPoint point[2];
	QPoint initPoint;

	//坐标信息
	QRect rect;
	int height;
	int width;
	//画笔信息
	int m_pen_width;
	int m_result_pen_width;
	int VAL;

	public slots:
	void drawPoints();	//将得到的数据处理成点

	private slots:
	void grabwindow();
	void showret();
signals:
	void ret();
};
#endif