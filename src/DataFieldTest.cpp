#include "DataField.h"
#include "BrickField.h"
#include "structs.h"
// #include <vector>
#include <iostream>

// void move( const Field &_field, const DataField &_dataField, BrickField &_brickField);
void moveBricks( const Field &_field, DataField &_dataField, BrickField &_brickField, const unsigned int &_y, const unsigned int &_index);
const unsigned int emptyOffset(const unsigned int &_y, const unsigned int &_index, const BrickField &_brickField, const Field &_field, const int &_direction);
void tabPrint( const Field &_field, const DataField &_dataField, const BrickField &_brickField);

int main(int argc, char const *argv[])
{
	Field field(10,10);
	unsigned int arr[] = {1,2,1,1,2,1,2,2,2,2};
	DataField dataField(field,10,arr);
	dataField.getData(0,0).setSize(8);
	dataField.getData(1,0).setSize(2);
	dataField.getData(1,1).setSize(2);
	dataField.getData(2,0).setSize(2);
	dataField.getData(3,0).setSize(8);
	dataField.getData(4,0).setSize(2);
	dataField.getData(4,1).setSize(2);
	dataField.getData(5,0).setSize(2);
	dataField.getData(6,0).setSize(6);
	dataField.getData(6,1).setSize(1);
	dataField.getData(7,0).setSize(1);
	dataField.getData(7,1).setSize(1);
	dataField.getData(8,0).setSize(1);
	dataField.getData(8,1).setSize(3);
	dataField.getData(9,0).setSize(5);
	dataField.getData(9,1).setSize(1);
	unsigned int arr2[] = {2,2,3,4,4,4,4,4,3,4};
	BrickField brickField(field,10,arr2);
	brickField.getData(0,0).setSize(1);
	brickField.getData(0,1).setSize(1);
	brickField.getData(1,0).setSize(2);
	brickField.getData(1,1).setSize(3);
	brickField.getData(2,0).setSize(4);
	brickField.getData(2,1).setSize(2);
	brickField.getData(2,2).setSize(1);
	brickField.getData(3,0).setSize(1);
	brickField.getData(3,1).setSize(2);
	brickField.getData(3,2).setSize(2);
	brickField.getData(3,3).setSize(1);
	brickField.getData(4,0).setSize(1);
	brickField.getData(4,1).setSize(1);
	brickField.getData(4,2).setSize(1);
	brickField.getData(4,3).setSize(1);
	brickField.getData(5,0).setSize(1);
	brickField.getData(5,1).setSize(1);
	brickField.getData(5,2).setSize(1);
	brickField.getData(5,3).setSize(1);
	brickField.getData(6,0).setSize(1);
	brickField.getData(6,1).setSize(1);
	brickField.getData(6,2).setSize(1);
	brickField.getData(6,3).setSize(1);
	brickField.getData(7,0).setSize(1);
	brickField.getData(7,1).setSize(1);
	brickField.getData(7,2).setSize(1);
	brickField.getData(7,3).setSize(2);
	brickField.getData(8,0).setSize(1);
	brickField.getData(8,1).setSize(2);
	brickField.getData(8,2).setSize(2);
	brickField.getData(9,0).setSize(1);
	brickField.getData(9,1).setSize(1);
	brickField.getData(9,2).setSize(1);
	brickField.getData(9,3).setSize(2);
	std::cout << "startPos()==" << brickField.startPos() << std::endl;
	moveBricks(field,dataField,brickField,0,0);
	tabPrint(field,dataField,brickField);
	return 0;
}

// void move( const Field &_field, const DataField &_dataField, BrickField &_brickField){
// 	for (unsigned int i = 0; i < _field.getY(); i++){
// 		for (unsigned int j = _brickField.getSize(i) - 1; j >= 0; j--){
// 			while ( emptyOffset(i,j,_brickField,_field,1) )
// 				_brickField.move(i,j,1);
			
// 		}
// 	}
// }

void moveBricks( const Field &_field, DataField &_dataField, BrickField &_brickField, const unsigned int &_y, const unsigned int &_index){
	// std::cout << "moveBricks\n" << emptyOffset(_y,_index,_brickField,_field,1) << std::endl;
	do {
		// std::cout << "moveBricks while\n";
		if (_index == _brickField.getSize(_y)-1 && _y < _field.getY())
			moveBricks(_field,_dataField,_brickField,_y+1,0);
		else
			moveBricks(_field,_dataField,_brickField,_y,_index+1);
		_brickField.move(_y,_index,1);
		for (unsigned int i = 0; i < _field.getX(); i++)
			_dataField.check(i);
	}while ( emptyOffset(_y,_index,_brickField,_field,1) > 0 );
	_brickField.move( _y, _index, 0-emptyOffset(_y,_index,_brickField,_field,-1) );
}

const unsigned int emptyOffset(const unsigned int &_y, const unsigned int &_index, const BrickField &_brickField, const Field &_field, const int &_direction){
	unsigned int offset = 0;
	unsigned int begin;
	if (_direction > 0)
		begin = _brickField.getData(_y,_index).getEnd();
	else if (_direction < 0)
		begin = _brickField.getData(_y,_index).getBegin();
	else
		return offset;
	while ( true ){
		if (begin + _direction < 0 || begin + _direction > _field.getX())
			return offset;
		if (_field.getColor(begin+_direction,_y) == Color::white){
			if (begin + _direction + _direction < 0 || begin + _direction + _direction > _field.getX())
				return offset += _direction;
			if (_field.getColor(begin+_direction+_direction,_y) != _brickField.getData(_y,_index).getColor())
				offset += _direction;
			else
				return offset;
		}
		else
			return offset;
	}
}

void tabPrint( const Field &_field, const DataField &_dataField, const BrickField &_brickField){
	unsigned int xShift = 0;
	unsigned int yShift = 0;
	for (unsigned int i = 0; i < _field.getY(); ++i)
	{
		if ( xShift < _brickField.getSize(i) )
			xShift = _brickField.getSize(i);
	}
	for (unsigned int i = 0; i < _field.getX(); ++i)
	{
		if ( yShift < _dataField.getSize(i) )
			yShift = _dataField.getSize(i);
	}
	for (unsigned int i = 0; i < yShift; ++i)
	{
		for (unsigned int j = 0; j < xShift; ++j)
		{
			std::cout << "  ";
		}
		for (unsigned int j = 0; j < _field.getX(); ++j)
		{
			if ( i < _dataField.getSize(j) )
				std::cout << _dataField.getData(j,i).getSize() << " ";
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}
	for (unsigned int i = 0; i < _field.getY(); ++i)
	{
		for (unsigned int j = 0; j < xShift; ++j)
		{
			if ( j < _brickField.getSize(i) )
				std::cout << _brickField.getData(i,j).getSize() << " ";
			else
				std::cout << "  ";
		}
		for (unsigned int j = 0; j < _field.getX(); ++j)
		{
			switch ( _field.getColor(j,i) ){
			case Color::white:
				std::cout << "..";
				break;
			case Color::black:
				std::cout << "8L";
				break;
			}
		}
		std::cout << std::endl;
	}
}