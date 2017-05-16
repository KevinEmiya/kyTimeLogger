#include "MainDlg.h"
#include "ui_MainDlg.h"

#include <QMessageBox>

MainDlg::MainDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDlg)
{
    ui->setupUi(this);
    m_config = new Configuration();
    m_storage = new LogStorage(m_config->mysqlConf());
    m_ticker = new QTimer(this);

    connect(ui->btnStart, SIGNAL(clicked(bool)), this, SLOT(onBtnStart()));
    connect(ui->btnFinish, SIGNAL(clicked(bool)), this, SLOT(onBtnFinish()));
    connect(ui->btnInterrupt, SIGNAL(clicked(bool)), this, SLOT(onBtnInterrupt()));

    ui->labelTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    connect(m_ticker, SIGNAL(timeout()), this, SLOT(onTicker()));
    m_ticker->start(1000);
    ui->btnFinish->setEnabled(false);
    ui->btnInterrupt->setEnabled(false);

    m_reasonDlg = new ReasonDlg(this);
    m_reasonDlg->hide();
    connect(m_reasonDlg, SIGNAL(reasonCommitted(QString)), this, SLOT(onReasonCommitted(QString)));
}

MainDlg::~MainDlg()
{
    delete ui;
    if(m_config != NULL)
    {
        delete m_config;
        m_config = NULL;
    }
    if(m_storage != NULL)
    {
        delete m_storage;
        m_storage = NULL;
    }
}

void MainDlg::onBtnStart()
{
    if(ui->lineEditDesc->text().isEmpty())
    {
        QMessageBox::warning(this, "错误", "请输入任务描述！");
        return;
    }
    m_startTimeCache = QDateTime::currentDateTime();
    ui->btnFinish->setEnabled(true);
    ui->btnInterrupt->setEnabled(true);
    ui->btnStart->setEnabled(false);
}

void MainDlg::onBtnInterrupt()
{
    m_reasonDlg->show();
}

void MainDlg::onBtnFinish()
{
    ui->btnFinish->setEnabled(false);
    ui->btnInterrupt->setEnabled(false);
    ui->btnStart->setEnabled(true);
    m_storage->writeToStorage(ui->lineEditDesc->text(), m_startTimeCache, QDateTime::currentDateTime());
}

void MainDlg::onTicker()
{
    ui->labelTime->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
}

void MainDlg::onReasonCommitted(QString reason)
{
    ui->btnFinish->setEnabled(false);
    ui->btnInterrupt->setEnabled(false);
    ui->btnStart->setEnabled(true);
    m_storage->writeToStorage(ui->lineEditDesc->text(), m_startTimeCache, QDateTime::currentDateTime(), "Interrupt", reason);
}
