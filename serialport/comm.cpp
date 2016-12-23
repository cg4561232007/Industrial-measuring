#include "comm.h"
#include <QMessageBox>
#include <QString>
#include <QDebug>
Comm::Comm(QObject *parent) : QObject(parent){
	m_serialPort = new QSerialPort;  //调用他的默认构造函数初始化Qserialport
	//m_baudRate=9600;
	// m_portName="";  //初始化名字为空
}

Comm::~Comm()
{   //调用析构函数之后隐含的调用各类成员的析构进行销毁，析构函数本身并不销毁；
	//内置类型不需要销毁，指针必须使用delete。
	delete m_serialPort;
}
static QSerialPort::BaudRate getBaudRate(int baudRate)
{
	switch (baudRate) {
	case 1200:
		return QSerialPort::Baud1200;
	case 2400:
		return QSerialPort::Baud2400;
	case 4800:
		return QSerialPort::Baud4800;
	case 9600:
		return QSerialPort::Baud9600;
	case 19200:
		return QSerialPort::Baud19200;
	case 38400:
		return QSerialPort::Baud38400;
	case 57600:
		return QSerialPort::Baud57600;
	case 115200:
		return QSerialPort::Baud115200;
	case 256000:
		return QSerialPort::Baud256000;
	//case 921600:
		//     return QSerialPort::Baud921600;
	default:
		return QSerialPort::UnknownBaud;
	}
}
void Comm::setBaudRate(int baudRate)
{
	m_baudRate = baudRate;
}

bool Comm::isopen() const   //实现的时候也要加上const才行。
{
	return m_serialPort->isOpen();
}
void Comm::setPortName(const QString &name)
{
	m_portName = name;
}

QString Comm::getPortName() const
{
	//m_serialPortinfo->availablePorts()
	return m_serialPort->portName();
}

//数据位
void Comm::setDataBits(int databits)
{	
	qDebug() << "setdatabits:(databits) " +QString::number(databits);
	switch (databits) {
	case 8:
		m_databits = QSerialPort::Data8;
		break;
	case 7:
		m_databits = QSerialPort::Data7;
		break;
	case 6:
		m_databits = QSerialPort::Data6;
		break;
	default:
		m_databits = QSerialPort::UnknownDataBits;
		break;
	}
}

QSerialPort::DataBits Comm::getDataBits() const
{
	return m_databits;
}
//校验位
void Comm::setParity(QString parity)
{
	if (parity == "no")     m_parity = QSerialPort::NoParity;
	else if (parity == "odd")  m_parity = QSerialPort::OddParity;
	else if (parity == "even")  m_parity = QSerialPort::EvenParity;
	else m_parity = QSerialPort::UnknownParity;
}

QSerialPort::Parity Comm::getParity() const
{
	return m_parity;
}
//停止位
void Comm::setStopBits(int stopbits)
{
	switch (stopbits) {
	case 1:
		m_stopbits = QSerialPort::OneStop;
		break;
	case 2:
		m_stopbits = QSerialPort::TwoStop;
		break;
	default:
		m_stopbits = QSerialPort::UnknownStopBits;
		break;
	}
}

QSerialPort::StopBits Comm::getStopBits() const
{
	return m_stopbits;
}
//打开串口
bool Comm::open()
{
	m_serialPort->setPortName(m_portName);
	m_serialPort->setBaudRate(m_baudRate);
	m_serialPort->setParity(m_parity);
	m_serialPort->setDataBits(m_databits);
	m_serialPort->setStopBits(m_stopbits);
	m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
	m_serialPort->setReadBufferSize(1024);  //1K的缓冲字节
	//qDebug() << m_serialPort->open(QIODevice::ReadWrite);

	return m_serialPort->open(QIODevice::ReadWrite);  //读写方式
}

void Comm::close()
{
	if (m_serialPort->isOpen()){
		m_serialPort->close();
	}
}

bool Comm::clear()
{
	if (m_serialPort->isOpen()){
		m_serialPort->clear();
		this->close();
		return this->open();
	}
	return false;
}

int Comm::readData(char *buffer, int count, int timeout)
{
	int len = 0;
	for (;;){
		int n = m_serialPort->read(&buffer[len], count - len);
		if (n == -1)   //模式错误，返回-1，比如writeOnlyMode.
		{
			qDebug() << "Opening serialport Mode wrong!\n";
			return -1;
		}
		//waitforreadyread这个函数其实会阻塞GUI界面.
		else if (n == 0 && !m_serialPort->waitForReadyRead(timeout)) //除非有新的数据，否则超时返回false。
		{
			qDebug() << "waiting for reading data timeout!\n";
			return  -2;
		}
			
		else{
			len += n;
			if (count == len)
				break;
		}
	}
	return len;
}

QByteArray Comm::readAll()
{
	return m_serialPort->readAll();
}

int Comm::writeData(char *data, int size)
{
	int len = 0;
	for (;;){
		int n = m_serialPort->write(&data[len], size - len);
		if (n == -1)
			return -1;
		else {
			len += n;
			if (len == size)
				break;
		}
	}
	return len;
}

int Comm::writeCh(char *ch)
{
	return m_serialPort->write(ch,1);
}

int Comm::bytesAvailable() const
{
	return m_serialPort->bytesAvailable();
}
