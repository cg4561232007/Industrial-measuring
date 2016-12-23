#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "qmainwindow.h"
#include "mthread.h"
#include "ui_mainMenu.h"
#include "serialport.h"
#include "qwidget.h"
#include "effLine.h"
#include "fixCheck.h"
#include "history.h"
#include "solvedata.h"
#include "setting.h"

namespace Ui{
	class mainMenu;
}
class mainMenu :public QWidget
{
	Q_OBJECT
public:
	explicit mainMenu(QWidget *parent= 0);
	~mainMenu();
	private slots:
	void showComm();
	void showHis();
	void showPlot();
	void showAutoCheck();
	void showFixCheck();
	void showret();
	void appear();
	void setWire();
	void showSet();
signals:
	void ret();
private:
	Ui::mainMenu *ui;
	mthread *handle;
	QWidget *m_childWidget, *m_childWidgetH, *m_childWidgetAuto, *m_childWidgetFix,
		*m_childWidgetPlot;
	QWidget *m_settings;
	solvedata *svdata;
	QMap<QString, QString> g_pal;

	private slots:
	void getStop();
	void getResume();
	void setpal(QMap<QString, QString>&);
};

#endif