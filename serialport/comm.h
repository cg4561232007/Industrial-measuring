#ifndef COMM_H
#define COMM_H

#include <QObject>
#include <QtSerialPort/QtSerialPort>    //头文件只是类的定义和函数的声明，并没有具体实现，还需要在链接器上加入Qtserialport的lib库.
#include <QString>
#include <QList>
#include "qbytearray.h"
class Comm : public QObject
{
	Q_OBJECT    //一长串必要的moc信息被替换为宏
public:
	explicit Comm(QObject *parent = 0);
	~Comm();
	bool isopen() const;
	void setPortName(const QString &name);
	QString getPortName() const;
	//static QList<QSerialPortInfo> availablePort();

	void setBaudRate(int);
	QSerialPort::BaudRate BaudRate(int) const;

	void setDataBits(int);
	QSerialPort::DataBits getDataBits() const;

	void setParity(QString);
	QSerialPort::Parity getParity() const;

	void setStopBits(int);
	QSerialPort::StopBits getStopBits() const;

	int bytesAvailable() const;

	virtual bool open();
	virtual void close();
	virtual bool clear();
	int readData(char *buffer, int count, int timeout = 50);
	QByteArray readAll();
	int writeData(char *data, int size);
	int writeCh(char *ch);

protected:
	QString m_portName;
	int m_baudRate;
	//增加校验位，数据位，停止位
	QSerialPort::Parity m_parity;
	QSerialPort::DataBits m_databits;
	QSerialPort::StopBits m_stopbits;
	//还应该包括一个串口对象成员.
	QSerialPort *m_serialPort;
	//QSerialPortInfo *m_serialPortinfo;
};

#endif // COMM_H
