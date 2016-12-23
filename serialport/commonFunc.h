#include "qstringlist.h"
#include "qdir.h"
#include "qwidget.h"
#include "qcoreapplication.h"
#include "qmessagebox.h"
#include <vector>
using namespace std;
class commonFunc
{
public:
	commonFunc();
	~commonFunc();
	static void grabwindow(QWidget *wid,QString prex);
	static void saveShowData(QWidget *, QString, vector<vector<int>>);
};
