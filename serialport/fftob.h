#ifndef FFTOB_H
#define FFTOB_H

#include "fftw3.h"
#include "qobject.h"
#include <deque>

using std::deque;
class fftob: public QObject
{
	Q_OBJECT
public:
	explicit fftob(QObject *parent = 0);
	~fftob();
	
signals:
	void sendFFTres(deque<float>);

	public slots:
	void fft(deque<int>);

private:
	deque<float> fftres;

};

#endif