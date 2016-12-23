#include "fftob.h"
#include "qdebug.h"
#include "qthread.h"
#include "qmetatype.h"
#define WIDTH 1200
#define PI 3.1415926

extern const int DATA_ARRAY_SIZE;

fftob::fftob(QObject *parent) :
QObject(parent)
{
	qRegisterMetaType<deque<float>>("deque<float>");
}

fftob::~fftob()
{

}

void fftob::fft(deque<int> fftsource)
{
	//处理fftsource就行
	qDebug() << "FFT Processing...";
	//int len = fftsource.size();
	int len = 900;
	qDebug() << "fftsource len is: " << len;
	double *in = NULL;
	in = (double*)fftw_malloc(sizeof(double)*len);
	for (int i = 0; i != len; ++i){
		in[i] = sin(200 * PI *i / len) + sin(1000 * PI *i / len) + sin(900 * PI *i / len);
		//in[i] = fftsource.at(i);
	}
	fftw_complex *out = NULL;
	fftw_plan  p;
	out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*len);
	p = fftw_plan_dft_r2c_1d(len,in,out,FFTW_ESTIMATE);
	fftw_execute(p);
	//输出幅度谱
	for (int i = 0; i != len; ++i){
		fftres.push_back(sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]));
	}
	//释放资源
	fftw_destroy_plan(p);
	fftw_free(in);
	fftw_free(out);
	qDebug() << "Sending FFT res";
	emit sendFFTres(fftres);
	//出现了内存泄漏的问题,要清空deque才能保证UI不卡.
	fftres.clear();	
}
