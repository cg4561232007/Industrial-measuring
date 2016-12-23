#ifndef CLICKLABEL_H
#define CLICKLABEL_H
#include "qlabel.h"
#include "qpixmap.h"

class clickLabel : public QLabel
{
	Q_OBJECT
public:
	explicit clickLabel(QPixmap pixmap,QString name, QWidget *parent = 0);
	~clickLabel();

private:
	QPixmap m_pixmap;
	QString m_name;
	QString getName() const;
signals:
	void clicked(int index);
protected:
	void mouseReleaseEvent(QMouseEvent*) override;
};

#endif