#include "serialport.h"
#include "ui_serialport.h"
#include <QDebug>
#include "qmessagebox.h"
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <cstring>
#include <stdlib.h>
#include "qfiledialog.h"
#include "qt_windows.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
using namespace Ui;     //因为组件的定义都在Ui空间中，故需要加入namespaceUi;

#define outRangeStr  "SendData contains values larger than 127..."
#define READ_DATA false
#define DISPLAY_DATA true
#define D_WORD unsigned long
using byte = unsigned char;

extern const int DATA_COUNT = 30;
QByteArray dataShare;
extern bool mutex = READ_DATA;
extern int precision = 8;
extern bool iswaveshow = false;
extern bool wire;

//默认是在本类的命名空间中.
Serial_port::Serial_port(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::serial_port)
{
	ui->setupUi(this);
	m_comm = new Comm;
	readData = "";
	stopShow = false;
	sendBytes = 0;
	recieveBytes = 0;
	totalBytes = 0;
	outOfRange = 0;
	initialUi();

	menuWave = new QMenu(trUtf8("&Wave"), this);
	menuNetWork = new QMenu(trUtf8("&NetWork"), this);
	menuSounds = new QMenu(trUtf8("&Sounds"), this);
	ui->menuBar->addMenu(menuWave);
	ui->menuBar->addMenu(menuNetWork);
	ui->menuBar->addMenu(menuSounds);

	closeAction = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&close"), this);
	connectAction = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&connect"), this);
	saveAct = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&save"), this);
	save_asAct = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&save as"), this);
	show_waveAct = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&showWave"), this);
	transToWav_Act = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&transToWav"), this);

	ui->menuQt->addAction(closeAction);
	ui->menuQt->addAction(saveAct);
	ui->menuQt->addAction(save_asAct);
	menuWave->addAction(show_waveAct);
	menuNetWork->addAction(connectAction);
	menuSounds->addAction(transToWav_Act);

	timer = new QTimer();

	connect(timer, SIGNAL(timeout()), this, SLOT(timeToRecieve()));		//定时器接收数据
	connect(ui->sendData, SIGNAL(clicked()), this, SLOT(sendData()));	//发送数据或者单字节
	connect(ui->sendFile, SIGNAL(clicked()), this, SLOT(sendFile()));
	connect(ui->stopShow, SIGNAL(clicked()), this, SLOT(stopShowData()));
	connect(ui->clearWindow, SIGNAL(clicked()), this, SLOT(clearWindow()));
	connect(ui->saveAdditon, SIGNAL(clicked()), this, SLOT(saveInfoAdd()));
	connect(ui->saveLocal, SIGNAL(clicked()), this, SLOT(saveLocal()));
	connect(ui->clearFile, SIGNAL(clicked()), this, SLOT(clearFile()));
	connect(ui->clearsend, SIGNAL(clicked()), this, SLOT(clearsend()));
	connect(ui->retbt, SIGNAL(clicked()), this, SLOT(showret()));

	//action
	connect(closeAction, SIGNAL(triggered()), this, SLOT(close()));
	connect(connectAction, SIGNAL(triggered()), this, SLOT(connectSocket()));
	connect(saveAct, SIGNAL(triggered()), this, SLOT(saveLocal()));
	connect(save_asAct, SIGNAL(triggered()), this, SLOT(saveInfoAdd()));
	connect(show_waveAct, SIGNAL(triggered()), this, SLOT(showwaveact()));
	connect(transToWav_Act, SIGNAL(triggered()), this, SLOT(transToWav()));

	//增加一个text来显示发送字符的ASC原字符
	connect(ui->showAscii, SIGNAL(clicked()), this, SLOT(getAsciiView()));
	connect(ui->editData, SIGNAL(textChanged()), this, SLOT(getAsciiView()));

	//自动发送窗口
	connect(ui->autosend, SIGNAL(clicked()), this, SLOT(autosendshow()));

	//get the reading message from serialport buffer
}

Serial_port::~Serial_port()
{
	delete ui;
	if (m_comm != NULL)
		delete m_comm;
}

void Serial_port::initialUi()
{
	QList<QSerialPortInfo> portInfo = QSerialPortInfo::availablePorts();
	QList<qint32> allowBaudRates = QSerialPortInfo::standardBaudRates();
	qDebug() << "QSerialportInfo: ------------allowBaudRates------------ :"
		<< allowBaudRates;

	QStringList list_name, list_baund, list_data, list_parity, list_stop;
	if (portInfo.count()>0){
		foreach(const QSerialPortInfo &info, portInfo) {
			list_name.append(info.portName());
		}
		std::sort(list_name.begin(), list_name.end());
		ui->cbPortName->addItems(list_name);   //add in combox
		ui->cbPortName->setCurrentText(list_name.at(0));
	}

	list_baund << "1200" << "2400" << "4800" << "9600" << "19200" << "38400" << "57600" << "119200";
	ui->cbBaudRate->addItems(list_baund);
	ui->cbBaudRate->setCurrentText(list_baund.at(3));

	list_data << "6" << "7" << "8";
	ui->cbdata->addItems(list_data);
	ui->cbdata->setCurrentText(list_data.at(2));

	list_parity << "no" << "odd" << "even";
	ui->cbPairty->addItems(list_parity);
	ui->cbPairty->setCurrentText(list_parity.at(0));

	list_stop << "1" << "2";
	ui->cbStop->addItems(list_stop);
	ui->cbStop->setCurrentText(list_stop.at(0));

	ui->ascdata->setVisible(false);

	ui->label_8->setText("0 bytes");
	ui->label_9->setText("0 bytes");

	ui->autosend->setEnabled(false);
}

void Serial_port::timeToRecieve()
{
	recieveData();
}
//qDebug() << "recieveData MUTEX: -------READ_DATA--------  WAITING FOR DISPLAY_DATA MUTEX";
void Serial_port::recieveData()
{
	//缓冲数组buffer的大小为 DATA_COUNT.
	char buffer[DATA_COUNT + 1] = "";
	if (DISPLAY_DATA == mutex)
	{
		//qDebug() << "recieveData MUTEX: -------DISPLAY_DATA--------  WAITING FOR READ_DATA MUTEX";
		return;
	}
	//读取Comm DATA_COUNT个字节到buffer字符数组里面
	int internal_bf = m_comm->bytesAvailable();
	if (internal_bf == 0){
		return;
	}
	qDebug() << "COMM:------------bytesAvaliable-------------- :" << QString::number(internal_bf);
	/*修改readall
	int count=m_comm->readData(buffer,DATA_COUNT);	//timeout为100ms
	buffer[DATA_COUNT] = '\0';*/
	//修改readdata
	readData = m_comm->readAll();
	qDebug() << "------------readdata-------------- :" << readData;
	dataShare = readData;
	recieveBytes += readData.size();
	totalBytes += readData.size();
	ui->label_8->setText(QString::number(totalBytes) + " bytes");
	showText(readData);
	readData.clear();
	if (recieveBytes > 1048576){
		saveLocal();
		recieveBytes = 0;
	}
	//打开了showwave之后改变mutex的状态来显示波形
	if (iswaveshow){
		qDebug() << "iswaveshow:"<<iswaveshow;
		mutex = DISPLAY_DATA;
	}
}

void Serial_port::showText(const QByteArray& message)
{
	//QByteArray就是以真实字符的形式传递的
	if (!stopShow){
		if (!message.isEmpty()){

			if (ui->hexLabel->isChecked())
				ui->textBrowser->append(ByteArrayToHexstring(message));
			else
				ui->textBrowser->append(message);
		}
	}
}

//ByteArray到Hex的转换,显示ByteArray的16进制ASCii码
//发送数据过来后，选择16进制显示的是控制字的16进制.
QString Serial_port::ByteArrayToHexstring(QByteArray str)
{

	QString HexStr;
	char *strdata = str.data();
	int strlength = str.size();
	for (int i = 0; i != strlength; ++i)
	{
		//qsnprintf(a, sizeof(inByte), "%0x", inByte);
		byte rebyte = byte(*(strdata + i));
		QString strtmp = QString::number(rebyte, 16);
		if (1 == strtmp.count()){
			strtmp.push_front("0");
		}

		HexStr.append(strtmp + " ");
	}
	return HexStr.toUpper();
	//每条消息默认最后加了换行符
}

//Hex到原型Ascii的转换
QByteArray Serial_port::HexstringToByteArray(QString str)
{
	//将字符串两两分割装到byte里面.
	str.remove(" ");
	int len = str.length();
	//用16进制表示的他的Ascii码一般是偶数的 
	if (len % 2)
		str = str.mid(0, len - 1) + "0" + str.right(1);
	QByteArray buffer;
	for (int i = 0; i < len; i += 2){
		//char a[4];
		QString tmp = str.mid(i, 2);
		//qsnprintf(a, sizeof(tmp), "%d", tmp);
		buffer.append(tmp.toInt(0, 16));
		qDebug() << "buffer is :" << buffer;
	}
	return buffer;
}

//在新加的一个text中显示Ascii的16进制
QString Serial_port::stringToHexString(QString str)
{
	str.remove(" ");
	int len = str.length();
	QByteArray buffer = "";
	QVector<int> value;
	for (int i = 0; i < len; i += 2){
		QString tmp = str.mid(i, 2);
		//ascii码为0-127，7位bit，若控制字是8位，可以超过这个范围
		value.push_back(tmp.toInt(0, 16));
		/*int value = tmp.toInt(0, 16);
		if (value>127 || value < 0)
		outOfRange = 1;
		buffer.append( tmp.toInt(0,16));*/
		buffer += value.at(i / 2);
	}
	for each (int var in value)
	{
		if (var > 127 || var < 0){
			outOfRange = 1;
			break;
		}
	}
	return buffer.toUpper();
}

void Serial_port::getAsciiView()
{
	QString hex, hexString = "";
	hex = stringToHexString(ui->editData->toPlainText());
	if (ui->showAscii->isChecked()){
		for (int i = 0; i != hex.length(); ++i)
			hexString += hex.at(i) + QString(" ");
		//是否选中了空格
		if (ui->enterSend->isChecked())
			hexString += "0D";

		//增加一个textbrowser来显示字符串的ASCii码
		ui->ascdata->setVisible(true);
		ui->ascdata->setText(hexString);
	}
	else{
		ui->ascdata->setVisible(false);
	}
	showoutOfRange();
	outOfRange = 0;
}

void Serial_port::showoutOfRange()
{
	QString outStr = ui->outRangeEdit->toPlainText();
	if (outOfRange && outStr == NULL){
		ui->outRangeEdit->insertPlainText(outRangeStr);
	}
	else if (!outOfRange && outStr != NULL){
		ui->outRangeEdit->clear();
	}
	else
		return;
}

void Serial_port::stopShowData()
{
	if (!stopShow){
		ui->stopShow->setText(tr("continue"));
		stopShow = true;
	}
	else{
		ui->stopShow->setText(tr("stop"));
		stopShow = false;
	}
}

//槽代表点击事件
void Serial_port::on_openbutton_clicked()
{

	if (m_comm->isopen()){
		m_comm->close();

		//加入关闭判断
		timer->stop();
		//handle->pause.lock();
		qDebug() << "串口成功关闭!";

		ui->cbPortName->setEnabled(true);
		ui->cbPairty->setEnabled(true);
		ui->cbStop->setEnabled(true);
		ui->cbBaudRate->setEnabled(true);
		ui->cbdata->setEnabled(true);
		ui->autosend->setEnabled(false);

		ui->sendData->setEnabled(false);
		ui->sendFile->setEnabled(false);
		ui->openbutton->setText("open");
		ui->lbstate->setText(ui->cbPortName->currentText() + " has been closed!");
		QMessageBox *mbox = new QMessageBox(QMessageBox::Information, "Information", "serialport has been closed!");
		mbox->show();
		return;
	}

	else{

		m_comm->setPortName(ui->cbPortName->currentText());
		m_comm->setBaudRate(ui->cbBaudRate->currentText().toInt());
		m_comm->setDataBits(ui->cbdata->currentText().toInt());
		qDebug() << "databits: " + ui->cbdata->currentText();
		m_comm->setParity(ui->cbPairty->currentText());
		m_comm->setStopBits(ui->cbStop->currentText().toInt());

		try{
			m_comm->open();
			if (m_comm->isopen())
				qDebug() << "qdebug: opening serialport...";
		}
		catch (QException e){
			qDebug() << "qdebug: serialport failed!";			//串口就没打开!!!
		}

		if (m_comm->isopen()){
			QMessageBox *mbox = new QMessageBox(QMessageBox::Information, tr("Information"), tr("serialport has been opened!"));
			mbox->show();
			ui->lbstate->setText(ui->cbPortName->currentText() + "," + ui->cbBaudRate->currentText() + ","
				+ ui->cbdata->currentText() + "," + ui->cbPairty->currentText() + "," + ui->cbStop->currentText());

			timer->start();
			//打开串口后才能够自动发送
			autosendw = new autosend(m_comm);

			//数据传递
			connect(autosendw, SIGNAL(correspondUi(int)), this, SLOT(recieveUi(int)));
			connect(closeAction, SIGNAL(triggered()), autosendw, SLOT(close()));
		}
		else{
			ui->lbstate->setText(tr("opening failed,device is being occupied..."));
			return;
		}

		ui->cbPortName->setEnabled(false);
		ui->cbPairty->setEnabled(false);
		ui->cbStop->setEnabled(false);
		ui->cbBaudRate->setEnabled(false);
		ui->cbdata->setEnabled(false);
		ui->sendData->setEnabled(true);
		ui->sendFile->setEnabled(true);
		ui->autosend->setEnabled(true);
		ui->openbutton->setText("close");
	}
}

void Serial_port::showret(){
	emit ret();
	this->hide();
}

void Serial_port::sendData()
{
	if (!m_comm->isopen()){
		QMessageBox::warning(this, tr("Warning"), tr("Must open Comm before sending."));
		return;
	}
	char *dataSend = "";
	char *chWrite = "";
	int n = 0;
	if (ui->editData->toPlainText() == "")
		QMessageBox::warning(this, tr("Warning"), tr("Can not write empty message to Com."));
	else{
		QString sendStr = ui->editData->toPlainText().remove(" ");
		qDebug() << "sendStr:" + QString(sendStr) + "  writing length:" + QString::number(sendStr.length());
		if (sendStr.length() == 1){
			chWrite = sendStr.toLatin1().data();
			n = m_comm->writeCh(chWrite);
			qDebug() << "writing message: " + QString(chWrite) << endl;
		}
		else{
			QByteArray ba = sendStr.toLatin1();
			dataSend = ba.data();	//利用tolatin1,datastr.toLatin1().data()一步完成不可以.
			qDebug() << "dataSend: " + QString(dataSend) << endl;
			//选中hex checkbox发送16进制数据
			if (ui->hexSend->isChecked()){
				QByteArray sbytes = HexstringToByteArray(sendStr);
				char *dataHex = sbytes.data();
				n = m_comm->writeData(dataHex, qstrlen(dataHex));
				sendBytes += n;
			}
			//否则按Ascii码发送
			else {
				n = m_comm->writeData(dataSend, qstrlen(dataSend));
				sendBytes += n;
			}
			qDebug() << "writing message: " + QString(dataSend) << endl;
		}
	}

	ui->label_9->setText(QString::number(sendBytes) + " bytes");
}

void Serial_port::sendfixfre(QByteArray fixfre)
{
	if (!m_comm->isopen()){
		QMessageBox::warning(this, tr("Warning"), tr("Must open Comm before sending."));
		return;
	}
	char *dataHex = fixfre.data();
	m_comm->writeData(dataHex, qstrlen(dataHex));
	qDebug() << "send fixfre";
}

void Serial_port::autosendshow()
{
	autosendw->setWindowTitle(tr("Auto send window"));
	autosendw->resetUi();
	autosendw->show();
}

void Serial_port::sendFile()
{
	if (!m_comm->isopen()){
		QMessageBox::warning(this, tr("Warning"), tr("Must open Comm before sending."));
		return;
	}
	QFileDialog *dialog = new QFileDialog(this);
	dialog->setWindowTitle(tr("Send File"));
	dialog->setDirectory(tr("."));
	dialog->setAcceptMode(QFileDialog::AcceptOpen);		//设置对话框保存文件
	dialog->setFileMode(QFileDialog::AnyFile);
	dialog->setNameFilter(tr("txt files(*.txt)"));

	QString str;
	if (dialog->exec() == QDialog::Accepted){
		QString filename = dialog->selectedFiles()[0];
		QFile sfile(filename);
		if (!sfile.open(QIODevice::ReadOnly | QIODevice::Text)){
			qDebug() << "opening files error!" << endl;
			return;
		}
		else{
			//输入流读取
			QTextStream readIn(&sfile);
			while (!readIn.atEnd())
				str.append("#XJTU#" + readIn.readLine() + "#END#");
		}
		sfile.close();
	}
	else
		QMessageBox::about(this, tr("warning"), tr("you must select one txtfile!"));

	//显示在textBrowser中
	ui->editData->insertPlainText(str);
	//writeComm
	int n = 0;
	if (ui->hexSend->isChecked()){
		char *fileHex = HexstringToByteArray(QString(str)).data();
		n = m_comm->writeData(fileHex, str.length());
	}
	else
		n = m_comm->writeData(str.toLatin1().data(), str.length());
	if (n == str.length())
		qDebug() << "writing successfully!" << endl;
	sendBytes += n;
	ui->label_9->setText(QString::number(sendBytes) + " bytes");
}

//清空显示
void Serial_port::clearWindow()
{
	ui->textBrowser->clear();
	ui->label_8->setText(tr("0") + "bytes");
}

//保存到本地
void Serial_port::saveLocal()
{
	QFile file;
	QDir dir;
	QStringList filters;
	filters << "*.txt" << "*.cpp";

	//保存到exe所在的文件夹中
	dir.setCurrent(QCoreApplication::applicationDirPath());
	dir.setNameFilters(filters);
	QFileInfo sub("./datasave");
	QString dirstr = "datasave";
	if (!sub.exists())
		dir.mkdir(dirstr);
	dir.cd(dirstr);

	QStringList currentFiles = dir.entryList(QDir::Files, QDir::Name);
	QStringList pointfile;
	for each(QString name in currentFiles){
		if (name.contains("dataRecieve"))
			pointfile.push_back(name);
	}

	//use lambda for stable sort.
	std::stable_sort(pointfile.begin(), pointfile.end(),
		[](const QString &s1, const QString &s2){return s1.size() < s2.size(); });

	int plen = pointfile.size();
	int nlen;
	QString lst;
	if (plen > 0){
		nlen = pointfile.at(plen - 1).size();
		lst = pointfile.at(plen - 1);
	}
	QString fileName;
	if (plen == 0)
		fileName = "dataRecieve.txt";
	else if (lst.at(11).isNumber() && lst.at(12).isNumber())
	{
		int lstnumber = QString(lst.mid(11, 2)).toInt();
		fileName = "dataRecieve" + QString::number(lstnumber + 1) + ".txt";
	}
	else if (lst.at(11).isNumber())
	{
		int lstnumber = QString(lst.at(11)).toInt();
		fileName = "dataRecieve" + QString::number(lstnumber + 1) + ".txt";
	}
	else {
		fileName = "dataRecieve1.txt";
	}
	file.setFileName(dir.filePath(fileName));
	qDebug() << "file's absolutly path is: " + file.fileName();


	if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){	//write,append,txt
		QTextStream stream(&file);
		stream << ui->textBrowser->toPlainText();
		stream.atEnd();
		file.close();
		QMessageBox::about(this, tr("Info"), tr("save successfully!"));
	}
	else
		qDebug() << "opening local file error!" << endl;

}

//保存readMessage到文件中去
void Serial_port::saveInfoAdd()
{
	//QString filename= QFileDialog::getOpenFileName(this, tr("Save files(*.txt)"), tr("./"), tr("txt files(*.txt)"));
	QFileDialog *filedialog = new QFileDialog(this);
	filedialog->setWindowTitle(tr("Save Options"));
	filedialog->setDirectory(tr("."));
	filedialog->setAcceptMode(QFileDialog::AcceptSave);		//设置对话框保存文件
	filedialog->setFileMode(QFileDialog::AnyFile);
	filedialog->setNameFilter(tr("txt files(*.txt)"));
	if (filedialog->exec() == QDialog::Accepted){
		QString filename = filedialog->selectedFiles()[0];	//返回类型为List的函数竟然直接在后面加下标使用!
		QFile file;
		file.setFileName(filename);
		if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
		{
			QTextStream saveFileStream(&file);
			saveFileStream << ui->textBrowser->toPlainText();
			saveFileStream.atEnd();
			file.close();
		}
		else{
			qDebug() << "opening files error!" << endl;
			return;
		}
	}
	else
		QMessageBox::warning(this, tr("waring"), tr("you must select one txtfile!"), QMessageBox::Ok);
}

//清空文件.
void Serial_port::clearFile()
{
	if (m_comm->isopen()){
		QMessageBox::warning(this, tr("Warning"), tr("Must close Comm before clearing."));
		return;
	}
	ui->label_8->setText("0 bytes");
	recieveBytes = 0;
	QDir dir;
	dir.setCurrent(QCoreApplication::applicationDirPath());
	QFile file(dir.filePath("dataRecieve.txt"));

	if (!file.exists())
		QMessageBox::information(this, tr("Info"), tr("wrong filename"), QMessageBox::Ok);
	file.resize(0);
	QMessageBox::information(this, tr("Info"), tr("clear successfully"), QMessageBox::Ok);
	file.close();
}

void Serial_port::clearsend()
{
	ui->editData->clear();
	ui->label_9->setText(tr("0"));
}

void Serial_port::recieveUi(int bytes)
{
	int localbytes = ui->label_9->text().toInt();
	localbytes += bytes;
	ui->label_9->setText(QString::number(localbytes) + " bytes");
}

void Serial_port::showwaveact()
{
	if (!iswaveshow){
		sw = new showwave();
		connect(closeAction, SIGNAL(triggered()), sw, SLOT(close()));

		if (handle == NULL)
			qDebug() << "after stop handle is NULL";
		sw->setWindowTitle(tr("Wave show window"));
		sw->show();
		iswaveshow = true;
		//connect(sw, SIGNAL(destroyed()), handle, SLOT(stop()));
	}
	else{
		QMessageBox::warning(this, tr("waring"), tr("Wave window is being shown!"), QMessageBox::Ok);
	}
}

void Serial_port::closeEvent()
{
	this->close();
	if (sw != NULL)
		sw->close();
}

void Serial_port::connectSocket()
{
	cp = new connectTcp();
	cp->setWindowTitle(tr("Connection window"));
	cp->show();
}

void Serial_port::transToWav()
{
	//建立wav文件的表头格式，三个struct
	typedef struct WAVE_HEADER W_HEADER;
	typedef struct WAVE_CHUCK W_CHUCK;
	typedef struct WAVE_FMT W_FMT;
	struct WAVE_CHUCK
	{
		char riff[4];	//RIFF	
		D_WORD bytesToEndl;
		char wave[4];	//WAVE
	};
	struct WAVE_FMT
	{
		char fmt[4];	//fmt +' '
		D_WORD pcmRt;
		wchar_t encodeSt;
		wchar_t chanels;
		D_WORD sampleRt;
		D_WORD transRt;
		wchar_t blockAlg;
		wchar_t pcmbits;
		char data[4];
		D_WORD dataBytes;
	};
	struct WAVE_HEADER
	{
		W_CHUCK wc;
		W_FMT wf;
	};
	W_CHUCK chuck{
		{ 'R', 'I', 'F', 'F' },
		0x01fe7824,
		{ 'W', 'A', 'V', 'E' }
	};
	W_FMT wavfmt{
		{ 'f', 'm', 't', ' ' },
		16, 1, 2,				//pcmrate,pcm,chanels
		44100, 176400, 4, 16,	//sample rate,bit rate
		{ 'd', 'a', 't', 'a' },
		0x01fe7800
	};
	W_HEADER wheader{ chuck, wavfmt };


	//建立输出流写入新的wav文件
	std::ofstream ofWav;
	const char *rWavPath = "C:\\Users\\heihei\\Desktop\\wav(0db)\\rWav.wav";
	ofWav.open(rWavPath, std::ofstream::binary | std::ofstream::out);
	if (!ofWav.is_open())
		std::cerr << "Opening file rWav failed. please check the path" << std::endl;
	ofWav.write((char *)&wheader, sizeof(char)* 44);


	//read data points into vector and writes them into ofstream
	vector<wchar_t> ValidData;
	QDir dir;
	dir.setCurrent(QCoreApplication::applicationDirPath());
	dir.cd("datasave");
	QString fileName = QFileDialog::getOpenFileName(this, tr("Select files(*.txt)"), "./",
		tr("text files(*.txt)"));
	/*
	if (fileName.isNull()){
	QMessageBox::warning(this, tr("Info"), tr("FileName can not be none."),QMessageBox::Ok);
	}
	else{
	std::ifstream ifSource(fileName.toLatin1().constData());
	string	line, missStr;
	bool missFlag = false;
	while (getline(ifSource, line)){
	if (line.empty())
	continue;
	if (missFlag)
	line = missStr+line;
	string::iterator iter = line.begin();
	while (iter != line.end()){
	if (*iter == ' ')
	iter = line.erase(iter);
	else
	iter++;
	}

	//解决了4分割字符串丢失的问题
	int length = line.length();
	if (length % 4 == 0)
	missFlag = false;
	else
	missFlag = true;
	for (int i = 0; i != length;i+=4){
	if (i + 3 > length - 1){
	missStr = line.substr(i);
	//qDebug() << "misss str occurs :" << QString::fromStdString(missStr);
	//qDebug() << missFlag;
	break;
	}
	else{
	wchar_t wch=(wchar_t)std::stoi(line.substr(i, 4),0,16);
	ValidData.push_back((wchar_t)std::stoi(line.substr(i, 4),0,16));
	ofWav.write((char*)&wch, sizeof(wch)/sizeof(char));
	}
	}
	}
	ifSource.close();
	ofWav.close();
	}*/


	std::ifstream ifSource("C:\\Users\\heihei\\Desktop\\ply.wav", ifstream::binary);
	if (ifSource.bad())
		return;
	ifSource.seekg(44, ios::beg);
	while (!ifSource.eof()){
		char a[512] = { 0 };
		ifSource.read((char*)a, sizeof(a) / sizeof(*a));
		if (ofWav.bad())
			return;
		ofWav.write((char*)a, sizeof(a) / sizeof(*a));
	}
	ifSource.close();
	ofWav.close();
}