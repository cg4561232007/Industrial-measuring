#ifndef AESOB_H
#define AESOB_H

#include "qobject.h"
#include <deque>
#include <vector>
#include "qdir.h"
using std::deque;
using std::vector;

#define ROUND 10//��������Ϊ12(����10,14���ֱ��Ӧ��128,192,256λ��Կ)
#define NK 4//��Կ���ȱ�����
#define NR 4//������Կ������ÿ���ĸ��ֽڴ�С

typedef  unsigned  char  SBOX[16][16];
typedef  unsigned  char  WBOX[NK * (ROUND + 1)][4];
typedef  unsigned  char  STATE[4][4];
typedef  unsigned  char  RCON[11][4];
typedef  unsigned  char  BYTE;
typedef  unsigned  char  TEMP[4];
typedef  unsigned  char  IN[16];

class aesob :public QObject{
	Q_OBJECT
public:
	explicit aesob(QObject *parent = 0);
	~aesob();
	QString getFilename(QDir,QString);
	void saveCipher(vector<BYTE>,QString);

private:
	deque<int> cipherText;
	unsigned char(*sbox)[16];
	unsigned char(*isbox)[16];
	//AES FUNCTIONS,��˽�еĺ��������ṩ�ⲿ�ӿ�
	void keyExpansion();
	void initialSbox();
	void generateW();
	void rotWord(TEMP);
	void subWord(unsigned char(*)[16], TEMP);
	void makeXor(int, TEMP);
	void encrypTion(STATE);
	void addRoundKey(STATE, int);
	void mixColums(STATE);
	void shiftRow(STATE);
	void subByte(STATE);
	void invCipher(STATE);//����ֵΪ�ַ��ͺ������ö����������
	void initialIsbox();
	void invAddRoundKey(STATE,int);
	void invMixColumns(STATE);
	void invShiftRow(STATE);
	void invSubByte(STATE);
	BYTE gfmulti0b(BYTE);
	BYTE gfmulti01(BYTE);
	BYTE gfmulti02(BYTE);
	BYTE gfmulti03(BYTE);
	BYTE gfmulti0d(BYTE);
	BYTE gfmulti0e(BYTE);
	BYTE gfmulti09(BYTE);

	public slots :
		void encrypt(vector<BYTE>);
		void decrypt(vector<BYTE>);

	signals:
		void sendprogress(int);
};
#endif