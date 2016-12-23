#include "autosend.h"
#include "qmessagebox.h"

autosend::autosend(QWidget *parent) :
QWidget(parent),
ui(new Ui::autosend_ui)
{
	ui->setupUi(this);
}

autosend::autosend(Comm *m_comm, QWidget *parent):
QWidget(parent),
ui(new Ui::autosend_ui)
{
	ui->setupUi(this);
	this->m_comm = m_comm;
	timeid = 0;
	interval = 500;
	busy = false;
	ui->spinBox->setRange(0, 16000);
	ui->spinBox->setValue(500);
	ui->autosendtxt->setEnabled(true);
	connect(ui->autoset, SIGNAL(clicked()), this, SLOT(autosendset()));
	connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(intervalset(int)));
}

autosend::~autosend()
{
	killTimer(timeid);
	delete ui;
	//if (m_comm!=NULL)
		//delete m_comm;	
}
void autosend::autosendset()
{
	if (!busy){
		if (ui->autosendtxt->toPlainText() == "")
		{
			QMessageBox::warning(this, tr("Empty"), tr("Autosend text can't be empty!"));
			return;
		}
		timeid = startTimer(interval);
		ui->spinBox->setEnabled(false);
		ui->autoset->setText(tr("&stop"));
		ui->autosendtxt->setEnabled(false);
		busy = true;
	}
	else{
		killTimer(timeid);
		ui->spinBox->setEnabled(true);
		ui->autoset->setText(tr("&send"));
		ui->autosendtxt->setEnabled(true);
		busy = false;
	}
}

int autosend::gettimeid() const
{
	return timeid;
}
void autosend::timerEvent(QTimerEvent *mevent)
{
	char *data = "";
	QByteArray ba = ui->autosendtxt->toPlainText().toLatin1();
	data = ba.data();
	autosendbytes=m_comm->writeData(data,ba.length());
	qDebug() << "autosend bytes: "+QString::number(autosendbytes);
	qDebug() << "autosend  data: " + QString(data);
	if (autosendbytes < 0)
		return;
	emit correspondUi(autosendbytes);
}

void autosend::closeEvent(QCloseEvent *closeevent)
{
	killTimer(timeid);
	this->close();
	//delete this->m_comm;
}

void autosend::intervalset(int newValue)
{
	//interval = ui->spinBox->value();
	interval = newValue;
	//QMessageBox::warning(this, tr("update value"), QString::number(interval));
}

void autosend::changeEvent(QEvent *e)
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

void autosend::resetUi()
{
	ui->spinBox->setEnabled(true);
	ui->autoset->setText(tr("&send"));
	ui->autosendtxt->setEnabled(true);
	ui->autosendtxt->clear();
	ui->spinBox->setValue(500);
	busy = false;
}