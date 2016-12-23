#ifndef SETUPWINDOW_H
#define SETUPWINDOW_H
#include "qmainwindow.h"
#include "ui_setupWindow.h"
#include "mainMenu.h"
namespace Ui{
	class setupWindow;
}
class setupWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit setupWindow(QWidget *parent=0);
	~setupWindow();

private:
	Ui::setupWindow *ui;
	mainMenu mu;
	private slots:
	void showMainWindow();
	void appear();
};

#endif