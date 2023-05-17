#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QScrollArea>
#include <QTableWidgetItem>
#include <QFont>
#include "Field.h"
#include "BrickField.h"
#include "DataField.h"
#include "Picross.h"

struct cursors{uint cursData = 0, cursBrick = 0, cursDataIndex = 0, cursBrickIndex;};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *e) override;

public:
    MainWindow(QWidget *parent = nullptr);
    void setXY(const uint &_x, const uint &_y);
    ~MainWindow();

private slots:
private:
    Ui::MainWindow *ui;
    Field *field;
    DataField *dataField;
    BrickField *brickField;
    Picross *picross;
    uint *brickFieldSizes;
    uint *dataFieldSizes;
    uint x=0,y=0;
    bool isBrickField = false,endPhase = false;
    QWidget *mainWidget;
    QScrollArea *scrollArea;
    void printScreen();
    void fillTables(const bool &createField);
    void resizeWindow();
    void keyArrowBrickValues(QKeyEvent &e, uint &cursBrick, uint &cursBrickIndex);
    void keyArrowDataValues(QKeyEvent &e, uint &cursData, uint &cursDataIndex);
    void keyArrowBrick(QKeyEvent &e, uint &cursBrick);
    void keyArrowData(QKeyEvent &e, uint &cursData);
    void keyPlusMinus(QKeyEvent &e, DataTable &_field, uint &_curs, uint &_index );
    void keyPlusMinusEnd(QKeyEvent &e, BrickField &_brickField, uint &_curs, uint &_index );
    void keyAny(QKeyEvent &e,cursors &curs);
    bool brickEqualData();
    QFont fontBig,fontSmall;
};
#endif // MAINWINDOW_H
