#ifndef SOLVEDATA_H
#define SOLVEDATA_H
#include "qobject.h"
#include <vector>
#include <deque>
#include "qmap.h"
using namespace std;

class solvedata : public QObject
{
	Q_OBJECT
public:
	solvedata(QObject *parent = 0);
	~solvedata();
	void processEightdata();
	unsigned long substr2bit(QString src, int index1, int index2);
	QString ByteArrayToHexstring(QByteArray str);
	string hexto2bit(string);
	void saveIn_vec_que(vector<int> &, int);
	void deal_valid_data(QByteArrayList);
	vector<int> deal_valid_data(const QByteArray&);

private:
	bool restFlag;
	QByteArray restData;
	vector<int> vec_points;
	vector<vector<int>> numvec = { 5, {} };
	vector<vector<int>> vec_vec = { 5, {} };
	vector<deque<int>> vec_que_points = { 5, {} };
	vector<int> vd_vec;
	quint16 frequency0 = 0, last_fre = 65535;
	double eff[5];
	quint16 THE_PAL[5];
	quint16 vpp[5];
	map<int, vector<double>> effmap0, effmap1, effmap2, effmap3, effmap4;
	QMap<int,double> g_pal;

	double getEff(const vector<double>&);
	int getVpp(const vector<double> &);
	void calcl_eff_vpp(quint16, quint16, const QByteArray&);
	vector<double> toPalData(vector<int>&, int);

	public slots:
	void testdata();
	void processSharedata();
	void saveShowData(QWidget *widget);
	void setpal(QMap<QString, QString>&);

signals:
	void sendSVdata(vector<deque<int>>, int, vector<int>, vector<double>, vector<vector<int>>);
	private slots:
	
};
#endif