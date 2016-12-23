#include "fixCheck.h"
#include "qdir.h"
#include "qmessagebox.h"
#include "qdebug.h"
#include "commonFunc.h"
//显示区域设置
#define WIDTH 1200
#define HEIGHT 660
#define REC_WID 900
#define REC_HEI 650
#define AREA_HEI 130
#define INITIAL_X 115
#define INTTIAL_Y 45
#define PI 3.14159265358979323846
#define min(a,b) (a>b?b:a)
#define versa(a) ((~a+1)&2047)

fixCheck::fixCheck(QWidget *parent) :
QWidget(parent),
ui(new Ui::fixCheck)
{
	ui->setupUi(this);
	rect = QRect(0, 0, REC_WID, REC_HEI);
	height = rect.height();
	width = rect.width();
	stopFlag = false;
	VALY = 0.5;
	gridnum = 10;
	initPoint.setX(INITIAL_X);
	initPoint.setY(INTTIAL_Y);
	VAL = 2;	//每N个像素显示一个点，即坐标scale
	N = 1;
	connect(ui->retbt, SIGNAL(clicked()), this, SLOT(showret()));
	connect(ui->snapbt, SIGNAL(clicked()), this, SLOT(grabwindow()));
	connect(ui->stopbt, SIGNAL(clicked()), this, SLOT(stopshow()));
	connect(ui->chekbt, SIGNAL(clicked()), this, SLOT(mapfrequecy()));
	connect(ui->savebt, SIGNAL(clicked()), this, SLOT(saveShowData()));
}

fixCheck::~fixCheck()
{
	delete painter;
}

void fixCheck::stopshow()
{
	if (!stopFlag)
	{
		stopFlag = true;
		ui->stopbt->setText(tr("&continue"));
	}
	else
	{
		stopFlag = false;
		ui->stopbt->setText(tr("&stopshow"));
	}
	qDebug() << "--------------sendstop--------------";
}

void fixCheck::paintEvent(QPaintEvent *qev)
{
	//设置画板画矩形
	painter = new QPainter(this);
	painter->setBrush(Qt::black);
	painter->translate(INITIAL_X, INTTIAL_Y);
	painter->drawRect(rect);
	painter->begin(this);	//设置画板为当前的widget上
	setXYcord();
	showGrid();
	showReal();
	painter->end();
}

void fixCheck::showReal()
{
	int startt = 0;
	int min_qz = REC_WID;
	int max_qz = 0;
	for (int j = 0; j < 5; j++){
		if (min_qz>vec_que_points[j].size())
			min_qz = vec_que_points[j].size();
		if (max_qz<vec_que_points[j].size())
			max_qz = vec_que_points[j].size();
	}
	if (max_qz == 0){
		qDebug() << "five ques are all empty.";
		return;
	}
	for (int j = 0; j < min_qz - 1; ++j)
	{
		painter->setPen(QPen(QPen(Qt::yellow, 2, Qt::SolidLine)));
		//for (int k = 0; k < 5; ++k){
		//painter->drawPoint(QPoint(startt, (AREA_HEI / 2 + 130 * k - vec_que_points[k].at(j) / VALY)));
		painter->drawPoint(QPoint(startt, (AREA_HEI / 2 + 130 * 3 - vec_que_points[3].at(j) / VALY)));
		painter->drawPoint(QPoint(startt, (AREA_HEI / 2 + 130 * 0 - vec_que_points[0].at(j) / VALY)));
		//}
		startt += VAL;		//周期变为原来的VAL倍，角频率变为原来的1/VAL.
	}
}

void fixCheck::showGrid()
{
	//x
	QPen pen(Qt::darkGreen);
	painter->setPen(pen);
	point[0].setY(0);
	point[1].setY(height);

	for (int i = 0; i<rect.width() / gridnum; i++)
	{
		point[0].setX(i*gridnum);
		point[1].setX(i*gridnum);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	//y
	point[0].setX(0);
	point[1].setX(width);
	for (int i = height / gridnum; i >= 0; i--)
	{
		point[0].setY(i*gridnum);
		point[1].setY(i*gridnum);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
}

void fixCheck::setXYcord()
{
	//x
	painter->setPen(QPen(Qt::blue));
	for (int i = 0; i < rect.width() / 10; i++)
	{
		point[0].setX(i * 10);
		point[0].setY(height);
		point[1].setX(i * 10);
		point[1].setY(height - 1);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	painter->drawLine(QPoint(0, height), QPoint(width, height));
	//y
	painter->setPen(QPen(Qt::red));
	for (int i = height / 10; i > 0; i--)
	{
		point[0].setX(0);
		point[0].setY(i * 10);
		point[1].setX(1);
		point[1].setY(i * 10);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	painter->drawLine(QPoint(0, 0), QPoint(0, height));

	//x值
	int j = 1;
	QFont font("Arial", 6, QFont::Normal, true);
	painter->setPen(QPen(Qt::black));
	painter->setFont(font);
	for (int i = 10; i<width; i += 10)
	{
		painter->drawText(rect.x() + i - 2, height + 10, QString::number(j, 10));
		j++;
	}

	//y值
	j = height / 10;
	painter->setFont(font);
	for (int i = 0; i <= height; i += 10)
	{
		painter->drawText(rect.x() - 13, height - i + 3, QString::number((height) / 10 - 33 - j, 10));
		j--;
	}
}

void fixCheck::drawPoints()
{
	setUpdatesEnabled(true);
	repaint();
}

void fixCheck::showret()
{
	emit ret();
	this->hide();
}

void fixCheck::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void fixCheck::closeEvent(QCloseEvent *e)
{
	this->close();
}

void fixCheck::grabwindow()
{
	commonFunc::grabwindow(this, "fixCheck");
	QMessageBox::information(this, tr("&screenshot"), QStringLiteral("截图成功！"));
}

void fixCheck::saveShowData()
{
	commonFunc::saveShowData(this, "fixcheck", vec_vec_points);
}

void fixCheck::mapfrequecy()
{
	QString sendstr = ui->lineHZ->text();
	fix_fre = sendstr.toInt();
	if (belongto(fix_fre, 1, 200)){
		QByteArray send_fre = HexstringToByteArray(QString("DC") + QString::number(fix_fre, 16));
		emit sendFre(send_fre);
		return;
	}
	if (belongto(fix_fre, 201, 400)){
		QByteArray send_fre = HexstringToByteArray(QString("E8") + QString::number(fix_fre - 200, 16));
		emit sendFre(send_fre);
		return;
	}
	if (belongto(fix_fre, 401, 600)){
		QByteArray send_fre = HexstringToByteArray(QString("EC") + QString::number(fix_fre - 400, 16));
		emit sendFre(send_fre);
		return;
	}
	if (belongto(fix_fre, 601, 800)){
		QByteArray send_fre = HexstringToByteArray(QString("F8") + QString::number(fix_fre - 600, 16));
		emit sendFre(send_fre);
		return;
	}
	if (belongto(fix_fre, 801, 1000)){
		QByteArray send_fre = HexstringToByteArray(QString("FC") + QString::number(fix_fre - 800, 16));
		emit sendFre(send_fre);
		return;
	}
}

//Hex到原型Ascii的转换
QByteArray fixCheck::HexstringToByteArray(QString str)
{
	//将字符串两两分割装到byte里面.
	str.remove(" ");
	int len = str.length();
	//用16进制表示的他的Ascii码一般是偶数的 
	if (len % 2)
		str = str.mid(0, len - 1) + "0" + str.right(1);
	QByteArray buffer;
	for (int i = 0; i < len; i += 2){
		//char a[4];
		QString tmp = str.mid(i, 2);
		//qsnprintf(a, sizeof(tmp), "%d", tmp);
		buffer.append(tmp.toInt(0, 16));
		qDebug() << "buffer is :" << buffer;
	}
	return buffer;
}

bool fixCheck::belongto(quint16 value, quint16 left, quint16 right)
{
	return (value >= left && value <= right);
}

void fixCheck::getSVdata(vector<deque<int>> m_vec_que, int m_fre,
	vector<int> m_vpp, vector<double> m_eff, vector<vector<int>> m_numvec)
{
	vec_que_points = m_vec_que;
	frequency0 = m_fre;
	for (int i = 0; i < 5; ++i){
		vpp[i] = m_vpp[i];
		eff[i] = m_eff[i];
	}
	drawPoints();
	updateFre();
	for (int i = 0; i < 5; ++i)
		vec_vec_points[i].insert(vec_vec_points[i].end(), m_numvec[i].begin(), m_numvec[i].end());
}

void fixCheck::updateFre()
{
	ui->ch0_fre->setText(QString::number(frequency0));
	ui->ch1_fre->setText(QString::number(frequency0));
	ui->ch2_fre->setText(QString::number(frequency0));
	ui->ch3_fre->setText(QString::number(frequency0));
	ui->ch4_fre->setText(QString::number(frequency0));
	ui->ch0_vpp->setText(QString::number(PAL[0]));
	ui->ch1_vpp->setText(QString::number(PAL[1]));
	ui->ch2_vpp->setText(QString::number(PAL[2]));
	ui->ch3_vpp->setText(QString::number(PAL[3]));
	ui->ch4_vpp->setText(QString::number(PAL[4]));
	//把有效值也计算并显示出来
	ui->ch0_vef->setText(QString::number(eff[0]));
	ui->ch1_vef->setText(QString::number(eff[1]));
	ui->ch2_vef->setText(QString::number(eff[2]));
	ui->ch3_vef->setText(QString::number(eff[3]));
	ui->ch4_vef->setText(QString::number(eff[4]));
}