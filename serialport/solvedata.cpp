#include "solvedata.h"
#include "qdebug.h"
#include <bitset>
#include "qfile.h"
#include "qcoreapplication.h"
#include "qmessagebox.h"
#include "qdir.h"
extern bool mutex;
extern QByteArray dataShare;
#define READ_DATA false
#define DISPLAY_DATA true
#define REC_WID 510

solvedata::solvedata(QObject *parent) :
QObject(parent)
{
	restFlag = false;
	qRegisterMetaType<vector<deque<int>>>("vector<deque<int>>");
	qRegisterMetaType<vector<vector<int>>>("vector<vector<int>>");
	qRegisterMetaType<vector<int>>("vector<int>");
	qRegisterMetaType<vector<double>>("vector<double>");
	for (int j = 0; j < 5; j++){
		vpp[j] = 0;
		eff[j] = 0;
		THE_PAL[j] = 0;
	}
}

solvedata::~solvedata()
{
}

/*************处理从handler线程中传来的sendData事件****************/
void solvedata::testdata()
{
	qDebug() << "**********************************************";
	qDebug() << "------------------testdata------------------- ";
	processSharedata();
	mutex = READ_DATA;
	//给界面发送数据
	emit(sendSVdata(vec_que_points, frequency0,
		vector<int>{&THE_PAL[0], &THE_PAL[5]}, vector<double>{&eff[0], &eff[5]},
		vec_vec));
}

void solvedata::processSharedata()
{
	//在打开了showwave之后才会打出下面的DeBug()消息
	if (mutex == DISPLAY_DATA)
	{

		qDebug() << "processSharedData MUTEX:" << " ------ DISPLAY_DATA------- WAITING FOR READ_DATA";
		processEightdata();
	}
	else{
		qDebug() << "processSharedData MUTEX: " << " ------READ_DATA------- WAITING FOR DISPLAY_DATA";
		qDebug() << "Fatal error: " << "This debug message can never appear!";
		return;
	}
}

double solvedata::getEff(const vector<double> &comparable)
{
	if (comparable.empty())
		return 0.0;
	double sumPow = 0.0;
	for (int i = 0; i < comparable.size(); ++i)
	{
		sumPow += pow(comparable[i], 2);
	}
	double ap = sqrt(sumPow / comparable.size());
	return ap;
}

int solvedata::getVpp(const vector<double> &comparable)
{
	int maxv = 0;
	int minv = 65535;
	for (int i = 0; i < comparable.size(); ++i)
	{
		if (maxv < comparable[i])
			maxv = comparable[i];
		if (minv>comparable[i])
			minv = comparable[i];
	}
	return maxv - minv;
}

void solvedata::processEightdata()
{
	//重新写process数据处理程序来实现五路数据
	int dataLength = dataShare.length();
	/*if (ffthread->isRunning()){
	emit sendnum(que_points);
	qDebug() << "Sending nums";
	}*/
	qDebug() << "datalength :" << dataLength;
	qDebug() << "Important message about dataShare: --------dataShare-------- :" << dataShare;
	if (dataLength == 0)		//无数据返回
		return;
	if (dataLength <= 4){
		qDebug() << "header missing";
		return;
	}
	if (restFlag){
		dataShare.insert(0, restData);
		qDebug() << "restdata :" << restData;
	}
	QString cat1 = ByteArrayToHexstring(dataShare);
	qDebug() << "Original data:" << cat1;
	qDebug() << "Original dataLength:" << cat1.length();

	//格式为：FFFF + 一字节frameId + 一字节（高四位通道数+高四位档位） + 两字节频率 + 30字节有效数据
	QByteArray header, beginData;
	vector<int> resdata0, resdata1, resdata2, resdata3, resdata4;
	quint16 frameId;
	quint16 frequency = 0;
	QString ROAD_PAL;
	quint16 ROAD, PAL;
	quint16 validSize = 30;
	//写一个循环，找出所有\xFF\xFF出现的位置
	int pos1 = dataShare.indexOf("\xFF\xFF");
	if (pos1 == -1)
		return;
	int pos2;
	if (pos1 != 0 && pos1 != -1){
		qDebug() << "-------------\\xFF NOT IN RECV HEAD-------------- ";
		beginData = dataShare.mid(0, pos1 - 1);
		qDebug() << "beginData: " << beginData;
	}
	while (pos1 != -1){
		pos2 = dataShare.indexOf("\xFF\xFF", pos1 + 2);
		if (pos2 == -1){
			qDebug() << "pos2 -1   ";
			restFlag = true;
			restData = dataShare.mid(pos1);	//将包括FF FF的不完整包整个续在下一个包前面
			qDebug() << "restData: " << restData;
			break;
		}
		//解析出包内的重要信息
		frameId = ByteArrayToHexstring(dataShare.mid(pos1 + 2, 1)).toInt(0, 16);
		qDebug() << "frameId: " << frameId;
		ROAD_PAL = ByteArrayToHexstring(dataShare.mid(pos1 + 3, 1));
		qDebug() << "ROAD_PAL: " << ROAD_PAL;
		ROAD = substr2bit(ROAD_PAL, 0, 3);
		qDebug() << "ROAD: " << ROAD;
		PAL = substr2bit(ROAD_PAL, 4, 7);
		qDebug() << "PAL: " << PAL;
		frequency = ByteArrayToHexstring(dataShare.mid(pos1 + 4, 2)).toInt(0, 16);
		qDebug() << "frequency: " << frequency;
		QByteArray nextValid = dataShare.mid(pos1 + 6, pos2 - pos1 - 6);
		nextValid.remove(nextValid.size() - 1, 1);
		qDebug() << "nextValid: " << nextValid;
		if (nextValid.size() != validSize){
			qDebug() << "-------------valid real size has problems------------- " << nextValid.size();
		}

		//解决量程的问题
		vector<int> paldata;
		vector<double> post_pal;
		paldata = deal_valid_data(nextValid);
		post_pal = toPalData(paldata, PAL);
		//解决有效值和峰峰值的问题
		if (last_fre != frequency&&!effmap0[last_fre].empty())
		{
			vpp[0] = getVpp(effmap0[last_fre]);
			vpp[1] = getVpp(effmap1[last_fre]);
			vpp[2] = getVpp(effmap2[last_fre]);
			vpp[3] = getVpp(effmap3[last_fre]);
			vpp[4] = getVpp(effmap4[last_fre]);
			eff[0] = getEff(effmap0[last_fre]);
			eff[1] = getEff(effmap1[last_fre]);
			eff[2] = getEff(effmap2[last_fre]);
			eff[3] = getEff(effmap3[last_fre]);
			eff[4] = getEff(effmap4[last_fre]);
			effmap0.erase(last_fre);		effmap1.erase(last_fre);
			effmap2.erase(last_fre);		effmap3.erase(last_fre);		effmap4.erase(last_fre);
		}
		last_fre = frequency;

		switch (ROAD)
		{
		case 1:
			frequency0 = frequency;
			effmap0[frequency].insert(effmap0[frequency].end(), post_pal.begin(), post_pal.end());
			resdata0.insert(resdata0.end(), paldata.begin(), paldata.end());
			THE_PAL[0] = PAL;
			break;
		case 2:
			effmap1[frequency].insert(effmap1[frequency].end(), post_pal.begin(), post_pal.end());
			resdata1.insert(resdata1.end(), paldata.begin(), paldata.end()); THE_PAL[1] = PAL;
			break;
		case 3:
			effmap2[frequency].insert(effmap2[frequency].end(), post_pal.begin(), post_pal.end());
			resdata2.insert(resdata2.end(), paldata.begin(), paldata.end()); THE_PAL[2] = PAL;
			break;
		case 4:
			effmap3[frequency].insert(effmap3[frequency].end(), post_pal.begin(), post_pal.end());
			resdata3.insert(resdata3.end(), paldata.begin(), paldata.end()); THE_PAL[3] = PAL;
			break;
		case 5:
			effmap4[frequency].insert(effmap4[frequency].end(), post_pal.begin(), post_pal.end());
			resdata4.insert(resdata4.end(), paldata.begin(), paldata.end()); THE_PAL[4] = PAL;
			break;
		default:
			break;
		}
		pos1 = pos2;
	}
	numvec[0].insert(numvec[0].begin(), resdata0.begin(), resdata0.end());
	numvec[1].insert(numvec[1].begin(), resdata1.begin(), resdata1.end());
	numvec[2].insert(numvec[2].begin(), resdata2.begin(), resdata2.end());
	numvec[3].insert(numvec[3].begin(), resdata3.begin(), resdata3.end());
	numvec[4].insert(numvec[4].begin(), resdata4.begin(), resdata4.end());
	for (int j = 0; j < 5; j++){
		if (vec_vec[j].size() != 0)
			vec_vec[j].clear();
		vec_vec[j] = numvec[j];
	}
	int k = 0;
	for (auto &inNum : numvec){
		saveIn_vec_que(inNum, k);
		++k;
	}
}

vector<double> solvedata::toPalData(vector<int>& pld, int pal)
{
	double pmul = 0.0;
	switch (pal)
	{
	case 0:	pmul = g_pal[0];    break;
	case 1: pmul = g_pal[1];    break;
	case 2: pmul = g_pal[2];	break;
	case 3: pmul = g_pal[3];	break;
	case 4: pmul = g_pal[4];	break;
	case 5: pmul = g_pal[5];	break;
	case 6: pmul = g_pal[6];	break;
	case 7: pmul = g_pal[7];	break;
	case 8: pmul = g_pal[8];	break;
	default:
		break;
	}
	vector<double> post;
	for (auto a : pld){
		post.push_back((double)a / (204.8*pmul));		//毫伏
	}
	return post;
}

vector<int> solvedata::deal_valid_data(const QByteArray &vd)
{
	if (vd.isEmpty()){
		return{};
	}
	QString cat;
	cat = ByteArrayToHexstring(vd);
	QStringList mouse;
	unsigned err = 0;
	for (int i = 0; i < cat.length();){
		if (i == cat.length() - 4 && cat[i] == '0'){
			mouse << cat.mid(i + 1);
			i += 4;
		}
		if (i <= cat.length() - 4){
			if (cat[i] == '0'&&cat[i + 4] == '0'){
				mouse << cat.mid(i + 1, 3);
				i += 4;
			}
			else{
				qDebug() << "-----------Bad times occurs------------ " << "in cat[" << i << "]";
				qDebug() << cat;
				qDebug() << cat.mid(i, 4);
				++i;
			}
		}
		else
			++i;
	}
	qDebug() << "mouse :" << mouse;
	vector<int> vlg;
	for (int i = 0; i < mouse.length(); ++i){
		string bit = mouse.at(i).toStdString();
		string bit2 = hexto2bit(bit);
		bitset<12> bitvec(std::stoul(bit, 0, 16));
		int lg;
		int ulg = std::stoul(bit2.substr(1), 0, 2);
		if (bitvec[11])
			lg = -(2048 - ulg);	//负数取反加一.
		else
			lg = ulg;
		vlg.push_back(lg / 10);
	}
	return vlg;
}

void solvedata::deal_valid_data(QByteArrayList vdlist)
{
	for (int ptr = 0; ptr < vdlist.size(); ++ptr){
		if (vdlist.at(ptr).isEmpty()){
			numvec[ptr].push_back({});
			continue;
		}
		QString cat;
		cat = ByteArrayToHexstring(vdlist.at(ptr));
		QStringList mouse;
		unsigned err = 0;
		for (int i = 0; i < cat.length();){
			if (i == cat.length() - 4 && cat[i] == '0'){
				mouse << cat.mid(i + 1);
				i += 4;
			}
			if (i <= cat.length() - 4){
				if (cat[i] == '0'&&cat[i + 4] == '0'){
					mouse << cat.mid(i + 1, 3);
					i += 4;
				}
				else{
					qDebug() << "-----------Bad times occurs------------ " << "in cat[" << i << "]";
					qDebug() << cat;
					qDebug() << cat.mid(i, 4);
					++i;
				}
			}
			else
				++i;
		}
		qDebug() << "mouse :" << mouse;
		vector<int> vlg;
		for (int i = 0; i < mouse.length(); ++i){
			string bit = mouse.at(i).toStdString();
			string bit2 = hexto2bit(bit);
			bitset<12> bitvec(std::stoul(bit, 0, 16));
			int lg;
			int ulg = std::stoul(bit2.substr(1), 0, 2);
			if (bitvec[11])
				lg = -(2048 - ulg);	//负数取反加一.
			else
				lg = ulg;
			vlg.push_back(lg / 10);
		}
		numvec[ptr].insert(numvec[ptr].end(), vlg.begin(), vlg.end());
		for (const auto &a : numvec[ptr])
			qDebug() << "a is " << a;
	}
}

unsigned long solvedata::substr2bit(QString src, int index1, int index2){
	string bit2 = hexto2bit(src.toStdString());
	return std::stoul(bit2.substr(index1, index2 - index1 + 1), 0, 2);
}

void solvedata::saveIn_vec_que(vector<int> &tail_vec, int k)
{
	int dsize = vec_que_points[k].size();
	vec_que_points[k].insert(vec_que_points[k].end(), tail_vec.begin(),
		tail_vec.end());
	if (dsize <= REC_WID){
		qDebug() << "que insert size" << vec_que_points[k].size();
	}
	else
	{
		int overpnum = vec_que_points[k].size() - REC_WID;
		qDebug() << "overnum :" << QString::number(overpnum);
		auto quebegin = vec_que_points[k].begin();
		quebegin = vec_que_points[k].erase(quebegin, quebegin + overpnum);
		qDebug() << "after erase que_points size :" << QString::number(vec_que_points[k].size());
		if (vec_que_points[k].size() != REC_WID)
		{
			qDebug() << "wrong size after erase!";
			return;
		}
	}
	tail_vec.clear();
	dataShare = "";
}

QString solvedata::ByteArrayToHexstring(QByteArray str)
{
	QString HexStr;
	char *strdata = str.data();
	int strlength = str.size();
	for (int i = 0; i != strlength; ++i)
	{
		//qsnprintf(a, sizeof(inByte), "%0x", inByte);
		unsigned char rebyte = unsigned char(*(strdata + i));
		QString strtmp = QString::number(rebyte, 16);
		if (1 == strtmp.count()){
			strtmp.push_front("0");
		}

		HexStr.append(strtmp);
	}
	return HexStr.toUpper();
}

void solvedata::saveShowData(QWidget *widget)
{

}

string solvedata::hexto2bit(string hex)
{
	int vnum;
	char str_2[20] = "";
	for (char c : hex){
		char a[2] = { c };
		vnum = std::stoi(a, 0, 16);
		char s1[10] = "";
		_itoa(vnum, s1, 2);
		string s4 = string(s1);
		while (s4.length() < 4)
			s4.insert(s4.cbegin(), '0');
		strcpy(s1, s4.c_str());
		strcat(str_2, s1);
	}
	hex = string(str_2);
	return hex;
}

void solvedata::setpal(QMap<QString, QString>& pal)
{
	for (auto iter = pal.cbegin(); iter != pal.cend(); ++iter)
	{
		g_pal.insert(iter.key().toInt(), iter.value().toDouble());
	}
	//g_pal = pal;
}