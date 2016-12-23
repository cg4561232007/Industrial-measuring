#ifndef FIXCHECK_H
#define FIXCHECK_H
#include "ui_fixCheck.h"
#include "qwidget.h"
#include "qmainwindow.h"
#include "qpainter.h"
#include "clickLabel.h"
#include <vector>
#include <deque>
using namespace std;
namespace Ui{
	class fixCheck;
}

class fixCheck : public QWidget
{
	Q_OBJECT
public:
	explicit fixCheck(QWidget *parent = 0);
	~fixCheck();

private:
	Ui::fixCheck *ui;
public:
	void paintEvent(QPaintEvent *evp) override;
	void showGrid();
	void drawPoints();
	void updateFre();
	void showReal();

private:
	void setXYcord();
	bool belongto(quint16, quint16, quint16);
	QByteArray HexstringToByteArray(QString str);
protected:
	void changeEvent(QEvent	*e) override;
	void closeEvent(QCloseEvent *e) override;
signals:
	void ret();
	void sendStop();
	void sendResume();
	void sendFre(QByteArray);

private:
	QPainter *painter;
	QPoint point[2];
	QPoint initPoint;
	//坐标信息
	QRect rect;
	int height;
	int width;
	unsigned gridnum;	//坐标精度
	//参数信息
	int N;
	float VALY;
	int VAL;
	int *num;
	QBrush default_brush = Qt::yellow;
	bool stopFlag;
	quint16 PAL[5];

	quint16 fix_fre = 0;
	QByteArray send_fre;
	vector<deque<int>> vec_que_points = { 5, {} };
	vector<vector<int>> vec_vec_points = { 5, {} };
	quint16 frequency0 = 0;
	double eff[5];
	quint16 vpp[5];

	private slots:
	void saveShowData();
	void grabwindow();
	void stopshow();
	void showret();
	public slots:
	void getSVdata(vector<deque<int>>, int, vector<int>, vector<double>, vector<vector<int>>);
	void mapfrequecy();
};

#endif