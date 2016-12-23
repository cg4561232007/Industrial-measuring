#include "clickLabel.h"
#include "qdebug.h"
clickLabel::clickLabel(QPixmap pixmap,QString name, QWidget *parent) :
QLabel(parent),m_name(name),m_pixmap(pixmap)
{
	setFixedWidth(18);
	setFixedHeight(18);
	setObjectName(name);
	setPixmap(pixmap.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}

clickLabel::~clickLabel(){}

void clickLabel::mouseReleaseEvent(QMouseEvent *e){
	int dex = getName().right(1).toInt();
	emit(clicked(dex));
}

QString clickLabel::getName() const
{
	qDebug() << "objectName: " << qPrintable(objectName());
	return this->objectName();
}