#ifndef AUTOSEND_H
#define AUTOSEND_H

#include "qwidget.h"
#include "qtimer.h"
#include "comm.h"
#include "ui_autosend.h"

namespace Ui{
	class autosend_ui;
}

class autosend : public QWidget
{
	Q_OBJECT
public:
	explicit autosend(QWidget *parent = 0);
	autosend(Comm *m_comm = 0, QWidget *parent = 0);
	~autosend();
	
	void closeEvent(QCloseEvent *mevent);
	void timerEvent(QTimerEvent *mevent);
	int  gettimeid() const;
	void resetUi();
protected:
	void changeEvent(QEvent *qc);

private:
	int timeid;
	int interval;
	Comm *m_comm;
	Ui::autosend_ui *ui;
	bool busy;
	int autosendbytes;	//�Զ����͵������ֽ������͸���UI����.

	signals:
	void correspondUi(int);

	private slots:
	void intervalset(int);
	void autosendset();

};
#endif