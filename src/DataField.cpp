#include "DataField.h"

bool DataField::check(const unsigned int &_x){
	unsigned int index = 0;
	unsigned int j;
	for (unsigned int i = 0; i < this->getSize(_x); i++){
		for (; index < field->getY(); index++){
			if ( field->getPix( _x, index ).getColor() == this->getData( _x, i ).getColor() )
				break;
		}
		for ( j = index; j < index + this->getData( _x, i ).getSize(); j++ ){
			if ( field->getPix( _x, j ).getColor() != this->getData( _x, i ).getColor() )
				return false;
		}
		index = j++;
	}
	return true;
}