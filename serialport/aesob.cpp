#include "aesob.h"
#include "qmetatype.h"
#include "qthread.h"
#include "qdebug.h"
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include "qfile.h"
#include "qdir.h"
#include "qcoreapplication.h"

WBOX w = { 0x0f,0x15,0x71,0xc9,
		   0x47,0xd9,0xe8,0x59,
		   0x0c,0xb7,0xad,0xd6,
		   0xaf,0x7f,0x67,0x98};
RCON rcon = { { 0x00, 0x00, 0x00, 0x00 },
{ 0x01, 0x00, 0x00, 0x00 },
{ 0x02, 0x00, 0x00, 0x00 },
{ 0x04, 0x00, 0x00, 0x00 },
{ 0x08, 0x00, 0x00, 0x00 },
{ 0x10, 0x00, 0x00, 0x00 },
{ 0x20, 0x00, 0x00, 0x00 },
{ 0x40, 0x00, 0x00, 0x00 },
{ 0x80, 0x00, 0x00, 0x00 },
{ 0x1b, 0x00, 0x00, 0x00 },
{ 0x36, 0x00, 0x00, 0x00 } };

aesob::aesob(QObject *parent):
QObject(parent)
{
	qRegisterMetaType<vector<BYTE>>("vector<BYTE>");
}

aesob::~aesob()
{

}

void aesob::encrypt(vector<BYTE> clearText)
{
	//对clearText进行加密 写入cipherText中去
	//AES加密开始
	qDebug() << "---AESOB---"<<"AES thread is running in :" << QThread::currentThread();
	initialSbox();
	keyExpansion();
	/*
	**	依次读取vector中的明文到STATE数组中
	*/
	STATE state;
	vector<BYTE> cipherByte;

	int i = 0, j;
	int clearsize = clearText.size();
	while (i <clearsize){
		if (i == clearsize - 4*NK)
			emit sendprogress(i);
		if (i%(400*NK)==0)
			emit sendprogress(i);
		for (j=0; j < 4 * NK; ++j){
			state[j % 4][j / 4] = clearText[i+j];	
		}
		i += 4 * NK;
		encrypTion(state);
		printf("密文是：\n");
		for (int k = 0; k < 4; k++){
			for (int l = 0; l < 4; l++){
				cipherByte.push_back(state[l][k]);
				//printf("0x%0x ", state[l][k]);
			}
			//printf("\n");
		}
	}
	saveCipher(cipherByte,"cipher");
}

void aesob::saveCipher(vector<BYTE> cipherByte,QString ct)
{
	QFile file;
	QDir dir;
	QStringList filters;
	filters << "*.txt" << "*.cpp";
	dir.setNameFilters(filters);
	dir.setCurrent(QCoreApplication::applicationDirPath());
	QFileInfo sub("./"+ct);
	QString dirstr = ct+"Text";
	if (!sub.exists())
		dir.mkdir(dirstr);
	dir.cd(dirstr);
	file.setFileName(dir.filePath(getFilename(dir,ct)));
	qDebug() << "file's absolutly path is: " + file.fileName();

	QString  tmpstr;
	for (int i = 0; i < cipherByte.size(); ++i){
		//tmpstr.append("0x" + QString::number(cipherByte[i], 16));
		tmpstr.append(QString::number(cipherByte[i], 16));
		tmpstr.append(" ");
		if (i % 16 == 15)
			tmpstr.append("\n");
	}

	if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){	//write,append,txt
		QTextStream stream(&file);
		stream << tmpstr;
		stream.atEnd();
		file.close();
	}
	else
		qDebug() << "opening local file error!" << endl;
}

QString aesob::getFilename(QDir dir,QString txt)
{
	QStringList currentFiles = dir.entryList(QDir::Files, QDir::Name);
	QStringList pointfile;
	for each(QString name in currentFiles){
		if (name.contains(txt))
			pointfile.push_back(name);
	}
	std::stable_sort(pointfile.begin(), pointfile.end(),
		[](const QString &s1, const QString &s2){return s1.size() < s2.size(); });
	int plen = pointfile.size();
	int nlen;
	int ppos;
	QString lst;
	if (plen > 0){
		nlen = pointfile.at(plen - 1).size();
		lst = pointfile.at(plen - 1);
		ppos = lst.indexOf(".");
	}
	QString fileName;
	if (plen == 0)
		fileName = txt+".txt";
	else if (lst.at(ppos-2).isNumber() && lst.at(ppos-1).isNumber())
	{
		int lstnumber = QString(lst.mid(ppos-2, 2)).toInt();
		fileName = txt + QString::number(lstnumber + 1) + ".txt";
	}
	else if (lst.at(ppos-1).isNumber())
	{
		int lstnumber = QString(lst.at(ppos-1)).toInt();
		fileName = txt + QString::number(lstnumber + 1) + ".txt";
	}
	else {
		fileName = txt+"1.txt";
	}
	return fileName;
}

void aesob::decrypt(vector<BYTE> cipherText)
{
	//对cipherText进行解密 写入clearText中去
	//AES解密开始
	qDebug() << "---AESOB---" << "AES thread is running in :" << QThread::currentThread();
	STATE state;
	initialSbox();	//isbox实在sbox的基础上得到的
	initialIsbox();
	vector<BYTE> invcipherByte;

	int i = 0, j;
	int ciphersize = cipherText.size();
	while (i <ciphersize){
		if (i == ciphersize - 4 * NK)
			emit sendprogress(i);
		if (i % (400 * NK) == 0)
			emit sendprogress(i);
		for (j = 0; j < 4 * NK; ++j){
			state[j % 4][j / 4] = cipherText[i + j];
		}
		i += 4 * NK;
		invCipher(state);
		printf("密文是：\n");
		for (int k = 0; k < 4; k++){
			for (int l = 0; l < 4; l++){
				invcipherByte.push_back(state[l][k]);
				printf("0x%0x ", state[l][k]);
			}
			printf("\n");
		}
	}
	saveCipher(invcipherByte,"invcipher");
}

void aesob::keyExpansion()
{
	int num = 0;
	//前面NR行填充种子密钥
	/*for (int i = 0; i < NR; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			w[i][j] = num++;
		}
	}*/
	generateW();
}

void aesob::initialSbox()
{
	//初始化sbox，输入值在0x00~0xff之间,共16行16列
	static SBOX subBox = { /*0*/{ 0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76 },
		/*1*/{ 0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0 },
		/*2*/{ 0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15 },
		/*3*/{ 0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75 },
		/*4*/{ 0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84 },
		/*5*/{ 0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf },
		/*6*/{ 0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8 },
		/*7*/{ 0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2 },
		/*8*/{ 0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73 },
		/*9*/{ 0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb },
		/*a*/{ 0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79 },
		/*b*/{ 0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08 },
		/*c*/{ 0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a },
		/*d*/{ 0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e },
		/*e*/{ 0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf },
		/*f*/{ 0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }
	};
	sbox = subBox;
}

void aesob::generateW()
{
	//*a指向sbox
	for (int i = NR; i < NK * (ROUND + 1); i++)
	{
		TEMP temp;
		for (int j = 0; j < 4; j++)
		{
			temp[j] = w[i - 1][j];
		}
		if (i%NR == 0){
			rotWord(temp);//行左移
			subWord(sbox, temp);//替换
			makeXor(i, temp);//异或操作
		}
		else if ((NR == 8) && (i%NR == 4))
		{
			subWord(sbox, temp);
		}
		for (int j = 0; j < 4; j++)
		{
			w[i][j] = temp[j] ^ w[i - NR][j];
		}	//最后与前NR行做异或   
	}
	printf("加密所用的密钥调度表为：\n");
	for (int i = 0; i < NK * (ROUND + 1); i++){
		for (int j = 0; j < 4; j++){
			printf("0x%0x ", w[i][j]);
		}
		printf("\n");	//产生的w调度表
	}
}

void aesob::rotWord(TEMP temp)
{
	int tmp = temp[0];
	for (int j = 0; j < 4; j++)
	{
		if (j < 3)
		{
			temp[j] = temp[j + 1];
		}
		else
		{
			temp[j] = tmp;
		}
	}
}

void aesob::subWord(unsigned char(*a)[16], TEMP temp)
{
	for (int j = 0; j < 4; j++)
	{	//在sbox中查找到相应密钥并替换
		int low = temp[j] & 0x0f;
		int high = temp[j] >> 4;
		temp[j] = a[high][low];
	}
}

void aesob::makeXor(int i, TEMP temp)
{
	for (int j = 0; j < 4; j++)
	{
		temp[j] = temp[j] ^ rcon[(i) / NR][j];
	}
}

void aesob::encrypTion(STATE state)
{
	addRoundKey(state, 0);
	for (int n = 1; n< ROUND; n++)//第一轮至第倒数第二轮加密,加密过程中指向state数组的指针不变
	{
		subByte(state);
		shiftRow(state);
		mixColums(state);
		addRoundKey(state, n);
	}
	subByte(state);
	shiftRow(state);
	addRoundKey(state, ROUND);
}

void aesob::subByte(STATE state)
{
	int low;
	int high;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			low = (int)(state[i][j] & 0x0f);
			high = (int)(state[i][j] >> 4);
			state[i][j] = sbox[high][low];
		}
	}
}

void aesob::shiftRow(STATE state)
{
	//temp数组存放state
	STATE temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[i][j] = state[i][j];
		}
	}
	//左移
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			state[i][j] = temp[i][(i + j) % NK];
		}
	}
}

void aesob::addRoundKey(STATE state, int n)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			state[i][j] = state[i][j] ^ w[4 * n + j][i];
		}
	}
}

void aesob::mixColums(STATE state)
{
	//temp数组存放state
	STATE temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[i][j] = state[i][j];
		}
	}
	for (int j = 0; j < 4; j++)
	{	//加密核心算法，这里是正确的。
		state[0][j] = (BYTE)((int)gfmulti02(temp[0][j]) ^ (int)gfmulti03(temp[1][j]) ^ (int)gfmulti01(temp[2][j]) ^ (int)gfmulti01(temp[3][j]));
		state[1][j] = (BYTE)((int)gfmulti01(temp[0][j]) ^ (int)gfmulti02(temp[1][j]) ^ (int)gfmulti03(temp[2][j]) ^ (int)gfmulti01(temp[3][j]));
		state[2][j] = (BYTE)((int)gfmulti01(temp[0][j]) ^ (int)gfmulti01(temp[1][j]) ^ (int)gfmulti02(temp[2][j]) ^ (int)gfmulti03(temp[3][j]));
		state[3][j] = (BYTE)((int)gfmulti03(temp[0][j]) ^ (int)gfmulti01(temp[1][j]) ^ (int)gfmulti01(temp[2][j]) ^ (int)gfmulti02(temp[3][j]));
	}
}

BYTE aesob::gfmulti01(BYTE byte)
{
	return byte;
}

BYTE aesob::gfmulti02(BYTE byte)
{
	if (byte < 0x80)
		return (BYTE)(int)(byte << 1);
	else
		return (BYTE)((int)(byte << 1) ^ (int)(0x1b));
	//return (byte > 0x80) ? (BYTE)((int)(byte << 1)^(int)0x1b) : (BYTE)(int)(byte << 1);
}

BYTE aesob::gfmulti03(BYTE byte)
{
	return (BYTE)((int)gfmulti02(byte) ^ (int)byte);
}

BYTE aesob::gfmulti0e(BYTE byte)
{
	return (BYTE)((int)gfmulti02(gfmulti02(gfmulti02(byte))) ^ (int)gfmulti02(gfmulti02(byte)) ^ (int)gfmulti02(byte));
}

BYTE aesob::gfmulti0b(BYTE byte)
{
	return (BYTE)((int)gfmulti02(gfmulti02(gfmulti02(byte))) ^ (int)gfmulti02(byte) ^ (int)byte);
}

BYTE aesob::gfmulti0d(BYTE byte)
{
	return (BYTE)((int)gfmulti02(gfmulti02(gfmulti02(byte))) ^ (int)gfmulti02(gfmulti02(byte)) ^ (int)byte);
}

BYTE aesob::gfmulti09(BYTE byte)
{
	return (BYTE)((int)gfmulti02(gfmulti02(gfmulti02(byte))) ^ (int)byte);
}

void aesob::invCipher(STATE state)
{
	addRoundKey(state, ROUND);//第0轮与密钥调度表最后四行进行异或运算
	//invAddRoundKey(state, 0);
	for (int n = ROUND - 1; n > 0; n--)
	{
		invShiftRow(state);
		invSubByte(state);
		addRoundKey(state, n);//这里与加密过程相比先进行异或运算
		invMixColumns(state);
	}
	invShiftRow(state);
	invSubByte(state);
	addRoundKey(state, 0);
}

void aesob::initialIsbox()
{
	//利用sbox得到isbox
	/*static SBOX	isubSbox = {
	{ 0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb },
	{ 0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb },
	{ 0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e },
	{ 0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25 },
	{ 0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92 },
	{ 0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84 },
	{ 0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06 },
	{ 0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b },
	{ 0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73 },
	{ 0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e },
	{ 0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b },
	{ 0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4 },
	{ 0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f },
	{ 0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef },
	{ 0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61 },
	{ 0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d } }; */
	static SBOX isubSbox;
	int low;
	int high;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			low = (int)(sbox[i][j] & 0x0f);
			high = (int)(sbox[i][j] >> 4);
			isubSbox[high][low] = (BYTE)(i * 16 + j);
		}
	}
	sbox = isubSbox;//全局变量指针sbox重新指向数组isubsbox[16][16]
}

void aesob::invSubByte(STATE state)
{
	int low = 0;
	int high = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			low = (int)(state[i][j] & 0x0f);
			high = (int)(state[i][j] >> 4);
			state[i][j] = sbox[high][low];
		}
	}
}

void aesob::invShiftRow(STATE state)
{
	//temp数组存放state没有移位时的数据
	STATE temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[i][j] = state[i][j];
		}
	}
	//右移
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			state[i][(i + j) % NK] = temp[i][j];
		}
	}
}

void aesob::invMixColumns(STATE state)
{
	//temp数组存放state
	STATE temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[i][j] = state[i][j];
		}
	}
	for (int j = 0; j < 4; j++)
	{	//解密核心算法
		state[0][j] = (BYTE)((int)gfmulti0e(temp[0][j]) ^ (int)gfmulti0b(temp[1][j]) ^ (int)gfmulti0d(temp[2][j]) ^ (int)gfmulti09(temp[3][j]));
		state[1][j] = (BYTE)((int)gfmulti09(temp[0][j]) ^ (int)gfmulti0e(temp[1][j]) ^ (int)gfmulti0b(temp[2][j]) ^ (int)gfmulti0d(temp[3][j]));
		state[2][j] = (BYTE)((int)gfmulti0d(temp[0][j]) ^ (int)gfmulti09(temp[1][j]) ^ (int)gfmulti0e(temp[2][j]) ^ (int)gfmulti0b(temp[3][j]));
		state[3][j] = (BYTE)((int)gfmulti0b(temp[0][j]) ^ (int)gfmulti0d(temp[1][j]) ^ (int)gfmulti09(temp[2][j]) ^ (int)gfmulti0e(temp[3][j]));
	}
}

void aesob::invAddRoundKey(STATE state, int n)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			state[i][j] = state[i][j] ^ w[51 - 4 * n - j][i];
		}
	}
}
