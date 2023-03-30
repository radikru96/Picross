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

//shitcode - checking through field, not brick
bool BrickField::move(const unsigned int &_y, const unsigned int &_index, const int &_value){
	int busy=0;
	if ( _index < 0 || _index >= field.getX() )
		return false;

	if (_value < 0){
		if (dataTable[_y].getData(_index).getBegin() + _value < 0)
			return false;
		busy = this->isBusy(_y,dataTable[_y].getData(_index).getBegin() - 1,dataTable[_y].getData(_index).getBegin() + _value - 1);
		if ( busy >= 0 )
			if (!this->move( _y, _index-1, dataTable[_y].getData(_index).getBegin() + _value - busy - 2 ))
				return false;
		for (unsigned int i = this->getData(_y,_index).getEnd() ; i > this->getData(_y,_index).getEnd() + _value; --i)
		{
			field.setPix(i,_y,Color::white);
			field.setPix(i-this->getData(_y,_index).getSize(),_y,Color::black);
		}
	}

	else if (_value > 0){
		if (dataTable[_y].getData(_index).getEnd() + _value >= field.getX())
			return false;
		busy = this->isBusy(_y, dataTable[_y].getData(_index).getEnd() + 1, dataTable[_y].getData(_index).getEnd() + _value + 1);
		if ( busy >= 0 )
			if (!this->move( _y, _index+1, dataTable[_y].getData(_index).getEnd() + _value - busy + 2))
				return false;
		for (unsigned int i = this->getData(_y,_index).getBegin(); i < this->getData(_y,_index).getEnd() + _value; ++i){
			field.setPix(i,_y,Color::white);
			field.setPix(i+this->getData(_y,_index).getSize(),_y,Color::black);
		}
	}
	else
		return false;
	dataTable[_index].getData(_y).move(_value);
	return true;
}

bool BrickField::startPos(){
	for ( unsigned int i = 0; i < field.getY(); i++){
		unsigned int j = 1;
		if (this->getSize(i) == 0)
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
			for (int k = this->getData(i,j).getBegin(); k <= this->getData(i,j).getEnd(); ++k)
			{
				field.setPix(k,i,this->getData(i,j).getColor());
			}
		}
	}
	return true;
}

int BrickField::isBusy(const unsigned int &_y, const unsigned int &_begin, const unsigned int &_end){
	if (_begin < _end){
		for ( int i = _begin; i <= _end && i < field.getX(); ++i)
		{
			if ( field.getColor(i,_y) != Color::white )
				return i;
		}
	}
	else{
		for ( int i = _begin; i >= _end && i >= 0; --i)
		{
			if ( field.getColor(i,_y) != Color::white )
				return i;
		}
	}
	return -1;
}