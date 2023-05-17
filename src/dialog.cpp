#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

void Dialog::insertWindow(MainWindow *parent)
{
    mw = parent;
}

Dialog::~Dialog()
{
    mw=nullptr;
    delete ui;
}

void Dialog::on_spinBoxX_valueChanged(int arg1)
{
    x = arg1;
}


void Dialog::on_spinBoxY_valueChanged(int arg1)
{
    y = arg1;
}


void Dialog::on_buttonBox_accepted()
{
    if ( x > 0 && y > 0 )
    {
        mw->show();
        mw->setXY(x,y);
    }
}

