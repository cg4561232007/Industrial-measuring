#ifndef MWIDGET_H
#define MWIDGET_H	

#include "qwidget.h"
#include "qobject.h"
#include "qthread.h"
#include "qpainter.h"

class mwidget : public QWidget
{
	Q_OBJECT
public:
	explicit mwidget(QWidget *parent = 0);
	~mwidget();

	public slots:
	void setXYcord();
	void showGrid();
	void paintEvent(QPaintEvent *qev) override;
	void testwidget();

signals:
	void pixmapReady();

private:
	QPainter *painter;
	QPixmap *pixmap;
	QRect rect;
	int height;
	int width;
	int gridnum;
	QPoint point[2];

public:
	QPixmap& getpixmap();
};

#endif