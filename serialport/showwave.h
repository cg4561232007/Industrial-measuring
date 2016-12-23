#ifndef SHOWWAVE_H
#define SHOWWAVW_H

#include "qwidget.h"
#include "qmainwindow.h"
#include "qmessagebox.h"
#include "ui_showwave.h"
#include "qpainter.h"
#include "qmenu.h"
#include "qmenubar.h"
#include "mthread.h"
#include "paintthread.h"
#include "qtimer.h"
#include <vector>
#include <map>
#include "qvector.h"
#include "fftwindow.h"
#include "fftob.h"
#include "qprogressdialog.h"
#include "clickLabel.h"

typedef unsigned char BYTE;
using namespace std;
namespace Ui{
	class showwaveUi;
}

class showwave : public QMainWindow
{
	Q_OBJECT
public:
	explicit showwave(QWidget *parent = 0);
	~showwave();

private:
	Ui::showwaveUi *ui;

public:
	void paintEvent(QPaintEvent *evp) override;

private:
	void setXYcord(const QRect&, int, int);
public:
	void showGrid(const QRect&, int, int);	//��ʾ����
	void updateFre();
	//�㷨
	void slideavg();
	void mathavg();
	void addWeightavg();
	void midavg();
protected:
	void changeEvent(QEvent	*e) override;
	void closeEvent(QCloseEvent *e) override;

signals:
	void ret();
	void sendnum(deque<int>);
	void sendScaleData(deque<int>);
	void sendStop();
	void sendResume();
private:
	QPainter *painter;
	QVector<QRect> recs_l, recs_r, recs;
	QPen m_scaleline_pen;
	QPen m_datawave_pen;
	vector<deque<int>> vec_que_points = { 5, {} };
	vector<vector<int>> vec_vec_points = { 5, {} };
	vector<int> vec_points;
	vector<map<int, double>> eff_map = { 5, {} };
	QPoint point[2];
	QPoint initPoint;

	//������Ϣ
	int column;
	QRect rect;
	int height;
	int width;
	qreal x;
	unsigned gridnum;	//���꾫��
	int *pointtmp;

	//������Ϣ
	int m_pen_width;
	int m_result_pen_width;
	int *sum1, *sum2, *sum3, *sum4;

	//������Ϣ
	int N;
	float VALY;
	int VAL;
	int *num;
	bool restFlag;
	QByteArray restData;
	QBrush default_brush = Qt::yellow;
	//Ƶ��
	quint16 frequency0 = 0;
	double eff[5];
	quint16 vpp[5];
	quint16 PAL[5];

	//��־λ
	int flag;
	bool flagGrid;
	bool clearFlag;
	bool stopFlag;
	bool sinFlag;

	//�˵���
	QMenu *menu;
	QAction *saveact;
	QAction *saveasact;
	QAction *closeact;
	paintthread *mpaintthread;
	QPixmap *pixmap;
	QThread *ffthread;
	QThread  aesthread;
	fftob *fob;
	SWITCH_STATE switch_state;	//״̬
	QTimer *ldtimer;

	public slots:
	//slotsҲ����ͨ����ͨ��������
	void drawGrid();	//�ڳ�ʼ�� Uiʱ����repaint()
	void drawPoints();	//���õ������ݴ���ɵ�
	void getSVdata(vector<deque<int>>, int, vector<int>, vector<double>, vector<vector<int>>);
	void showReal();
	void showNormalWave();
	void FFTtransform();

	private slots:
	void saveShowData();
	void saveAsData();
	void grabwindow();
	void saveEff();
	void stopshow();

	void gridSpin(int);
	void pixelSpin(int);
	void penwidthSpin(int);
	void result_penwidthSpin(int);
	void on_mathavg_clicked();
	void on_midavg_clicked();
	void on_slideavg_clicked();
	void on_addweightavg_clicked();
	void showret();

	//show scale
	void showScale(int);
	void appear();

private:
	fftwindow *fw;
	clickLabel *scaleLb1, *scaleLb2, *scaleLb3, *scaleLb4, *scaleLb5,
		*scaleLb6, *scaleLb7, *scaleLb8, *scaleLb9, *scaleLb10;
	QWidget *scaleW;
	int que_index = 0;
};
#endif