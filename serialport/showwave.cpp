/*******************************change log**********************************/
//1.调试出为什么AES核心加密模块加密数据量一上去的时候就出现了内存溢出的错误.
//	2016/1/13解决了该问题，是QProgressDialog的问题
//
//2.增加一个系统函数的对话框，调试出FFT刻度出错的原因
//
//3.增加网络模块，基于TCP/IP协议的QT C++ socket/server socket编程

//4.修改核心程序来处理五路并行发过来的数据
#include "showwave.h"
#include "qdebug.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "qfiledialog.h"
#include "qpixmap.h"
#include "qmetatype.h"
#include <bitset>
#include "qprogressdialog.h"
#include "qbuffer.h"
#include "scaleWin.h"

//显示区域设置
#define WIDTH 1200
#define HEIGHT 660
#define REC_WID 510
#define REC_HEI 130
#define D1 50
#define D2 50
#define D3 70
#define D4 80
#define INITIAL_X 102
#define INTTIAL_Y 40
#define READ_DATA false
#define DISPLAY_DATA true
#define PI 3.14159265358979323846
#define min(a,b) (a>b?b:a)
#define versa(a) ((~a+1)&2047)
#define PAYLOAD_LENGTH 8190

extern const int DATA_COUNT;
extern QByteArray dataShare;
extern char buffer[1024];
extern bool mutex;
extern int precision;
extern bool iswaveshow;
extern const int DATA_ARRAY_SIZE = WIDTH;
extern int errorCnt = 0;

showwave::showwave(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::showwaveUi)
{
	qRegisterMetaType<deque<int>>("deque<int>");
	qRegisterMetaType<deque<float>>("deque<float>");
	qRegisterMetaType<vector<BYTE>>("vector<BYTE>");
	qRegisterMetaType<vector<vector<int>>>("vector<vector<int>>");
	ui->setupUi(this);
	ui->listwd->insertItem(0, QStringLiteral("&波形设置"));
	ui->listwd->insertItem(1, QStringLiteral("&算法"));
	ui->listwd->setCurrentRow(0);
	ui->stackedwd->setCurrentIndex(0);
	//添加label来放大图片
	scaleLb1 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb0");
	scaleLb2 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb1");
	scaleLb3 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb2");
	scaleLb4 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb3");
	scaleLb5 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb4");
	QVBoxLayout *Vlayout1 = new QVBoxLayout(this);
	Vlayout1->addWidget(scaleLb1);
	Vlayout1->addWidget(scaleLb2);
	Vlayout1->addWidget(scaleLb3);
	Vlayout1->addWidget(scaleLb4);
	Vlayout1->addWidget(scaleLb5);
	scaleLb6 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb5");
	scaleLb7 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb6");
	scaleLb8 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb7");
	scaleLb9 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb8");
	scaleLb10 = new clickLabel(QPixmap(QCoreApplication::applicationDirPath() + "\\resources\\mirror2.png"), "scaleLb9");
	QVBoxLayout *Vlayout2 = new QVBoxLayout(this);
	Vlayout2->addWidget(scaleLb6);
	Vlayout2->addWidget(scaleLb7);
	Vlayout2->addWidget(scaleLb8);
	Vlayout2->addWidget(scaleLb9);
	Vlayout2->addWidget(scaleLb10);
	ui->mainhorizonLayout->insertLayout(2, Vlayout1);
	ui->mainhorizonLayout->insertLayout(4, Vlayout2);
	setLayout(ui->mainlayout);
	connect(scaleLb1, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb2, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb3, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb4, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb5, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb6, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb7, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb8, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb9, SIGNAL(clicked(int)), this, SLOT(showScale(int)));
	connect(scaleLb10, SIGNAL(clicked(int)), this, SLOT(showScale(int)));

	mpaintthread = new paintthread();
	//mpaintthread->start();
	qDebug() << "*QThread* mpaintthread:-----mpaintthread is running in-----: " << mpaintthread << QThread::currentThread();
	pixmap = new QPixmap(WIDTH, HEIGHT);
	qRegisterMetaType<SWITCH_STATE>("SWITCH_STATE");

	connect(ui->retbt, SIGNAL(clicked()), this, SLOT(showret()));
	menu = menuBar()->addMenu(trUtf8("&Option"));
	closeact = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&close"), this);
	saveact = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&save"), this);
	saveasact = new QAction(QIcon(trUtf8("resources/datou.jpg")), trUtf8("&save as"), this);
	menu->addAction(closeact);
	menu->addAction(saveact);
	menu->addAction(saveasact);
	rect = QRect(0, 0, REC_WID, REC_HEI);
	for (int i = 0; i < 5; ++i){
		recs_l.push_back(QRect(0, i * 135, REC_WID, REC_HEI));
		recs_r.push_back(QRect(560, i * 135, REC_WID, REC_HEI));
	}
	recs = recs_l + recs_r;
	height = rect.height();
	width = rect.width();
	pointtmp = new int[width];		//横坐标点的个数,动态分配内存
	x = 0.0;

	//波形的状态
	switch_state = NORMAL_WAVE;
	flagGrid = true;
	clearFlag = false;
	stopFlag = false;
	sinFlag = false;

	column = DATA_ARRAY_SIZE;
	VALY = 1;
	m_pen_width = 2;
	m_result_pen_width = 1;

	ui->penwidth_spin->setValue(1);
	ui->penwidth_spin->setRange(1, 10);
	ui->otherPenSpin->setValue(1);
	ui->otherPenSpin->setRange(1, 10);

	initPoint.setX(INITIAL_X);
	initPoint.setY(INTTIAL_Y);

	VAL = 1;	//每N个像素显示一个点，即坐标scale
	ui->interalPixelsSpin->setValue(VAL);
	ui->interalPixelsSpin->setRange(1, 100);

	gridnum = 10;
	ui->gridNum->setValue(10);
	ui->gridNum->setRange(1, 100);

	num = new int[DATA_ARRAY_SIZE];
	//memset对num数组的前65300 个字节赋值 
	memset(num, 65300, sizeof(int)*DATA_ARRAY_SIZE);

	N = 1;
	sum1 = new int[column / N];
	sum2 = new int[column / N];
	sum3 = new int[column / N];
	sum4 = new int[column / N];

	//动态创建的对象
	fw = new fftwindow;
	fob = new fftob;
	ffthread = new QThread;
	restFlag = false;

	//初始化UI的时候就调用了paintEvent
	connect(ui->listwd, SIGNAL(currentRowChanged(int)), ui->stackedwd, SLOT(setCurrentIndex(int)));
	connect(ui->gridNum, SIGNAL(valueChanged(int)), this, SLOT(gridSpin(int)));
	connect(ui->interalPixelsSpin, SIGNAL(valueChanged(int)), this, SLOT(pixelSpin(int)));
	connect(ui->penwidth_spin, SIGNAL(valueChanged(int)), this, SLOT(penwidthSpin(int)));
	connect(ui->otherPenSpin, SIGNAL(valueChanged(int)), this, SLOT(result_penwidthSpin(int)));

	connect(closeact, SIGNAL(triggered()), this, SLOT(close()));
	connect(saveact, SIGNAL(triggered()), this, SLOT(saveShowData()));
	connect(saveasact, SIGNAL(triggered()), this, SLOT(saveAsData()));

	connect(ui->showgrid, SIGNAL(clicked()), this, SLOT(drawGrid()));
	connect(ui->snapbt, SIGNAL(clicked()), this, SLOT(grabwindow()));
	connect(ui->savebt, SIGNAL(clicked()), this, SLOT(saveShowData()));
	connect(ui->saveasbt, SIGNAL(clicked()), this, SLOT(saveAsData()));
	connect(ui->saveEffbt, SIGNAL(clicked()), this, SLOT(saveEff()));
	connect(ui->stopbt, SIGNAL(clicked()), this, SLOT(stopshow()));
	connect(ui->showbt, SIGNAL(clicked()), this, SLOT(showNormalWave()));

	connect(ui->avgfilterbt, SIGNAL(clicked()), this, SLOT(on_mathavg_clicked()));
	connect(ui->slidefilterbt, SIGNAL(clicked()), this, SLOT(on_slideavg_clicked()));
	connect(ui->midfilterbt, SIGNAL(clicked()), this, SLOT(on_midavg_clicked()));
	connect(ui->weightfilterbt, SIGNAL(clicked()), this, SLOT(on_addweightavg_clicked()));

	ldtimer = new QTimer(this);
	connect(ldtimer, SIGNAL(timeout()), this, SLOT(timerShowHis()));
	scaleW = nullptr;
	for (int j = 0; j < 5; j++){
		vpp[j] = 0;
		eff[j] = 0;
	}
}

showwave::~showwave()
{
	delete ui;
	delete painter;
	delete pointtmp;
	if (mpaintthread != NULL)
		delete mpaintthread;
	if (ffthread != NULL)
		delete ffthread;
	if (scaleW != NULL)
		delete scaleW;
	delete[]num;
	delete ldtimer;
	delete fw;
	delete fob;
}

void showwave::showScale(int index){
	que_index = index;
	qDebug() << "show scale";
	scaleW = new scaleWin();
	connect(scaleW, SIGNAL(ret()), this, SLOT(appear()));
	connect(this, SIGNAL(sendScaleData(deque<int>)), scaleW, SLOT(showScaleData(deque<int>)));
	scaleW->show();
	this->hide();
}

void showwave::appear(){
	this->show();
	delete scaleW;
	scaleW = nullptr;
}

void showwave::paintEvent(QPaintEvent *qev)
{
	//设置画板画矩形
	painter = new QPainter(this);
	painter->setBrush(Qt::black);
	painter->translate(INITIAL_X, INTTIAL_Y);
	painter->drawRects(recs);
	painter->begin(this);	//设置画板为当前的widget上

	if (flagGrid){
		for (int i = 0; i < recs.size(); ++i)
			showGrid(recs[i], recs[i].x(), recs[i].y());
	}
	for (int i = 0; i < recs.size(); ++i)
		setXYcord(recs[i], recs[i].x(), recs[i].y());

	//reset波形
	if (clearFlag)
	{
		painter->end();
		clearFlag = false;
		sinFlag = 0;
		qDebug() << "clearflag triggeres threadStart!";
		return;
	}
	switch (switch_state){
	case NORMAL_WAVE:
		painter->setPen(QPen(QPen(default_brush, m_pen_width, Qt::SolidLine)));
		showReal();
		break;

	case  SLIDE_AVG:
		painter->setPen(QPen(Qt::red, m_result_pen_width, Qt::SolidLine));
		slideavg();
		break;

	case MID_AVG:
		painter->setPen(QPen(Qt::green, m_result_pen_width, Qt::SolidLine));
		midavg();
		break;

	case ADD_WEIGHT_AVG:
		painter->setPen(QPen(Qt::yellow, m_result_pen_width, Qt::SolidLine));
		addWeightavg();
		break;

	case MATH_AVG:
		painter->setPen(QPen(Qt::blue, m_result_pen_width, Qt::SolidLine));
		mathavg();
		break;

	case MFITER:
		break;

	case SIN_WAVE:
		break;

	default:
		break;
	}
	painter->end();
}

void showwave::setXYcord(const QRect& rect, int x, int y)
{
	//x
	painter->setPen(QPen(Qt::blue));
	for (int i = 0; i < rect.width() / 10; i++)
	{
		point[0].setX(x + i * 10);
		point[0].setY(y + height);
		point[1].setX(x + i * 10);
		point[1].setY(y + height - 1);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	painter->drawLine(QPoint(0, height), QPoint(width, height));
	//y
	painter->setPen(QPen(Qt::red));
	for (int i = height / 10; i > 0; i--)
	{
		point[0].setX(x);
		point[0].setY(y + i * 10);
		point[1].setX(x + 1);
		point[1].setY(y + i * 10);
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
		painter->drawText(rect.x() + i - 2, y + height + 10, QString::number(j, 10));
		j++;
	}

	//y值
	j = height / 10;
	painter->setFont(font);
	for (int i = 0; i <= height; i += 10)
	{
		painter->drawText(rect.x() - 13, y + height - i + 3, QString::number((height) / 10 - 6 - j, 10));
		j--;
	}
}

void showwave::drawGrid()
{
	if (flagGrid){
		ui->showgrid->setText(tr("disaplay"));
		flagGrid = false;
	}
	else{
		ui->showgrid->setText(tr("hide"));
		flagGrid = true;
	}
	repaint();	//调用repaint()函数来触发paintEvent.
}

void showwave::showGrid(const QRect& rect, int x, int y)
{
	//x
	QPen pen(Qt::darkGreen);
	painter->setPen(pen);
	point[0].setY(y);
	point[1].setY(y + height);

	for (int i = 0; i<rect.width() / gridnum; i++)
	{
		point[0].setX(x + i*gridnum);
		point[1].setX(x + i*gridnum);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
	//y
	point[0].setX(x);
	point[1].setX(x + width);
	for (int i = height / gridnum; i >= 0; i--)
	{
		point[0].setY(y + i*gridnum);
		point[1].setY(y + i*gridnum);
		painter->drawLine(QPoint(point[0].x(), point[0].y()), QPoint(point[1].x(), point[1].y()));
	}
}

void showwave::slideavg()
{
	qDebug() << "------slideavg------- :" << "slideavg has been triggered.";
	memset(sum2, 0, sizeof(int)*(column - N));

	int i, j, k;

	for (i = 0; i<column - N; i++)
	{
		for (j = 0; j<N; j++)
		{
			sum2[i] += num[j + i];
		}
		sum2[i] /= N;

		if (i>WIDTH || num[i] >= 65535)
			break;
	}

	i = 0;
	for (k = 0; k< column - N - 1; k++)
	{
		painter->drawLine(QPoint(i, (height - sum2[k] / VALY - D2)), QPoint(i + VAL, (height - sum2[k + 1] / VALY - D2)));
		i += VAL;
		if (i > WIDTH || num[i] >= 65535)
			break;
	}
}

void showwave::midavg()
{
	qDebug() << "------midavg------- :" << "midavg has been triggered.";
	if (N < 3)
		return;

	int i, j, k;
	int min, max;
	k = 0;
	min = 0;
	max = 0;

	memset(sum3, 0, sizeof(int)*column / N);

	for (i = 0; i<column / N; i++)
	{
		if (i>WIDTH || num[k + N] >= 65500)
			break;

		for (j = 0; j<N; j++)
		{
			if (min>num[k])
			{
				min = num[k];
			}
			else if (max<num[k])
			{
				max = num[k];
			}

			k++;
			sum3[i] += num[k];
		}

		sum3[i] -= min + max;
		sum3[i] /= N - 2;
	}
	j = 0;
	for (k = 0; k<i - 1; k++)
	{
		painter->drawLine(QPoint(j, (height - sum3[k] / VALY - D3)), QPoint(j + VAL, (height - sum3[k + 1] / VALY - D3)));
		j += VAL;
	}
}

void showwave::addWeightavg()
{
	qDebug() << "------addWeigetavg------- :" << "addWeigetavg has been triggered.";
	int i, j, k;
	k = 0;
	int weights = 0;

	memset(sum4, 0, sizeof(int)*column / N);

	for (i = 1; i <= N; i++)
	{
		weights += i;
	}

	for (i = 0; i<column / N; i++)
	{
		if (i>WIDTH || num[k + N] >= 65535)
			break;
		for (j = 0; j<N; j++)
		{
			sum4[i] += num[k] * (j + 1);
			k++;
		}
		sum4[i] /= weights;
	}

	j = 0;
	for (k = 0; k<i - 1; k++)
	{
		painter->drawLine(QPoint(j, (height - sum4[k] / VALY - D4)), QPoint(j + VAL, (height - sum4[k + 1] / VALY) - D4));
		j += VAL;
	}
}

void showwave::mathavg()
{
	qDebug() << "------mathavg------- :" << "mathavg has been triggered.";
	memset(sum1, 0, sizeof(int)*column / N);
	int i, j, k, temp, x;
	temp = column / N;
	k = 0;
	x = 0;
	for (i = 0; i<temp; i++)
	{
		for (j = 0; j<N; j++, k++)
		{
			sum1[i] += num[k];
		}
		sum1[i] /= N;
	}
	i = 0;
	for (int n = 0; n<temp - 1; n++)
	{
		int start = 0;
		height = 100;
		for (int j = 0; j<column - 1; j++)
		{
			painter->drawPoint(QPoint(start, num[j]));
			start += VAL;
			if (start>WIDTH)
				break;
		}
	}
}

void showwave::getSVdata(vector<deque<int>> m_vec_que, int m_fre,
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
	if (scaleW != nullptr)
		emit sendScaleData(vec_que_points[que_index]);
}

void showwave::updateFre()
{
	ui->ch0_fre->setText(QString::number(frequency0));
	ui->ch1_fre->setText(QString::number(frequency0));
	ui->ch2_fre->setText(QString::number(frequency0));
	ui->ch3_fre->setText(QString::number(frequency0));
	ui->ch4_fre->setText(QString::number(frequency0));
	ui->ch0_vpp->setText(QString::number(vpp[0]));
	ui->ch1_vpp->setText(QString::number(vpp[1]));
	ui->ch2_vpp->setText(QString::number(vpp[2]));
	ui->ch3_vpp->setText(QString::number(vpp[3]));
	ui->ch4_vpp->setText(QString::number(PAL[4]));
	//把有效值也计算并显示出来
	ui->ch0_ef->setText(QString::number(eff[0]).left(6));
	ui->ch1_ef->setText(QString::number(eff[1]).left(6));
	ui->ch2_ef->setText(QString::number(eff[2]).left(6));
	ui->ch3_ef->setText(QString::number(eff[3]).left(6));
	ui->ch4_ef->setText(QString::number(eff[4]).left(6));
	eff_map[0][frequency0] = eff[0];
	eff_map[1][frequency0] = eff[1];
	eff_map[2][frequency0] = eff[2];
	eff_map[3][frequency0] = eff[3];
	eff_map[4][frequency0] = eff[4];
	if (frequency0 == 1000)
		saveEff();
}

void showwave::showReal()
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
		//painter->drawPoint(QPoint(j, (REC_HEI / 2 +5 + 135 * k - vec_que_points[k].at(j) / VALY)));
		painter->drawPoint(QPoint(j, (REC_HEI / 2 + 5 + 135 * 3 - vec_que_points[3].at(j) / VALY)));
		//painter->drawPoint(QPoint(j, (REC_HEI / 2 + 5 + 135 * 1 - vec_que_points[1].at(j) / VALY)));
		painter->drawPoint(QPoint(j, (REC_HEI / 2 + 5 + 135 * 0 - vec_que_points[0].at(j) / VALY)));
		//}
		startt += VAL;		//周期变为原来的VAL倍，角频率变为原来的1/VAL.
	}
}

void showwave::drawPoints()
{
	setUpdatesEnabled(true);
	repaint();
}

/**************************保存数据点******************************/
void showwave::saveShowData()
{
	commonFunc::saveShowData(this, "autocheck", vec_vec_points);
}

void showwave::saveAsData()
{
	QFileDialog *filedialog = new QFileDialog(this);
	filedialog->setWindowTitle(tr("Save Options"));
	filedialog->setDirectory(tr("."));
	filedialog->setAcceptMode(QFileDialog::AcceptSave);		//设置对话框保存文件
	filedialog->setFileMode(QFileDialog::AnyFile);
	filedialog->setNameFilter(tr("txt files(*.txt)"));

	QString  tmpstr = "";
	for (int i = 0; i < vec_points.size(); ++i){
		tmpstr.append(QString::number(vec_points.at(i), 10));
		tmpstr.append(" ");
	}

	if (filedialog->exec() == QDialog::Accepted){
		QString filename = filedialog->selectedFiles()[0];	//返回类型为QstringList的函数竟然直接在后面加下标使用!
		QFile file;
		file.setFileName(filename);
		if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
		{
			QTextStream saveFileStream(&file);
			saveFileStream << tmpstr;
			saveFileStream.atEnd();
			file.close();
		}
		else{
			qDebug() << "opening files error!" << endl;
			return;
		}
	}
	else
		QMessageBox::warning(this, tr("waring"), tr("you must select one txtfile!"), QMessageBox::Ok);
}

/*************************调整波形显示参数**************************/
void showwave::gridSpin(int newvalue)
{
	gridnum = newvalue;
	setUpdatesEnabled(true);
	update();
}

void showwave::pixelSpin(int newvalue)
{
	VALY = newvalue;
	drawPoints();
}

void showwave::penwidthSpin(int newvalue)
{
	m_pen_width = newvalue;
	qDebug() << "m_pen_width changes :" << newvalue;
	drawPoints();
}

void showwave::result_penwidthSpin(int newvalue)
{
	m_result_pen_width = newvalue;
	drawPoints();
}

void showwave::on_slideavg_clicked()
{
	switch_state = SLIDE_AVG;
	qDebug() << "--------------sendslide--------------";
	drawPoints();
}

void showwave::on_midavg_clicked()
{
	switch_state = MID_AVG;
	qDebug() << "--------------sendmid--------------";
	drawPoints();
}

void showwave::on_addweightavg_clicked()
{
	switch_state = ADD_WEIGHT_AVG;
	qDebug() << "--------------addweight--------------";
	drawPoints();
}

void showwave::on_mathavg_clicked()
{
	switch_state = MATH_AVG;
	qDebug() << "--------------sendmath--------------";
	drawPoints();
}

void showwave::showNormalWave()
{
	switch_state = NORMAL_WAVE;
	qDebug() << "--------------sendnormal--------------";
	drawPoints();
}

void showwave::showret()
{
	emit ret();
	this->hide();
}

void showwave::grabwindow()
{
	commonFunc::grabwindow(this, "autoCheck");
	QMessageBox::information(this, tr("&screenshot"), QStringLiteral("截图成功！"));
}

void showwave::saveEff()
{
	QFile file;
	QDir dir;
	QStringList filters;
	filters << "*.txt" << "*.cpp";

	//保存到exe所在的文件夹中
	dir.setCurrent(QCoreApplication::applicationDirPath());
	dir.setNameFilters(filters);
	QFileInfo sub("./datasave");
	QString dirstr = "datasave";
	if (!sub.exists())
		dir.mkdir(dirstr);
	dir.cd(dirstr);

	QStringList currentFiles = dir.entryList(QDir::Files, QDir::Name);
	QStringList pointfile;
	for each(QString name in currentFiles){
		if (name.contains("effective"))
			pointfile.push_back(name);
	}

	//use lambda for stable sort.
	std::stable_sort(pointfile.begin(), pointfile.end(),
		[](const QString &s1, const QString &s2){return s1.size() < s2.size(); });

	int plen = pointfile.size();
	int nlen;
	QString lst;
	if (plen > 0){
		nlen = pointfile.at(plen - 1).size();
		lst = pointfile.at(plen - 1);
	}
	QString fileName;
	if (plen == 0)
		fileName = "effective.txt";
	else if (lst.at(9).isNumber() && lst.at(10).isNumber())
	{
		int lstnumber = QString(lst.mid(9, 2)).toInt();
		fileName = "effective" + QString::number(lstnumber + 1) + ".txt";
	}
	else if (lst.at(9).isNumber())
	{
		int lstnumber = QString(lst.at(9)).toInt();
		fileName = "effective" + QString::number(lstnumber + 1) + ".txt";
	}
	else {
		fileName = "effective1.txt";
	}
	file.setFileName(dir.filePath(fileName));
	qDebug() << "file's absolutly path is: " + file.fileName();
	if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){	//write,append,txt
		QTextStream stream(&file);
		for (int i = 0; i < 5; ++i){
			stream << "Number " << i + 1 << " channel: ";
			int k = 0;
			stream << endl;
			for (auto iter = eff_map[i].begin(); iter != eff_map[i].end(); ++iter){
				stream << iter->first;
				stream << " KHZ:";
				stream << iter->second;
				stream << 'V';
				stream << endl;
			}
			stream << endl;
			stream << endl;
		}
		stream.atEnd();
		file.close();
	}
}

void showwave::stopshow()
{
	if (!stopFlag)
	{
		stopFlag = true;
		emit sendStop();
		ldtimer->stop();
		ui->stopbt->setText(tr("&continue"));
	}
	else
	{
		stopFlag = false;
		emit sendResume();
		ldtimer->start();
		ui->stopbt->setText(tr("&stopshow"));
	}
	qDebug() << "--------------sendstop--------------";
}

void showwave::closeEvent(QCloseEvent *e)
{
	this->close();
	iswaveshow = false;
	ffthread->terminate();
	mpaintthread->stop();
	qDebug() << "---------errorCnt-------- :" << errorCnt;
}

void showwave::changeEvent(QEvent *e)
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

void showwave::FFTtransform()
{
	//将数据点num[WIDTH]的波形转换为其频谱, 但是不能够实时处理
	fw->show();
	fob->moveToThread(ffthread);
	connect(this, SIGNAL(sendnum(deque<int>)), fob, SLOT(fft(deque<int>)));
	connect(fob, SIGNAL(sendFFTres(deque<float>)), fw, SLOT(fftGet(deque<float>)));
	qDebug() << "FFT thread is  running in :" << ffthread;
	ffthread->start();
}

