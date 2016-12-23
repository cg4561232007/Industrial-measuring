#ifndef SCALEWIN_H
#define SCALEWIN_H
#include  "qwidget.h"
#include <deque>
#include <vector>
#include "qevent.h"
#include "qpainter.h"
#include "ui_scaleWin.h"
#include "commonFunc.h"
using std::deque;
using std::vector;
namespace Ui{
	class scaleWin;
}
class scaleWin : public QWidget
{
	Q_OBJECT
public:
	explicit scaleWin(QWidget *parent = 0);
	~scaleWin();
private:
	void setXYcord();
public:
	void paintEvent(QPaintEvent *evp) override;
	void showGrid();	//��ʾ����
	QString ByteArrayToHexstring(QByteArray str);
protected:
	void changeEvent(QEvent	*e) override;
	void closeEvent(QCloseEvent *e) override;

signals:
	void ret();

private:
	QPainter *painter;
	QRect rect;
	deque<int> que_points;
	QPoint point[2];
	QPoint initPoint;

	//������Ϣ
	int column;
	int height;
	int width;
	unsigned gridnum;	//���꾫��
	int *pointtmp;

	//������Ϣ
	int m_pen_width;
	int m_result_pen_width;

	//������Ϣ
	int N;
	float VALY;
	int *num;
	bool stopFlag;
	Ui::scaleWin *ui;

	public slots:
	//�������ݸ��Ŵ���Ļ�Ŀؼ�
	void showScaleData(deque<int>);

	private slots:
	void grabwindow();
	void stopshow();
	void showret();
public:
	void judgeColor(quint16 fid, QBrush& brush);
};
#endif