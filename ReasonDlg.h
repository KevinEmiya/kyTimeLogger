#ifndef REASONDLG_H
#define REASONDLG_H

#include <QDialog>
#include <QString>

namespace Ui {
class ReasonDlg;
}

class ReasonDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ReasonDlg(QWidget *parent = 0);
    ~ReasonDlg();

signals:
    void reasonCommitted(QString reason);

private slots:
    void onBtnOk();
    void onBtnCancel();

private:
    Ui::ReasonDlg *ui;
};

#endif // REASONDLG_H
