#include "BrickField.h"

BrickField::BrickField(Field &_field, const unsigned int &_width, const unsigned int *_sizes) : field(_field){
	this->init(_width,_sizes);
}

BrickField::~BrickField(){
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

bool BrickField::move(const unsigned int &_y, const unsigned int &_index, const int &_value){
	int busy=0;
	if ( _index < 0 || _index >= this->getSize(_y) )
		return true;
	if ( this->getData(_y,_index).getSize() == 0 )
		return false;
	if (_value < 0){
		if (int(this->getData(_y,_index).getBegin()) + _value < 0)
			return false;
		busy = this->isBusy(_y,this->getData(_y,_index).getBegin() - 1,this->getData(_y,_index).getBegin() + _value - 1);
		if ( busy >= 0 )
            if (
                !this->move( _y, _index-1,
                int(this->getData(_y,_index).getBegin()) + _value - busy - 2 ))
				return false;
		for (unsigned int i = this->getData(_y,_index).getEnd() ; i > this->getData(_y,_index).getEnd() + _value; --i)
		{
			field.setPix(i,_y,Color::white);
			field.setPix(i-this->getData(_y,_index).getSize(),_y,Color::black);
		}
	}
	else if (_value > 0){
		if (this->getData(_y,_index).getEnd() + _value >= field.getX())
			return false;
		busy = this->isBusy(_y, this->getData(_y,_index).getEnd() + 1, this->getData(_y,_index).getEnd() + _value + 1);
		if ( busy >= 0 )
			if (!this->move( _y, _index+1, this->getData(_y,_index).getEnd() + _value - busy + 2))
				return false;
		for (unsigned int i = this->getData(_y,_index).getBegin(); i < this->getData(_y,_index).getBegin() + _value; ++i){
			field.setPix(i,_y,Color::white);
			field.setPix(i+this->getData(_y,_index).getSize(),_y,Color::black);
		}
	}
	else
		return false;
	this->getData(_y,_index).move(_value);
	return true;
}

bool BrickField::startPos(){
	for ( unsigned int i = 0; i < field.getY(); i++){
		unsigned int j = 1;
		if (this->getData(i,0).getSize() == 0)
			continue;
		this->getData(i,0).setBegin(0);
		this->getData(i,0).setEnd(this->getData(i,0).getSize()-1);
		for ( j = 1; j < this->getSize(i); j++){
			this->getData(i,j).setBegin(this->getData(i,j-1).getEnd()+2);
			this->getData(i,j).setEnd(this->getData(i,j).getSize() + this->getData(i,j).getBegin() - 1);
		}
		if (this->getData(i,j-1).getEnd() >= field.getX())
			return false;
		for ( unsigned int j = 0; j < this->getSize(i); ++j)
		{
			for (unsigned int k = this->getData(i,j).getBegin(); k <= this->getData(i,j).getEnd(); ++k)
			{
				field.setPix(k,i,this->getData(i,j).getColor());
			}
		}
	}
	return true;
}

int BrickField::isBusy(const unsigned int &_y, const unsigned int &_begin, const unsigned int &_end){
	if (_begin < _end){
		for ( unsigned int i = _begin; i <= _end && i < field.getX(); i++)
		{
			if ( field.getColor(i,_y) != Color::white )
				return i;
		}
	}
	else{
        for ( int i = _begin; i >= (int)_end && i >= 0; --i)
		{
			if ( field.getColor(i,_y) != Color::white )
				return i;
		}
	}
	return -1;
}
