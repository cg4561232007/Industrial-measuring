#include "serialport.h"
#include "mainMenu.h"
#include "setupWindow.h"
#include <QApplication>
#include "qpixmap.h"
#include "qsplashscreen.h"
#include "qthread.h"
#include "qdesktopwidget.h"
#include <QElapsedTimer> 

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QPixmap pixmap("resources/landscape1.jpg");
	QSplashScreen splash(pixmap);
	splash.resize(1024, 768);
	QDesktopWidget *deskwin = QApplication::desktop();
	QRect screenInfo = deskwin->screenGeometry();
	splash.move((screenInfo.width() - splash.width()) / 2, (screenInfo.height() - splash.height()) / 2);
	splash.showMessage("Welcom to Qt application.", Qt::AlignCenter, Qt::red);
	splash.show();
	//∂® ±¡Ω√Î
	QElapsedTimer elptimer;
	int delay = 1;
	elptimer.start();
	while (elptimer.elapsed() <= (delay*100))
		a.processEvents();

	/*mainMenu m;
	m.show();
	splash.finish(&m);*/
	setupWindow m;
	m.show();
	splash.finish(&m);
	return a.exec();
}
