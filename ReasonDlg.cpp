#include "ReasonDlg.h"
#include "ui_ReasonDlg.h"
#include <QMessageBox>

ReasonDlg::ReasonDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReasonDlg)
{
    ui->setupUi(this);
    connect(ui->btnOk, SIGNAL(clicked(bool)), this, SLOT(onBtnOk()));
    connect(ui->btnCancel, SIGNAL(clicked(bool)), this, SLOT(onBtnCancel()));
}

ReasonDlg::~ReasonDlg()
{
    delete ui;
}

void ReasonDlg::onBtnOk()
{
    if(ui->lineEditReason->text().isEmpty())
    {
        QMessageBox::warning(this, "错误", "请输入终端原因！");
        return;
    }
    emit reasonCommitted(ui->lineEditReason->text());
    hide();
}

void ReasonDlg::onBtnCancel()
{
    hide();
}
