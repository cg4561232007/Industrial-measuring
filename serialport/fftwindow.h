#ifndef FFTWINDOW_H
#define FFTWINDOW_H

#include "qmainwindow.h"
#include "qpainter.h"
#include "qwidget.h"
#include "qobject.h"
#include "qrect.h"
#include <deque>

using std::deque;
namespace Ui{
	class fftwindowUi;
}

class fftwindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit fftwindow(QWidget *parent=0);
	~fftwindow();
	void paintEvent(QPaintEvent *evp) override;

	public slots:
	void setXYcord();
	void showGrid();
	void fftGet(deque<float>);
	void drawFFT();

private:
	Ui::fftwindowUi *ui;
	QRect rect;
	QPainter *painter;
	int width, height;
	QPoint begin_point;
	QPoint point[2];
	deque<int> queFFT;
};
#endif