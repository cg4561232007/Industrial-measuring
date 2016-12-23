#ifndef SERIAL_PORT_H
#define SERIAL_PORT_H

#include <QMainWindow>
#include "comm.h"       //对于自己写的默认在工程目录下的头文件使用“”而不是<>。
#include "qbytearray.h"
#include "qmenu.h"
#include "qaction.h"
#include "qtimer.h"
#include "autosend.h"
#include "showwave.h"
#include "mthread.h"
#include "connectTcp.h"

namespace Ui {
	class serial_port;
}

class Serial_port : public QMainWindow
{
	Q_OBJECT

public:
	explicit Serial_port(QWidget *parent = 0);
	~Serial_port();
	void initialUi();
	void showText(const QByteArray&);

	QString ByteArrayToHexstring(QByteArray);
	QByteArray HexstringToByteArray(QString);
	QString stringToHexString(QString str);

	void showoutOfRange();
	void recieveData();
	void closeEvent();

	public slots:
	void connectSocket();

private slots:
	void on_openbutton_clicked();
	void timeToRecieve();
	void sendData();
	void sendFile();
	void stopShowData();
	void clearWindow();
	void saveInfoAdd();
	void saveLocal();
	void clearFile();
	void clearsend();
	void showret();
	void getAsciiView();
	void autosendshow();
	void recieveUi(int);

	//显示波形
	void showwaveact();
	void transToWav();
signals:
	void ret();
private:
	Ui::serial_port *ui;
	Comm *m_comm;   //直接在这里加入serialport类型的private成员不行吗？
	QTimer *timer;
	QByteArray readData;
	bool stopShow;
	int sendBytes,recieveBytes;
	long long totalBytes;
	bool outOfRange;
	autosend *autosendw;
	QMenu *menuWave, *menuNetWork,*menuSounds;
	QAction *closeAction, *connectAction, *saveAct,
		*save_asAct, *show_waveAct, *FFT_Act;
	QAction *transToWav_Act;
	//波形
	showwave *sw;
	connectTcp *cp;
	//线程
	mthread *handle;

	public slots:
	void sendfixfre(QByteArray);
};

#endif // SERIAL_PORT_H
