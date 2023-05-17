#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    static struct cursors curs;
    if ( brickField == nullptr && dataField == nullptr ) {
        if (isBrickField)
            keyArrowBrick(*e,curs.cursBrick);
        else
            keyArrowData(*e,curs.cursData);
    }
    else {
        if (endPhase || isBrickField){
            if (endPhase) keyPlusMinusEnd(*e,*brickField,curs.cursBrick,curs.cursBrickIndex);
            else keyPlusMinus(*e,*brickField,curs.cursBrick,curs.cursBrickIndex);
            keyArrowBrickValues(*e,curs.cursBrick,curs.cursBrickIndex); }
        else{
            keyPlusMinus(*e,*dataField,curs.cursData,curs.cursDataIndex);
            keyArrowDataValues(*e,curs.cursData,curs.cursDataIndex); }
    }
    if (!endPhase)
        keyAny(*e,curs);
    printScreen();
}

void MainWindow::keyAny(QKeyEvent &e,cursors &curs){
    switch (e.key()){
    case Qt::Key_Tab:
        if (isBrickField)
            ui->qBrickField->item(curs.cursBrick,curs.cursBrickIndex)->setData(Qt::BackgroundRole,QVariant());
        else
            ui->qDataField->item(curs.cursDataIndex,curs.cursData)->setData(Qt::BackgroundRole,QVariant());
        isBrickField = !isBrickField;
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        if ( brickField == nullptr && dataField == nullptr ){
            brickField = new BrickField( *field, y, brickFieldSizes );
            dataField = new DataField( *field, x, dataFieldSizes );
            ui->qDataField->clear();
            ui->qBrickField->clear();
            ui->qDataField->setRowCount(dataField->getShift());
            ui->qBrickField->setColumnCount(brickField->getShift());
            resizeWindow();
            fillTables(false);
            break;
        }
        else if (brickEqualData() && brickField->startPos()) {
            picross = new Picross( *field, *dataField, *brickField );
            picross->start();
            endPhase = true;
        }
    }
    if (isBrickField)
        ui->qBrickField->item(curs.cursBrick,curs.cursBrickIndex)->setData(Qt::BackgroundRole,QVariant(QBrush(Qt::darkGray)));
    else
        ui->qDataField->item(curs.cursDataIndex,curs.cursData)->setData(Qt::BackgroundRole,QVariant(QBrush(Qt::darkGray)));
}

bool MainWindow::brickEqualData(){
    uint bufData = 0, bufBrick = 0;
    for ( uint i = 0; i < x; i++ )
        for ( uint j = 0; j < dataField->getSize(i); j++ )
            bufData += dataField->getData(i,j).getSize();
    for ( uint i = 0; i < y; i++ )
        for ( uint j = 0; j < brickField->getSize(i); j++ )
            bufBrick += brickField->getData(i,j).getSize();
    return bufData == bufBrick;
}

void MainWindow::keyArrowBrickValues(QKeyEvent &e, uint &cursBrick, uint &cursBrickIndex){
    ui->qBrickField->item(cursBrick,cursBrickIndex)->setData(Qt::BackgroundRole,QVariant());
    switch (e.key()) {
    case Qt::Key_Up:
        if(cursBrick>0){
            cursBrick--; cursBrickIndex=0; }
        break;
    case Qt::Key_Down:
        if(cursBrick<y-1){
            cursBrick++; cursBrickIndex=0; }
        break;
    case Qt::Key_Right:
        if(cursBrickIndex<brickField->getSize(cursBrick)-1)
            cursBrickIndex++;
        break;
    case Qt::Key_Left:
        if(cursBrickIndex>0)
            cursBrickIndex--;
        break;
    }
    ui->qBrickField->item(cursBrick,cursBrickIndex)->setData(Qt::BackgroundRole,QVariant(QBrush(Qt::darkGray)));
}

void MainWindow::keyArrowDataValues(QKeyEvent &e, uint &cursData, uint &cursDataIndex){
    ui->qDataField->item(cursDataIndex,cursData)->setData(Qt::BackgroundRole,QVariant());
    switch (e.key()) {
    case Qt::Key_Left:
        if(cursData>0){
            cursData--; cursDataIndex=0; }
        break;
    case Qt::Key_Right:
        if(cursData<y-1){
            cursData++; cursDataIndex=0; }
        break;
    case Qt::Key_Down:
        if(cursDataIndex<dataField->getSize(cursData)-1)
            cursDataIndex++;
        break;
    case Qt::Key_Up:
        if(cursDataIndex>0)
            cursDataIndex--;
        break;
    }
    ui->qDataField->item(cursDataIndex,cursData)->setData(Qt::BackgroundRole,QVariant(QBrush(Qt::darkGray)));
}

void MainWindow::keyArrowBrick(QKeyEvent &e, uint &cursBrick){
    if ( e.key() == Qt::Key_Up || e.key() == Qt::Key_Down ) {
        ui->qBrickField->item(cursBrick,0)->setData(Qt::BackgroundRole,QVariant());
        if(e.key() == Qt::Key_Up && cursBrick>0)
            cursBrick--;
        else if(cursBrick<y-1)
            cursBrick++;
        ui->qBrickField->item(cursBrick,0)->setData(Qt::BackgroundRole,QVariant(QBrush(Qt::darkGray)));
    }
    else if(e.key() == Qt::Key_Right && brickFieldSizes[cursBrick]<x/2+(x%2)){
        brickFieldSizes[cursBrick]++;
        if ( brickFieldSizes[cursBrick]>9 && ui->qBrickField->item(cursBrick,0)->font().pointSize() > 6)
            ui->qBrickField->item(cursBrick,0)->setFont(fontSmall);
    }
    else if(e.key() == Qt::Key_Left && brickFieldSizes[cursBrick]>0){
        brickFieldSizes[cursBrick]--;
        if ( brickFieldSizes[cursBrick]<10 && ui->qBrickField->item(cursBrick,0)->font().pointSize() < 12)
            ui->qBrickField->item(cursBrick,0)->setFont(fontBig);
    }
    else if(e.key() > Qt::Key_0 && e.key() < Qt::Key_Colon)
        brickFieldSizes[cursBrick] = e.key() - Qt::Key_0;
}

void MainWindow::keyArrowData(QKeyEvent &e, uint &cursData){
    if ( e.key() == Qt::Key_Right || e.key() == Qt::Key_Left ) {
        ui->qDataField->item(0,cursData)->setData(Qt::BackgroundRole,QVariant());
        if(e.key() == Qt::Key_Right && cursData<x-1)
            cursData++;
        else if(cursData>0)
            cursData--;
        ui->qDataField->item(0,cursData)->setData(Qt::BackgroundRole,QVariant(QBrush(Qt::darkGray)));
    }
    else if(e.key() == Qt::Key_Up && dataFieldSizes[cursData]<y/2+(y%2))
        dataFieldSizes[cursData]++;
    else if(e.key() == Qt::Key_Down && dataFieldSizes[cursData]>0)
        dataFieldSizes[cursData]--;
    else if(e.key() > Qt::Key_0 && e.key() < Qt::Key_Colon)
        dataFieldSizes[cursData] = e.key() - Qt::Key_0;
    if ( dataFieldSizes[cursData]>9 && ui->qDataField->item(0,cursData)->font().pointSize() > 6)
        ui->qDataField->item(0,cursData)->setFont(fontSmall);
    else if ( dataFieldSizes[cursData]<10 && ui->qDataField->item(0,cursData)->font().pointSize() < 12)
        ui->qDataField->item(0,cursData)->setFont(fontBig);
}

void MainWindow::keyPlusMinus(QKeyEvent &e, DataTable &_field, uint &_curs, uint &_index ){
    if ( e.key() == Qt::Key_Plus ) {
        _field.getData(_curs,_index).setSize(_field.getData(_curs,_index).getSize()+1);
    }
    else if ( e.key() == Qt::Key_Minus && _field.getData(_curs,_index).getSize() > 0) {
        _field.getData(_curs,_index).setSize(_field.getData(_curs,_index).getSize()-1);
    }
    else if (e.key() > Qt::Key_0 && e.key() < Qt::Key_Colon)
        _field.getData(_curs,_index).setSize( e.key() - Qt::Key_0 );
    if ( isBrickField ) {
        if ( _field.getData(_curs,_index).getSize() > 9 && ui->qBrickField->item(_curs,_index)->font().pointSize() > 6 )
            ui->qBrickField->item(_curs,_index)->setFont(fontSmall);
        else if ( _field.getData(_curs,_index).getSize() < 10 && ui->qBrickField->item(_curs,_index)->font().pointSize() < 12 )
            ui->qBrickField->item(_curs,_index)->setFont(fontBig);
    }
    else {
        if ( _field.getData(_curs,_index).getSize() > 9 && ui->qDataField->item(_index,_curs)->font().pointSize() > 6 )
            ui->qDataField->item(_index,_curs)->setFont(fontSmall);
        else if ( _field.getData(_curs,_index).getSize() < 10 && ui->qDataField->item(_index,_curs)->font().pointSize() < 12 )
            ui->qDataField->item(_index,_curs)->setFont(fontBig);
    }
}

void MainWindow::keyPlusMinusEnd(QKeyEvent &e, BrickField &_brickField, uint &_curs, uint &_index ){
    if ( e.key() == Qt::Key_Plus )
        _brickField.move(_curs,_index,1);
    else if ( e.key() == Qt::Key_Minus )
        _brickField.move(_curs,_index,-1);
}

void MainWindow::printScreen(){
    if ( brickField == nullptr && dataField == nullptr ) {
        for ( uint i = 0; i < ui->qBrickField->columnCount(); i++ )
            for ( uint j = 0; j < ui->qBrickField->rowCount(); j++ )
                ui->qBrickField->item( j, i)->setText( QString::number( brickFieldSizes[j] ) );
        for ( uint i = 0; i < ui->qDataField->rowCount(); i++ )
            for ( uint j = 0; j < ui->qDataField->columnCount(); j++ )
                ui->qDataField->item( i, j)->setText( QString::number( dataFieldSizes[j] ) );
    }
    else {
        for ( uint i = 0; i < ui->qBrickField->rowCount(); i++ )
            for ( uint j = 0; j < brickField->getSize(i); j++ )
                ui->qBrickField->item( i, j)->setText( QString::number( brickField->getData(i,j).getSize() ) );
        for ( uint i = 0; i < ui->qDataField->columnCount(); i++ )
            for ( uint j = 0; j < dataField->getSize(i); j++ )
                ui->qDataField->item( j, i)->setText( QString::number( dataField->getData(i,j).getSize() ) );
        for ( uint i = 0; i < x; i++ )
            for ( uint j = 0; j < y; j++ )
                ui->qField->item( j, i )->setData(Qt::BackgroundRole,QVariant(QBrush(
                            field->getColor(i,j)==Color::white?Qt::white:Qt::black)));
    }
}

void MainWindow::fillTables(const bool &createField){
    for ( uint i = 0; i < ui->qBrickField->columnCount(); i++ ){
        for ( uint j = 0; j < ui->qBrickField->rowCount(); j++ ){
            ui->qBrickField->setItem( j, i, new QTableWidgetItem() );
            ui->qBrickField->item( j, i )->setFont( fontBig ); } }
    for ( uint i = 0; i < ui->qDataField->rowCount(); i++ ){
        for ( uint j = 0; j < ui->qDataField->columnCount(); j++ ){
            ui->qDataField->setItem( i, j, new QTableWidgetItem() );
            ui->qDataField->item( i, j )->setFont( fontBig ); } }
    if (createField){
        for ( uint i = 0; i < ui->qField->rowCount(); i++ ){
            for ( uint j = 0; j < ui->qField->columnCount(); j++ ){
                ui->qField->setItem( i, j, new QTableWidgetItem() );
                ui->qField->item(i,j)->setData(Qt::BackgroundRole,QVariant(QBrush(
                        field->getColor(j,i)==Color::white?Qt::white:Qt::black))); } }
        ui->qDataField->item(0,0)->setData(Qt::BackgroundRole,QVariant(QBrush(Qt::darkGray)));
    }
    printScreen();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fontBig.setPointSize(12);
    fontSmall.setPointSize(6);
//    mainWidget = new QWidget();
//    scrollArea = new QScrollArea();
//    scrollArea->setWidget(mainWidget);
//    scrollArea->setWidgetResizable(true);
//    setCentralWidget(scrollArea);
}

void MainWindow::setXY(const uint &_x, const uint &_y)
{
    x=_x;
    y=_y;
    field = new Field(x,y);
    dataFieldSizes = new uint[x];
    brickFieldSizes = new uint[y];
    for ( uint i = 0; i < x; i++ )
        dataFieldSizes[i] = 0;
    for ( uint i = 0; i < y; i++ )
        brickFieldSizes[i] = 0;

    ui->qField->setColumnCount(x);
    ui->qField->setRowCount(y);
    ui->qDataField->setColumnCount(x);
    ui->qDataField->setRowCount(1);
    ui->qBrickField->setColumnCount(1);
    ui->qBrickField->setRowCount(y);
    resizeWindow();

    fillTables(true);
}

void MainWindow::resizeWindow(){
    resize(15*(x+ui->qBrickField->columnCount())+10,15*(y+ui->qDataField->rowCount())+10);
    ui->centralwidget->setFixedSize(15*(x+ui->qBrickField->columnCount())+10,15*(y+ui->qDataField->rowCount())+10);
    ui->qField->setGeometry((15*ui->qBrickField->columnCount())+6,(15*ui->qDataField->rowCount())+6,(15*x)+4,(15*y)+4);
    ui->qBrickField->setGeometry(0,(15*ui->qDataField->rowCount())+6,(15*ui->qBrickField->columnCount())+4,(15*ui->qBrickField->rowCount())+4);
    ui->qDataField->setGeometry((15*ui->qBrickField->columnCount())+6,0,(15*ui->qDataField->columnCount())+4,(15*ui->qDataField->rowCount())+4);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (field!=nullptr) delete field;
    if (dataField!=nullptr) delete dataField;
    if (brickField!= nullptr) delete brickField;
    if (dataFieldSizes!=nullptr) delete[] dataFieldSizes;
    if (brickFieldSizes!=nullptr) delete[] brickFieldSizes;
}
