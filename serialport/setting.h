#ifndef SETTING_H
#define SETTING_H
#include "ui_setting.h"
#include "qwidget.h"
#include "qmap.h"

namespace Ui{
	class setting;
}

class setting :public QWidget
{
	Q_OBJECT
public:
	explicit setting(QWidget *parent = 0);
	~setting();

signals:
	void transpal(QMap<QString,QString> &);
private:
	Ui::setting *ui;
	QMap<QString, QString> palinfo,pal_send;
	private slots:
	void loadSetting();
	void ensure();
};


#endif