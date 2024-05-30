#include "Picross.h"
#include <iostream>

Picross::Picross( Field &_field, DataField &_dataField, BrickField &_brickField )
                        : field(_field), dataField(_dataField), brickField(_brickField) {}

Picross::~Picross(){}

bool Picross::start() {
    if ( !brickField.startPos() || !brickEqualData() )
        return false;
    uint j = 0;
    for ( uint i = 0; i < field.getX(); ) {
        for ( ; j < dataField.getSize(i);) {
            if ( j == 0 && dataField.getData(i,j).getBegin() > 0 ) {
                if ( !clear ( i, 0, dataField.getData(i,j).getBegin()-1, dataField.getData(i,j).getColor() ) ) {
                    if ( i == 0 )
                        return false;
                    i--;
                    j = dataField.getSize(i) - 1;
                    dataField.getData(i,j).setBegin( dataField.getData(i,j).getBegin() + 1 );
                    continue;
                }
            }
            else if ( j > 0 ) {
                if ( !clear( i, dataField.getData(i,j-1).getEnd()+1, dataField.getData(i,j).getBegin()-1, dataField.getData(i,j).getColor() ) ) {
                    j--;
                    dataField.getData(i,j).setBegin( dataField.getData(i,j).getBegin() + 1 );
                    continue;
                }
            }
            if ( buildBlock( i, j, dataField.getData(i,j).getBegin() ) ) {
                j++;
                if ( j < dataField.getSize(i) )
                    dataField.getData(i,j).setBegin( dataField.getData(i,j-1).getEnd() + 2 );
                else if ( i+1 < field.getX() )
                    dataField.getData(i+1,0).setBegin(0);
            }
            else {
                if ( dataField.getData(i,j).getBegin() + dataField.getData(i,j).getSize() < field.getY() ){}
                else if ( j > 0 )
                    j--;
                else if ( i > 0 ) {
                    i--;
                    j = dataField.getSize(i) - 1;
                }
                else
                    return check();
                dataField.getData(i,j).setBegin( dataField.getData(i,j).getBegin() + 1 );
            }
        }
        if ( clear( i, dataField.getData( i, dataField.getSize(i)-1 ).getEnd()+1
                , field.getY()-1, dataField.getData( i, dataField.getSize(i)-1 ).getColor() ) ) {
            i++;
            j=0;
        }
        else {
            if ( j > 0 )
                j--;
            else if ( i > 0) {
                i--;
                j = dataField.getSize(i) - 1;
            }
            else
                return false;
            dataField.getData(i,j).setBegin( dataField.getData(i,j).getBegin() + 1 );
        }
    }
    return check();
}

bool Picross::check(){
    for (uint i = 0; i < field.getX(); i++){
        if (!dataField.check(i))
            return false;
    }
    return true;
}

bool Picross::buildBlock( const uint &_width, const uint &_index, const uint &_begin ) {
    if ( _begin + dataField.getData( _width, _index ).getSize() > field.getY() )
        return false;
    for ( uint i = 0; i < dataField.getData( _width, _index ).getSize(); i++ ){
        if ( field.getColor( _width, _begin+i ) == dataField.getData( _width, _index ).getColor() )
            continue;
        if ( _width > 0 && field.getColor( _width-1, _begin+i ) == dataField.getData( _width, _index ).getColor() )
            return false;
        for ( uint j = 0; j < brickField.getSize(_begin+i); j++ ){
            if ( brickField.getData(_begin+i,j).getBegin() > _width ){
                brickField.move( _begin+i, j, (int)_width - brickField.getData(_begin+i,j).getBegin() );
                break; 
            }
        }
        if ( field.getColor( _width, _begin+i ) != dataField.getData( _width, _index ).getColor() )
            return false;
    }
    if ( _begin + dataField.getData( _width, _index ).getSize() < field.getY() ) {
        if ( !clear( _width, _begin + dataField.getData( _width, _index ).getSize()
                , _begin + dataField.getData( _width, _index ).getSize(), dataField.getData( _width, _index ).getColor() ) )
            return false;
    }
    dataField.getData( _width, _index ).setBegin( _begin );
    dataField.getData( _width, _index ).setEnd( _begin + dataField.getData( _width, _index ).getSize() - 1 );
    if ( _index < dataField.getSize(_width)-1 && dataField.getData( _width, _index ).getEnd() > dataField.getData( _width, _index+1 ).getBegin() )
        dataField.getData( _width, _index+1 ).setBegin( dataField.getData( _width, _index ).getEnd() + 2 );
    return true;
}

bool Picross::clear( const uint &_width, const uint &_begin, const uint &_end, const Color &_color ){
    for ( uint i = _begin; i <= _end; i++ ) {
        if ( field.getColor( _width, i ) == _color ) {
            if ( _width > 0 && field.getColor( _width-1, i ) == _color )
                return false;
            for ( uint j = 0; j < brickField.getSize(i); j++ ) {
                if ( brickField.getData(i,j).getBegin() == _width ) {
                    if ( !brickField.move( i, j, 1 ) )
                        return false;
                    break;
                }
            }
            if ( field.getColor( _width, i ) == _color )
                return false;
        }
    }
    return true;
}

bool Picross::brickEqualData(){
    uint bufData = 0, bufBrick = 0;
    for ( uint i = 0; i < field.getX(); i++ )
        for ( uint j = 0; j < dataField.getSize(i); j++ )
            bufData += dataField.getData(i,j).getSize();
    for ( uint i = 0; i < field.getY(); i++ )
        for ( uint j = 0; j < brickField.getSize(i); j++ )
            bufBrick += brickField.getData(i,j).getSize();
    return bufData == bufBrick;
}

void Picross::tabPrint(){
    uint xShift = 0;
    uint yShift = 0;
    for (uint i = 0; i < field.getY(); ++i)
    {
        if ( xShift < brickField.getSize(i) )
            xShift = brickField.getSize(i);
    }
    for (uint i = 0; i < field.getX(); ++i)
    {
        if ( yShift < dataField.getSize(i) )
            yShift = dataField.getSize(i);
    }
    std::cout << std::endl;
    for (uint i = 0; i < yShift; ++i)
    {
        std::cout.width(xShift*2+field.getX()/10);
            std::cout << "  ";
        for (uint j = 0; j < field.getX(); ++j)
        {
            if ( i < dataField.getSize(j) ) {
                if ( dataField.getData(j,i).getSize() > 9 )
                    std::cout << dataField.getData(j,i).getSize();
                else
                    std::cout << dataField.getData(j,i).getSize() << " ";
            }
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
    for (uint i = 0; i < field.getY(); ++i)
    {
        std::stringstream out;
        for (uint j = 0; j < brickField.getSize(i); ++j)
        {
            out << std::to_string( brickField.getData(i,j).getSize() ) << " ";
        }
        std::cout.width(xShift*2+field.getX()/10);
        std::cout << out.str();
        for (uint j = 0; j < field.getX(); ++j)
        {
            switch ( field.getColor(j,i) ){
            case Color::white:
                std::cout << "..";
                break;
            case Color::black:
                std::cout << (char)0xB2 << (char)0xB2;
                break;
            }
        }
        std::cout << std::endl;
    }
} 
