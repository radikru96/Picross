#include "DataField.h"

DataField::DataField(Field &_field, const unsigned int &_width, const unsigned int *_sizes) : field(_field){
	// field = _field;
	// std::cout << "start init\n";
	this->init(_width,_sizes);
	// std::cout << "end init\n";
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
    // field = nullptr;
}

bool DataField::check(const unsigned int &_x){
	unsigned int index = 0;
	unsigned int j;
	for (unsigned int i = 0; i < dataTable[_x].getSize(); i++){
		for (; index < field.getY(); index++){
			if ( field.getColor( _x, index ) == dataTable[_x].getData( i ).getColor() )
				break;
		}
		std::cout << "begin=" << index << std::endl;
		for ( j = index; j < index + dataTable[_x].getData( i ).getSize() && j < field.getY(); j++ ){
			if ( field.getColor( _x, j ) != dataTable[_x].getData( i ).getColor() )
				return false;

			std::cout << "in for j=" << j << std::endl;
		}
		std::cout << "after for j=" << j << std::endl;
		if ( j < index + dataTable[_x].getData( i ).getSize() || (j < field.getY() && field.getColor( _x, j ) == dataTable[_x].getData( i ).getColor()) )
			return false;
		index = j;
	}
	return true;
}