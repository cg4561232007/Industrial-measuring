#include "connectTcp.h"
#include "qmessagebox.h"
#include "qdir.h"
#include "qexception.h"
#include "qthread.h"
#include "qbuffer.h"
#include "qfiledialog.h"
#include "qimagereader.h"

#define server_state 1
#define client_state 0
#define global_port 6666
#define HeaderSize 24
using pkgtype = enum{MESSAGE_INFO,FILE__INFO,IMAGE_INFO,MP3_INFO};

connectTcp::connectTcp(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::connectTcp_class)
{
	ui->setupUi(this);
	QDir::setCurrent(QCoreApplication::applicationDirPath());
	ui->socketWd->addItem(new QListWidgetItem(QIcon("resources/user.jpg"), tr("Client"),0, QListWidgetItem::UserType));
	ui->socketWd->addItem(new QListWidgetItem(QIcon("resources/server.jpg"), tr("Server"), 0, QListWidgetItem::UserType));
	ui->socketWd->setIconSize(QSize(300,38));
	ui->socketWd->setCurrentRow(0);
	ui->stackedWidget->setCurrentIndex(0);

	ui->usrList->setAutoFillBackground(true);
	QPalette palette = ui->usrList->palette();
	palette.setColor(QPalette::Base, QColor(183, 211, 242));
	ui->usrList->setPalette(palette);
	palette.setColor(QPalette::Base, QColor(177,248,223));
	ui->textBrowser->setPalette(palette);
	ui->textEdit->setPalette(palette);
	ui->serverlabel->setText(tr("server is closed."));

	tcpserver = NULL;
	tcpsocket = NULL;
	server_open = false;
	pkgtype pkg = FILE__INFO;
	endMark = "#xjtu#";
	headMark = "#login#";
	normalMark = "#normal#";
	datasize = 0;
	state = IDLE;

	//sendfile
	bytesWriten = 0;
	bytesToWrite = 0;
	totalBytes = 0;
	bytesRecived = 0;
	perBytes = 8*1024;	//每次发送8k个字节
	filenamesize = 0;
	ui->sendfilebar->setVisible(false);

	connect(ui->socketWd, SIGNAL(currentRowChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
	connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(buildCloseServer()));
	connect(ui->linkButton, SIGNAL(clicked()), this, SLOT(buildClient()));
	connect(ui->cancelbt, SIGNAL(clicked()), this, SLOT(closeClient()));
	connect(ui->sendBt, SIGNAL(clicked()), this, SLOT(appendMessage()));
	connect(ui->sendImgBt, SIGNAL(clicked()), this, SLOT(sendImage()));
	connect(ui->sendFileBt, SIGNAL(clicked()), this, SLOT(sendFile()));
	connect(ui->sendMp3Bt, SIGNAL(clicked()), this, SLOT(sendMp3()));
}

connectTcp::~connectTcp()
{
	delete ui;
}

void connectTcp::aboutInfo()
{

}

void connectTcp::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void connectTcp::buildCloseServer()
{
	if (!server_open){
		buildServer();
		ui->pushButton_5->setText(tr("close"));
		server_open = true;
	}
	else{
		closeServer();
		ui->pushButton_5->setText(tr("open"));
		server_open = false;
	}
}

//server constructs
void connectTcp::buildServer()
{
	tcpserver = new QTcpServer();
	connect(tcpserver, SIGNAL(newConnection()), this, SLOT(getConnection()));
	connect(tcpserver, SIGNAL(acceptError(QAbstractSocket::SocketError)), this, SLOT(servererror(QAbstractSocket::SocketError)));

	if (!tcpserver->listen(QHostAddress::Any, 8889)){
		qDebug() << "<buildServer>    Tcp server listen failed!";
		close();
		return;
	}
	else
		ui->serverlabel->setText(tr("server is listening for user..."));
	userName = "server";
	ui->label_6->setText(tr("connecting"));
	ui->usrList->addItem(userName);
	server_client = server_state;
}

void connectTcp::servererror(QAbstractSocket::SocketError e)
{
	ui->label_6->setText(tr("server error"));
	qDebug() << "<serverError>		" << e;
}

void connectTcp::getConnection()
{	
	tcpsocket = new QTcpSocket();
	tcpsocket = tcpserver->nextPendingConnection();
	ui->progressBar->setMaximum(1);
	ui->progressBar->setValue(1);
	ui->pushButton_5->setEnabled(true);
	ui->pushButton_5->setText(tr("&Stop"));
	ui->label_6->setText(tr("&connected"));
	//有数据来时
	connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(newDataRecv()));
	//断开连接
	connect(tcpsocket, SIGNAL(disconnected()), this, SLOT(deleteName()));
}

void connectTcp::closeServer()
{
	ui->label_6->setText(tr("disconnected"));
	ui->progressBar->setValue(0);
	tcpserver->close();
	ui->serverlabel->setText(tr("server is closed."));
	ui->usrList->clear();
}

//client constructs
void connectTcp::buildClient()
{
	if (ui->IPline->text().isEmpty() || ui->Portline->text().isEmpty())
	{
		QMessageBox::about(this, tr("&Warning"), tr("IP address or port can't be empty."));
		return;
	}
	tcpsocket = new QTcpSocket();
	connect(tcpsocket, SIGNAL(hostFound()), this, SLOT(findHost()));
	connect(tcpsocket, SIGNAL(connected()), this, SLOT(sendUsrInfo()));
	connect(tcpsocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(error(QAbstractSocket::SocketError)));
	connect(tcpsocket, SIGNAL(readyRead()), this, SLOT(newDataRecv()));
	connect(tcpsocket, SIGNAL(disconnected()), this, SLOT(deleteName()));
	//connect(tcpsocket, SIGNAL(disconnected()), this, SLOT(deleteLater()));

	tcpsocket->abort();
	hostAddr = ui->IPline->text();
	port = ui->Portline->text().toInt();
	userName = ui->lineEdit->text();
	tcpsocket->connectToHost(hostAddr, port, QIODevice::ReadWrite);
	server_client = client_state;
}

void connectTcp::findHost()
{
	qDebug() << "find host ";
}

void connectTcp::closeClient()
{
	tcpsocket->disconnectFromHost();
	//tcpsocket->close();
	qDebug() << "<closeClient>   close client...";
	ui->stateLabel->setText(tr("disconnect"));
}

void connectTcp::error(QAbstractSocket::SocketError)
{
	QMessageBox::about(this, tr("&error"), tr("an error occurs in connection,\ndisconnected from host"));
	ui->stateLabel->setText(tr("error"));
}

void connectTcp::sendUsrInfo()
{
	ui->stateLabel->setText(tr("connected"));
	qDebug() << "<sendUsrInfo>    clinet connected";
	QListWidgetItem *item1 = new QListWidgetItem(userName);
	item1->setBackground(Qt::darkGreen);
	item1->setForeground(Qt::blue);
	ui->usrList->addItem(userName);
	QDataStream out(tcpsocket);
	out << headMark;
	out << userName;
}

void connectTcp::newDataRecv()
{
	QDataStream in;
	in.setDevice(tcpsocket);
	qDebug() << "<newDataRecv>	recvdata slots count: " << count++;
	QString loginName, content;
	QString mark, end;

	//不同的数据接收状态：普通消息、图片、MP3、文件
	switch (state)
	{
	case QFILE:
		recvFile(in);
		return;
	case IMAGE:
		recvImage(in);
		return;
	case MP3:
		recvMp3(in);
		return;
	default:
		break;
	}

	//解析包头获取登录信息，并依据数据接受的状态来接受数据
	in >> mark;
	if (mark == headMark){
		in >> loginName >> content;
		if (content.isEmpty()){
			if (server_client == server_state){
				ui->usrList->addItem(loginName);
				ui->serverlabel->setText(QString("server is connected to ") + loginName);
				qDebug() << "<server>  the login info is :"
					<< loginName;
				//add userinfo in client list
				QDataStream logout(tcpsocket);
				logout << mark;
				logout << userName << content;
			}
			else {
				qDebug() << "<client>  the login info is :"
					<< loginName;
				ui->usrList->addItem(loginName);
			}
		}
		return;
	}
	else if (mark == normalMark){
		int pkg;
		in>>pkg;
		switch (pkg)
		{
		case MESSAGE_INFO:
			recvMessage(in, loginName, content);
			state = MESSAGE;
			break;
		case FILE__INFO:
			state = QFILE;
			recvFile(in);
			break;
		case IMAGE_INFO:
			state = IMAGE;
			recvImage(in);
			break;
		case MP3_INFO:
			state = MP3;
			recvMp3(in);
			break;
		default:
			break;
		}
	}
}

void connectTcp::recvMessage(QDataStream &in,QString loginName,QString content)
{
	in >> loginName >> content;
	nowTime = QDateTime::currentDateTime();
	ui->textBrowser->append(
		QString("\n%1%2%3\n%4")
		.arg(loginName)
		.arg("    ")
		.arg(nowTime.toString("hh:mm:ss    yyyy-MM-dd"))
		.arg(content)
		);
}

void connectTcp::appendMessage()
{
	QString textInput = ui->textEdit->toPlainText();
	if (textInput.isEmpty()){
		QMessageBox::warning(this, tr("&warning"), tr("&Send message cannnot be none!"));
		return;
	}
	QDateTime sendTime = QDateTime::currentDateTime();
	ui->textBrowser->append(
		QString("\n%1%2%3\n%4")
		.arg(userName)
		.arg("    ")
		.arg(sendTime.toString("hh:mm:ss  yyyy-MM-dd"))
		.arg(textInput)
		);

	QDataStream out;
	out.setDevice(tcpsocket);
	out << normalMark;
	out << MESSAGE_INFO;
	out << userName << textInput;
	qDebug() << "<appendMessage>   send message successfully";
	ui->textEdit->clear();
}

void connectTcp::deleteName()
{
	qDebug() << "server socket closed";
	if (server_state==server_client)
		ui->usrList->takeItem(1);
	else{
		ui->usrList->clear();
	}
}

void connectTcp::sendImage()
{
	if (!tcpsocket){
		QMessageBox::information(this, tr("warning"), tr("Must build connection before sending"), QMessageBox::Ok);
		return;
	}
	QDir::setCurrent(QCoreApplication::applicationDirPath());
	QString filename;
	QImage *image = new QImage();
	filename = QFileDialog::getOpenFileName(this, tr("select pictures"), tr("select one existing pictures"),
		tr("Image files(*.png *.jpg *.gif *.bmp *.tif)"));
	if (filename.isEmpty())
		return;
	else if (!(image->load(filename))){
		QMessageBox::information(this, tr("error"), tr("open file failed!"), QMessageBox::Ok);
		delete image;
		return;
	}
	ui->labelImg->setPixmap(QPixmap::fromImage(
		image->scaled(ui->labelImg->width(),ui->labelImg->height(),Qt::KeepAspectRatio)));

	//存图片到buffer缓冲流中,从缓冲流中读取图片至QByteArray
	QByteArray validData;
	QBuffer buffer;
	QDataStream out(&validData, QIODevice::WriteOnly);
	image->save(&buffer, "jpg");
	ui->filelabel->setText(QString::number(buffer.size()));
	out.setVersion(QDataStream::Qt_5_5);
	//图片文件流格式为：mark+pkgtype+sizeof(pic)+picinfo
	out << normalMark;
	out << IMAGE_INFO;
	out << (quint32)buffer.data().size();	//先写入图片大小信息
	out << buffer.data();
	qDebug() << "<sendimage>	buffer data size:" << buffer.data().size();
	qDebug() << "<sendimage>	validdata size:" << validData.size();

	tcpsocket->write(validData);
	validData.resize(0);
	out.device()->seek(0);
	buffer.reset();
}

void connectTcp::recvImage(QDataStream &in)
{
	in.setVersion(QDataStream::Qt_5_5);
	//读入图片大小信息
	if (datasize == 0){
		if (tcpsocket->bytesAvailable() < sizeof(quint32))
			return;
		in >> datasize;
	}
	//待接收到完整的图片数据包
	if (tcpsocket->bytesAvailable() < datasize){
		qDebug() << "<recvimage>	datasize:"<<datasize;
		qDebug() << "<recvimage>	tcpsocket bytes available" << tcpsocket->bytesAvailable();
		return;
	}

	//存储图片要使用QDataStram!!!!!! 要使用QImage *image=new QImage(),动态分配
	QByteArray recdata = tcpsocket->read(datasize);
	QBuffer recbuffer(&recdata);
	recbuffer.open(QIODevice::ReadOnly);
	QDataStream imagein(&recbuffer);
	QImage *image = new QImage();
	imagein >> *image;
	ui->labelImg->setPixmap(QPixmap::fromImage(image->scaled(ui->labelImg->width(), ui->labelImg->height(), Qt::KeepAspectRatio)));
	ui->filelabel->setText(QString::number(datasize)+"	bytes");
	qDebug() << "<recvimage>	imagesize:" <<image->size();
	datasize = 0;
}

void connectTcp::sendBytes(qint64 bytesNumber)
{
	bytesWriten += bytesNumber;
	ui->sendfilebar->setVisible(true);
	ui->sendfilebar->setValue(bytesWriten);
	ui->sendfilebar->setMaximum(totalBytes);
	if (bytesWriten == 0){
		sendfile->close();
	}
	else{
		outblock = sendfile->read(qMin(bytesToWrite,perBytes));
		bytesToWrite -= tcpsocket->write(outblock);
		outblock.resize(0);
	}
	if (bytesWriten == totalBytes){
		bytesWriten = 0;
		bytesToWrite = 0;
		totalBytes = 0;
		sendfile->close();
		ui->fstatelabel->setText(tr("transfering completes"));
	}
}

void connectTcp::sendFile()
{
	if (!tcpsocket){
		QMessageBox::information(this, tr("warning"), tr("Must build connection before sending"), QMessageBox::Ok);
		return;
	}
	connect(tcpsocket, SIGNAL(bytesWritten(qint64)), this, SLOT(sendBytes(qint64)));
	QString filename = QFileDialog::getOpenFileName(this);
	if (!filename.isEmpty())
		ui->fstatelabel->setText(tr("selected one file,start to transfer"));
	else
		return;
	sendfile = new QFile(filename);
	if (!sendfile->open(QIODevice::ReadOnly)){
		qDebug() << "open file error!";
		return;
	}
	QDataStream out(&outblock, QIODevice::WriteOnly);
	out.setVersion(QDataStream::Qt_5_5);
	totalBytes = sendfile->size();
	QString currentName = filename.right(filename.size() - filename.lastIndexOf('/') - 1);

	//写入文件总大小信息，文件名大小信息，文件名
	out << normalMark << FILE__INFO;
	out << qint64(0) << qint64(0);
	qint32 headersize = outblock.size() - sizeof(qint64)* 2;
	out << currentName;
	qint64 fnamesize = outblock.size() - sizeof(qint64)* 2 - headersize;
	totalBytes += outblock.size();
	out.device()->seek(headersize);
	out << totalBytes << fnamesize;
	bytesToWrite = totalBytes - tcpsocket->write(outblock);
	ui->fstatelabel->setText(tr("start transfering fileInfo %1").arg(currentName));
	outblock.resize(0);
}

void connectTcp::recvFile(QDataStream&)
{
	QDataStream in(tcpsocket);
	QString filename;
	in.setVersion(QDataStream::Qt_5_5);
	//刚开始接受时解析包头
	if (bytesRecived <= sizeof(qint64)* 2){
		if (tcpsocket->bytesAvailable() >= sizeof(qint64)* 2 && filenamesize == 0){
			in >> totalBytes >> filenamesize;
			bytesRecived += sizeof(qint64)* 2;
			qDebug() << "<recvFile>	bytesrecieved:" << bytesRecived;
		}
		else
			return;
		if (filenamesize != 0 && tcpsocket->bytesAvailable() >= filenamesize){
			in >> filename;
			bytesRecived += filenamesize;
			qDebug() << "<recvFile>	bytesrecieved:" << bytesRecived;
			ui->fstatelabel->setText(tr("Totalbytes:%1 filenamesize:%2 filename:%3").arg(totalBytes).arg(filenamesize).arg(filename));
			//建立新的文件
			QDir dir;
			QFileInfo sub("./netfile");
			QString dirstr = "netfile";
			if (!sub.exists())
				dir.mkdir(dirstr);
			dir.cd(dirstr);
			recvfile = new QFile();
			recvfile->setFileName(dir.filePath("new"+filename));
			if (!recvfile->open(QIODevice::WriteOnly)){
				qDebug() << "create file error";
				return;
			}
			return;
		}
		else
			return;
	}
	//开始接收有用的文件信息
	if (bytesRecived < totalBytes){
		bytesRecived += tcpsocket->bytesAvailable();
		qDebug() << "<recvFile>	bytesrecieved:" << bytesRecived
				<<"bytesavailable: "<<tcpsocket->bytesAvailable();
		inblock = tcpsocket->readAll();
		recvfile->write(inblock);
		qDebug() << tr("bytesrecived:%1 bytes, totalbytes:%2 bytes").arg(bytesRecived).arg(totalBytes);
		inblock.resize(0);
	}
	ui->sendfilebar->setVisible(true);
	ui->sendfilebar->setValue(bytesRecived);
	ui->sendfilebar->setMaximum(totalBytes-HeaderSize);
	//接收完成
	if (bytesRecived == totalBytes-HeaderSize){
		filenamesize = 0;
		bytesRecived = 0;
		totalBytes = 0;
		recvfile->close();
		ui->fstatelabel->setText(tr("Recieve file successfully"));
	}
}

void connectTcp::sendMp3()
{

}

void connectTcp::recvMp3(QDataStream&)
{

}