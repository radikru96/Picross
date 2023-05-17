#ifndef PICROSS_H
#define PICROSS_H
#include "DataField.h"
#include "BrickField.h"
#include <string>

class Picross {
private:
    Field &field;
    DataField &dataField;
    BrickField &brickField;
    std::string debug;
    bool check();
    bool buildBlock( const uint &_width, const uint &_index, const uint &_begin );
    bool clear( const uint &_width, const uint &_begin, const uint &_end, const Color &_color );
    bool brickEqualData();
public:
    Picross( Field &_field, DataField &_dataField, BrickField &_brickField );
    ~Picross();
    bool start();
    void tabPrint();
};

#endif
