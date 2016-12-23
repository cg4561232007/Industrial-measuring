#ifndef CONNCETTCP_H
#define CONNECTTCP_H

#include "QtNetwork\qtcpsocket.h"
#include "QtNetwork\qtcpserver.h"
#include "qdatetime.h"
#include "QtNetwork\qhostaddress.h"
#include "qmainwindow.h"
#include "ui_connectTcp.h"
#include "qtimer.h"
#include "qfile.h"
using statetype = enum{ IDLE, MESSAGE, QFILE, IMAGE, MP3 };

namespace Ui{
	class connectTcp_class;
}

class connectTcp : public QMainWindow
{
	Q_OBJECT

public:
	explicit connectTcp(QWidget *parent=0);
	~connectTcp();

private:
	Ui::connectTcp_class *ui;

	//TCP protocol server and client
	QTcpSocket *tcpsocket;
	QTcpServer *tcpserver;
	QTimer *timer;
	//state info
	bool server_open;
	bool server_client;
	QString userName;
	QString hostAddr;
	int port;
	QDateTime nowTime;

	QString headMark, endMark, normalMark;
	int datasize;
	statetype state;
	int count = 0;

	//file
	QFile *sendfile;
	QByteArray outblock;
	qint64 bytesToWrite;
	qint64 totalBytes;
	qint64 bytesWriten;
	qint64 perBytes;
	QFile *recvfile;
	qint64 bytesRecived;
	qint64 filenamesize;

	QByteArray inblock;
protected:
	void changeEvent(QEvent *e) override;

	private slots:
	void buildServer();
	void closeServer();
	void buildCloseServer();
	void buildClient();
	void closeClient();

	void getConnection();
	void error(QAbstractSocket::SocketError);
	void findHost();
	void sendUsrInfo();
	void newDataRecv();
	void servererror(QAbstractSocket::SocketError);

	void aboutInfo();
	void appendMessage();
	void recvMessage(QDataStream&,QString,QString);
	void deleteName();
	void sendImage();
	void recvImage(QDataStream&);
	void sendFile();
	void recvFile(QDataStream&);
	void sendMp3();
	void recvMp3(QDataStream&);
	void sendBytes(qint64);
};

#endif