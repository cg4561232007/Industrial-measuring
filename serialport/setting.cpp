#include "setting.h"
#include "qdir.h"
#include "qtextstream.h"
#include "qfile.h"
#include "qdebug.h"

setting::setting(QWidget *parent) :
QWidget(parent),
ui(new Ui::setting)
{
	ui->setupUi(this);
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(loadSetting()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ensure()));
}

setting::~setting()
{
	delete ui;
}

void setting::loadSetting()
{
	double pal[9] = { 0 };
	QDir dir;
	dir.setCurrent(QCoreApplication::applicationDirPath());
	QString filename = "pal.ini";
	QFile file;
	qDebug() << dir.filePath(filename);
	file.setFileName(dir.filePath(filename));
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream inStream(&file);
		QString readLine, palname, paldata;
		while (inStream.readLineInto(&readLine))
		{
			if (readLine.contains(":="))
			{
				int pos1 = readLine.indexOf(":");
				int pos2 = readLine.indexOf("=");
				paldata = readLine.mid(pos2+1);
				palname = readLine.mid(0, pos1);
				palinfo.insert(palname, paldata);
			}
		}
	}
	ui->lineEdit->setText(palinfo["0"]);
	ui->lineEdit_2->setText(palinfo["1"]);
	ui->lineEdit_3->setText(palinfo["2"]);
	ui->lineEdit_4->setText(palinfo["3"]);
	ui->lineEdit_5->setText(palinfo["4"]);
	ui->lineEdit_6->setText(palinfo["5"]);
	ui->lineEdit_7->setText(palinfo["6"]);
	ui->lineEdit_8->setText(palinfo["7"]);
	ui->lineEdit_9->setText(palinfo["8"]);
}

void setting::ensure()
{
	pal_send.insert("0", ui->lineEdit->text());
	pal_send.insert("1", ui->lineEdit_2->text());
	pal_send.insert("2", ui->lineEdit_3->text());
	pal_send.insert("3", ui->lineEdit_4->text());
	pal_send.insert("4", ui->lineEdit_5->text());
	pal_send.insert("5", ui->lineEdit_6->text());
	pal_send.insert("6", ui->lineEdit_7->text());
	pal_send.insert("7", ui->lineEdit_8->text());
	emit transpal(palinfo);
	this->hide();
}