#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    MainWindow *mw;
    uint x=0,y=0;

public:
    explicit Dialog(QWidget *parent = nullptr);
    void insertWindow(MainWindow *parent);
    ~Dialog();

private slots:
    void on_spinBoxX_valueChanged(int arg1);

    void on_spinBoxY_valueChanged(int arg1);

    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
