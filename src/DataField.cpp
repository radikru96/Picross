#include "DataField.h"

DataField::DataField(Field &_field, const unsigned int &_width, const unsigned int *_sizes) : field(_field){
	this->init(_width,_sizes);
}

DataField::~DataField(){
    if (sizes!=nullptr)
    {
        delete [] sizes;
        sizes = nullptr;
    }
    if (dataTable != nullptr)
    {
        delete [] dataTable;
        dataTable = nullptr;
    }
}

bool DataField::check(const unsigned int &_x) const{
	unsigned int index = 0;
	unsigned int j;
	for (unsigned int i = 0; i < dataTable[_x].getSize(); i++){
		for (; index < field.getY(); index++){
			if ( field.getColor( _x, index ) == dataTable[_x].getData( i ).getColor() )
				break;
		}
		for ( j = index; j < index + dataTable[_x].getData( i ).getSize() && j < field.getY(); j++ ){
			if ( field.getColor( _x, j ) != dataTable[_x].getData( i ).getColor() )
				return false;
		}
		if ( j < index + dataTable[_x].getData( i ).getSize() || (j < field.getY() && field.getColor( _x, j ) == dataTable[_x].getData( i ).getColor()) )
			return false;
		index = j;
	}
	return true;
}