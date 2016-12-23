#ifndef COMM_H
#define COMM_H

#include <QObject>
#include <QtSerialPort/QtSerialPort>    //ͷ�ļ�ֻ����Ķ���ͺ�������������û�о���ʵ�֣�����Ҫ���������ϼ���Qtserialport��lib��.
#include <QString>
#include <QList>
#include "qbytearray.h"
class Comm : public QObject
{
	Q_OBJECT    //һ������Ҫ��moc��Ϣ���滻Ϊ��
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
	//����У��λ������λ��ֹͣλ
	QSerialPort::Parity m_parity;
	QSerialPort::DataBits m_databits;
	QSerialPort::StopBits m_stopbits;
	//��Ӧ�ð���һ�����ڶ����Ա.
	QSerialPort *m_serialPort;
	//QSerialPortInfo *m_serialPortinfo;
};

#endif // COMM_H
