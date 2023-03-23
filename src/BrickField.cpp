#include "BrickField.h"

bool BrickField::move(const unsigned int &_y, const unsigned int &_index, const unsigned int &_value){
	if (_value < 0)
		if (dataTable[_index].getData(_y).getBegin() + _value < 0)
			return false;
	if (_value > 0){
			if (dataTable[_index].getData(_y).getEnd() + _value > field->getX())
				return false;
	}
	else
		return false;
	dataTable[_index].getData(_y).move(_value);
	return true;
}