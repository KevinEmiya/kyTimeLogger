#ifndef MAINDLG_H
#define MAINDLG_H

#include <QDialog>
#include <QTimer>

#include "Configuration.h"
#include "LogStorage.h";
#include "ReasonDlg.h"

namespace Ui {
class MainDlg;
}

class MainDlg : public QDialog
{
    Q_OBJECT

public:
    explicit MainDlg(QWidget *parent = 0);
    ~MainDlg();

private slots:
    void onBtnStart();
    void onBtnInterrupt();
    void onBtnFinish();
    void onTicker();
    void onReasonCommitted(QString reason);

private:
    Ui::MainDlg *ui;
    LogStorage* m_storage;
    Configuration* m_config;
    QTimer* m_ticker;
    QDateTime m_startTimeCache;
    ReasonDlg* m_reasonDlg;
};

#endif // MAINDLG_H
