#include "mthread.h"
#include "qdebug.h"

#define SLEEP_TIME 100

mthread::mthread(QObject *parent) :
QThread(parent)
{
	stoped = false;
	lockstate = false;
}

mthread::~mthread()
{

}

void mthread::run()
{
	//在run函数中写入forever循环或者while(1)循环.
	//利用mutex互斥量来挂起和继续一个线程.
	forever{
		pause.lock();
		if (stoped){
			stoped = false;
			pause.unlock();
			break;
		}
		emit sendhandledata();
		qDebug() << "-------------- handle is running -------------"<<QThread::currentThread();
		msleep(SLEEP_TIME);
		pause.unlock();
	}

	/*
	while (!stoped){
		emit sendhandledata();
		qDebug() << "-------------- handle is running -------------";
		msleep(SLEEP_TIME);
	}
	stoped = false;*/
}

void mthread::stop()
{
	stoped = true;
}

void mthread::threadpause()
{
	this->pause.lock();
	this->lockstate = true;
	qDebug() << QString("---pause--- state :%1").arg(lockstate);
}

void mthread::threadresume()
{
	this->pause.unlock();
	this->lockstate = false;
	qDebug() << QString("---resume--- state :%l").arg(lockstate);
}