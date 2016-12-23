#include "commonFunc.h"
#include "qtextstream.h"
#include "qdebug.h"
commonFunc::commonFunc(){}
commonFunc::~commonFunc(){}
void commonFunc::grabwindow(QWidget *widget,QString prex)
{
	QStringList listfilters;
	listfilters << "*.png" << "*jpeg";
	QDir dir;
	dir.setCurrent(QCoreApplication::applicationDirPath());
	dir.setNameFilters(listfilters);
	QFileInfo sub("./waveshot");
	if (!sub.exists())
		dir.mkdir("waveshot");
	dir.cd("waveshot");

	QStringList currentFiles = dir.entryList(QDir::Files, QDir::Name);
	QStringList pointfile;
	for each(QString name in currentFiles){
		if (name.contains(prex))
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
	int prexsize = prex.size();
	if (plen == 0)
		fileName = prex+".png";
	else if (lst.at(prexsize).isNumber() && lst.at(prexsize + 1).isNumber())
	{
		int lstnumber = QString(lst.mid(prexsize, 2)).toInt();
		fileName = prex + QString::number(lstnumber + 1) + ".png";
	}
	else if (lst.at(prexsize).isNumber())
	{
		int lstnumber = QString(lst.at(prexsize)).toInt();
		fileName = prex + QString::number(lstnumber + 1) + ".png";
	}
	else {
		fileName = prex+"1.png";
	}

	QPixmap pixmap = widget->grab(QRect(30, 20, 1000, 750));
	QString pixpath = dir.filePath(fileName);
	pixmap.save(pixpath, "png");
}

void commonFunc::saveShowData(QWidget *widget,QString prex,vector<vector<int>> vec_vec_points){
	QFile file1, file2, file3, file4, file5;
	QDir dir;
	QStringList filters;
	filters << "*.txt" << "*.cpp";
	dir.setNameFilters(filters);
	dir.setCurrent(QCoreApplication::applicationDirPath());
	qDebug() << "application Dir: " << QCoreApplication::applicationDirPath();

	QFileInfo sub("./datasave");
	QString dirstr = "datasave";
	if (!sub.exists())
		dir.mkdir(dirstr);
	dir.cd(dirstr);

	QStringList currentFiles = dir.entryList(QDir::AllDirs, QDir::Name);
	QStringList pointfile;
	for each(QString name in currentFiles){
		if (name.contains(prex))
			pointfile.push_back(name);
	}
	//use lambda for stable sort.
	std::stable_sort(pointfile.begin(), pointfile.end(),
		[](const QString &s1, const QString &s2){return s1.size() < s2.size(); });

	QString dirname;
	int plen = pointfile.size();
	int nlen;
	int prexsize = prex.size();
	QString lst;
	if (plen > 0){
		nlen = pointfile.at(plen - 1).size();
		lst = pointfile.at(plen - 1);
	}
	if (plen == 0)
		dirname = prex;
	else if (lst.size()>(prexsize+1) && lst.at(prexsize).isNumber()
		 && lst.at(prexsize+1).isNumber())
	{
		int lstnumber = QString(lst.mid(prexsize, 2)).toInt();
		dirname = prex + QString::number(lstnumber + 1);
	}
	else if (lst.size()>prexsize && lst.at(prexsize).isNumber())
	{
		int lstnumber = QString(lst.at(prexsize)).toInt();
		dirname = prex + QString::number(lstnumber + 1);
	}
	else {
		dirname = prex + "1";
	}
	dir.mkdir(dirname);
	dir.cd(dirname);

	QString fileName1, fileName2, fileName3, fileName4, fileName5;
	fileName1 = "channel_1.txt";		fileName2 = "channel_2.txt";
	fileName3 = "channel_3.txt";	fileName4 = "channel_4.txt";
	fileName5 = "channel_5.txt";
	file1.setFileName(dir.filePath(fileName1));		file2.setFileName(dir.filePath(fileName2));
	file3.setFileName(dir.filePath(fileName3));		file4.setFileName(dir.filePath(fileName4));
	file5.setFileName(dir.filePath(fileName5));
	qDebug() << "dataPoints path : " << dir.filePath(fileName1);
	qDebug() << "file's absolutly path is: " + file1.fileName();

	vector<QString> tmpstr(5, "");
	for (int j = 0; j < vec_vec_points.size(); j++){
		for (int i = 0; i < vec_vec_points[j].size(); ++i){
			tmpstr[j].append(QString::number(vec_vec_points[j].at(i), 10));
			tmpstr[j].append(" ");
			if (i % 20 == 1)
				tmpstr[j].append('\n');
		}
	}
	if (file1.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)
		&& file2.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)
		&& file3.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)
		&& file4.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)
		&& file5.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)
		)	//write,append,txt
	{
		QTextStream stream1(&file1);			QTextStream stream2(&file2);
		QTextStream stream3(&file3);		QTextStream stream4(&file4);
		QTextStream stream5(&file5);
		stream1 << tmpstr[0];				stream2 << tmpstr[1];
		stream3 << tmpstr[2];				stream4 << tmpstr[3];
		stream5 << tmpstr[4];
		stream1.atEnd();	stream2.atEnd();	stream3.atEnd();	stream4.atEnd();	stream5.atEnd();
		file1.close();		file2.close();		file3.close();		file4.close();		file5.close();
		QMessageBox::about(widget, "Info", "save successfully!");
	}
	else
		qDebug() << "opening local file error!" << endl;
}
