#ifndef MTHREAD_H
#define MTHREAD_H

#include "qthread.h"
#include "qmutex.h"

class mthread : public QThread
{
	Q_OBJECT
public:
	explicit mthread(QObject *parent=0);
	~mthread();

protected:
	void run() override;

signals:
	void sendhandledata();

	public slots:
	void stop();
	void threadpause();
	void threadresume();

private:
	volatile bool stoped;
	QMutex pause;
	
public:
	bool lockstate;
};

#endif