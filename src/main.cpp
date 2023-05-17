#include "DataField.h"
#include "BrickField.h"
#include "structs.h"
#include "Picross.h"
#include <exception>
#include <iostream>

#define DF dataField
#define BF brickField
#define GD getData
#define SS setSize

void tabPrint( const Field &_field, const DataField &_dataField, const BrickField &_brickField);

int main(int argc, char const *argv[])
{
	// unsigned int arr[] = {1,1,1};
	// DataField dataField(field,3,arr);
	// dataField.getData(0,0).setSize(1);
	// dataField.getData(1,0).setSize(2);
	// dataField.getData(2,0).setSize(3);
	// BrickField brickField(field,3,arr);
	// brickField.getData(0,0).setSize(1);
	// brickField.getData(1,0).setSize(2);
	// brickField.getData(2,0).setSize(3);
	
	// Field field(15,15);
	// unsigned int arr[] = {4,5,5,6,3,5,5,4,4,4,4,6,5,5,4};
	// DataField dataField(field,15,arr);
	// dataField.getData(0,0).setSize(3); dataField.getData(0,1).setSize(1); dataField.getData(0,2).setSize(1); dataField.getData(0,3).setSize(2); 
	// dataField.getData(1,0).setSize(1); dataField.getData(1,1).setSize(1); dataField.getData(1,2).setSize(1); dataField.getData(1,3).setSize(1); dataField.getData(1,4).setSize(3);
	// dataField.getData(2,0).setSize(1); dataField.getData(2,1).setSize(1); dataField.getData(2,2).setSize(2); dataField.getData(2,3).setSize(3); dataField.getData(2,4).setSize(1); 
	// dataField.getData(3,0).setSize(1); dataField.getData(3,1).setSize(1); dataField.getData(3,2).setSize(2); dataField.getData(3,3).setSize(3); dataField.getData(3,4).setSize(1); dataField.getData(3,5).setSize(1); 
	// dataField.getData(4,0).setSize(3); dataField.getData(4,1).setSize(1); dataField.getData(4,2).setSize(5);
	// dataField.getData(5,0).setSize(1); dataField.getData(5,1).setSize(1); dataField.getData(5,2).setSize(2); dataField.getData(5,3).setSize(1); dataField.getData(5,4).setSize(5);
	// dataField.getData(6,0).setSize(1); dataField.getData(6,1).setSize(1); dataField.getData(6,2).setSize(2); dataField.getData(6,3).setSize(4); dataField.getData(6,4).setSize(1);
	// dataField.getData(7,0).setSize(2); dataField.getData(7,1).setSize(1); dataField.getData(7,2).setSize(1); dataField.getData(7,3).setSize(4); 
	// dataField.getData(8,0).setSize(2); dataField.getData(8,1).setSize(1); dataField.getData(8,2).setSize(4); dataField.getData(8,3).setSize(1); 
	// dataField.getData(9,0).setSize(2); dataField.getData(9,1).setSize(2); dataField.getData(9,2).setSize(1); dataField.getData(9,3).setSize(5); 
	// dataField.getData(10,0).setSize(1); dataField.getData(10,1).setSize(2); dataField.getData(10,2).setSize(1); dataField.getData(10,3).setSize(5); 
	// dataField.getData(11,0).setSize(1); dataField.getData(11,1).setSize(1); dataField.getData(11,2).setSize(1); dataField.getData(11,3).setSize(3); dataField.getData(11,4).setSize(1); dataField.getData(11,5).setSize(1); 
	// dataField.getData(12,0).setSize(2); dataField.getData(12,1).setSize(1); dataField.getData(12,2).setSize(2); dataField.getData(12,3).setSize(3); dataField.getData(12,4).setSize(1); 
	// dataField.getData(13,0).setSize(1); dataField.getData(13,1).setSize(1); dataField.getData(13,2).setSize(1); dataField.getData(13,3).setSize(1); dataField.getData(13,4).setSize(3);
	// dataField.getData(14,0).setSize(2); dataField.getData(14,1).setSize(1); dataField.getData(14,2).setSize(1); dataField.getData(14,3).setSize(3); 
	// unsigned int arr2[] = {3,5,4,2,1,4,4,5,5,4,1,3,3,4,4};
	// BrickField brickField(field,15,arr2);
	// brickField.getData(0,0).setSize(2); brickField.getData(0,1).setSize(2); brickField.getData(0,2).setSize(3);
	// brickField.getData(1,0).setSize(2); brickField.getData(1,1).setSize(1); brickField.getData(1,2).setSize(1); brickField.getData(1,3).setSize(1); brickField.getData(1,4).setSize(2);
	// brickField.getData(2,0).setSize(1); brickField.getData(2,1).setSize(4); brickField.getData(2,2).setSize(2); brickField.getData(2,3).setSize(1);
	// brickField.getData(3,0).setSize(5); brickField.getData(3,1).setSize(5);
	// brickField.getData(4,0).setSize(3);
	// brickField.getData(5,0).setSize(4); brickField.getData(5,1).setSize(2); brickField.getData(5,2).setSize(2); brickField.getData(5,3).setSize(4);
	// brickField.getData(6,0).setSize(2); brickField.getData(6,1).setSize(1); brickField.getData(6,2).setSize(1); brickField.getData(6,3).setSize(1);
	// brickField.getData(7,0).setSize(2); brickField.getData(7,1).setSize(1); brickField.getData(7,2).setSize(1); brickField.getData(7,3).setSize(1); brickField.getData(7,4).setSize(2);
	// brickField.getData(8,0).setSize(1); brickField.getData(8,1).setSize(1); brickField.getData(8,2).setSize(1); brickField.getData(8,3).setSize(1); brickField.getData(8,4).setSize(1);
	// brickField.getData(9,0).setSize(3); brickField.getData(9,1).setSize(1); brickField.getData(9,2).setSize(1); brickField.getData(9,3).setSize(3);
	// brickField.getData(10,0).setSize(13);
	// brickField.getData(11,0).setSize(3); brickField.getData(11,1).setSize(7); brickField.getData(11,2).setSize(3);
	// brickField.getData(12,0).setSize(2); brickField.getData(12,1).setSize(9); brickField.getData(12,2).setSize(2);
	// brickField.getData(13,0).setSize(2); brickField.getData(13,1).setSize(1); brickField.getData(13,2).setSize(2); brickField.getData(13,3).setSize(1);
	// brickField.getData(14,0).setSize(2); brickField.getData(14,1).setSize(2); brickField.getData(14,2).setSize(2); brickField.getData(14,3).setSize(2); 

	// Field field(20,20);
	// unsigned int arr[] = {1,2,2,1,3, 4,4,6,4,5, 4,6,4,3,2, 1,2,3,2,1};
	// DataField dataField(field,20,arr);
	// dataField.getData(0,0).setSize(1);
	// dataField.getData(1,0).setSize(2); dataField.getData(1,1).setSize(1);
	// dataField.getData(2,0).setSize(2); dataField.getData(2,1).setSize(3);
	// dataField.getData(3,0).setSize(14);
	// dataField.getData(4,0).setSize(1); dataField.getData(4,1).setSize(4); dataField.getData(4,2).setSize(6);
	// dataField.getData(5,0).setSize(2); dataField.getData(5,1).setSize(3); dataField.getData(5,2).setSize(3); dataField.getData(5,3).setSize(2);
	// dataField.getData(6,0).setSize(2); dataField.getData(6,1).setSize(2); dataField.getData(6,2).setSize(2); dataField.getData(6,3).setSize(1);
	// dataField.getData(7,0).setSize(2); dataField.getData(7,1).setSize(2); dataField.getData(7,2).setSize(2); dataField.getData(7,3).setSize(2); dataField.getData(7,4).setSize(1); dataField.getData(7,5).setSize(1); 
	// dataField.getData(8,0).setSize(2); dataField.getData(8,1).setSize(1); dataField.getData(8,2).setSize(1); dataField.getData(8,3).setSize(5); 
	// dataField.getData(9,0).setSize(4); dataField.getData(9,1).setSize(1); dataField.getData(9,2).setSize(1); dataField.getData(9,3).setSize(1); dataField.getData(9,4).setSize(1);
	// dataField.getData(10,0).setSize(4); dataField.getData(10,1).setSize(1); dataField.getData(10,2).setSize(1); dataField.getData(10,3).setSize(5); 
	// dataField.getData(11,0).setSize(3); dataField.getData(11,1).setSize(1); dataField.getData(11,2).setSize(2); dataField.getData(11,3).setSize(2); dataField.getData(11,4).setSize(1); dataField.getData(11,5).setSize(2); 
	// dataField.getData(12,0).setSize(2); dataField.getData(12,1).setSize(2); dataField.getData(12,2).setSize(2); dataField.getData(12,3).setSize(2);
	// dataField.getData(13,0).setSize(2); dataField.getData(13,1).setSize(3); dataField.getData(13,2).setSize(3); 
	// dataField.getData(14,0).setSize(6); dataField.getData(14,1).setSize(6);  
	// dataField.getData(15,0).setSize(16);
	// dataField.getData(16,0).setSize(2); dataField.getData(16,1).setSize(3);
	// dataField.getData(17,0).setSize(2); dataField.getData(17,1).setSize(2); dataField.getData(17,2).setSize(1);
	// dataField.getData(18,0).setSize(1); dataField.getData(18,1).setSize(2);
	// dataField.getData(19,0).setSize(2);
	// unsigned int arr2[] = {1,1,1,3,3, 3,1,2,4,5, 5,2,4,3,2, 2,4,4,5,3};
	// BrickField brickField(field,20,arr2);
	// brickField.getData(0,0).setSize(1);
	// brickField.getData(1,0).setSize(3);
	// brickField.getData(2,0).setSize(5);
	// brickField.getData(3,0).setSize(3); brickField.getData(3,1).setSize(5);
	// brickField.getData(4,0).setSize(4); brickField.getData(4,1).setSize(6);
	// brickField.getData(5,0).setSize(3); brickField.getData(5,1).setSize(4);
	// brickField.getData(6,0).setSize(19);
	// brickField.getData(7,0).setSize(5); brickField.getData(7,1).setSize(4);
	// brickField.getData(8,0).setSize(3); brickField.getData(8,1).setSize(3); brickField.getData(8,2).setSize(1); brickField.getData(8,3).setSize(1);
	// brickField.getData(9,0).setSize(2); brickField.getData(9,1).setSize(1); brickField.getData(9,2).setSize(1); brickField.getData(9,3).setSize(2); brickField.getData(9,4).setSize(3);
	// brickField.getData(10,0).setSize(1); brickField.getData(10,1).setSize(1); brickField.getData(10,2).setSize(1); brickField.getData(10,3).setSize(1); brickField.getData(10,4).setSize(1);
	// brickField.getData(11,0).setSize(1); brickField.getData(11,1).setSize(1);
	// brickField.getData(12,0).setSize(2); brickField.getData(12,1).setSize(1); brickField.getData(12,2).setSize(1); brickField.getData(12,3).setSize(2);
	// brickField.getData(13,0).setSize(2); brickField.getData(13,1).setSize(5); brickField.getData(13,2).setSize(2);
	// brickField.getData(14,0).setSize(4); brickField.getData(14,1).setSize(4);
	// brickField.getData(15,0).setSize(6); brickField.getData(15,1).setSize(6);
	// brickField.getData(16,0).setSize(3); brickField.getData(16,1).setSize(1); brickField.getData(16,2).setSize(1); brickField.getData(16,3).setSize(3);
	// brickField.getData(17,0).setSize(3); brickField.getData(17,1).setSize(3); brickField.getData(17,2).setSize(1); brickField.getData(17,3).setSize(3);
	// brickField.getData(18,0).setSize(1); brickField.getData(18,1).setSize(1); brickField.getData(18,2).setSize(1); brickField.getData(18,3).setSize(3); brickField.getData(18,4).setSize(2);
	// brickField.getData(19,0).setSize(2); brickField.getData(19,1).setSize(7); brickField.getData(19,2).setSize(3);
	
	Field field(30,30);
	unsigned int arr[] = {3,3,5,5,6, 7,6,6,5,8, 4,4,5,4,2, 1,3,5,9,7, 9,9,7,6,8, 6,5,4,4,1};
	DataField dataField(field,30,arr);
	DF.GD(0,0).SS(3); DF.GD(0,1).SS(8); DF.GD(0,2).SS(3);
	DF.GD(1,0).SS(10); DF.GD(1,1).SS(4); DF.GD(1,2).SS(9);
	DF.GD(2,0).SS(7); DF.GD(2,1).SS(2); DF.GD(2,2).SS(6); DF.GD(2,3).SS(2); DF.GD(2,4).SS(4);
	DF.GD(3,0).SS(4); DF.GD(3,1).SS(1); DF.GD(3,2).SS(11); DF.GD(3,3).SS(1); DF.GD(3,4).SS(4);
	DF.GD(4,0).SS(4); DF.GD(4,1).SS(1); DF.GD(4,2).SS(2); DF.GD(4,3).SS(2); DF.GD(4,4).SS(8); DF.GD(4,5).SS(4);

	DF.GD(5,0).SS(4); DF.GD(5,1).SS(1); DF.GD(5,2).SS(2); DF.GD(5,3).SS(1); DF.GD(5,4).SS(1); DF.GD(5,5).SS(9); DF.GD(5,6).SS(4);
	DF.GD(6,0).SS(4); DF.GD(6,1).SS(1); DF.GD(6,2).SS(1); DF.GD(6,3).SS(1); DF.GD(6,4).SS(10); DF.GD(6,5).SS(4);
	DF.GD(7,0).SS(4); DF.GD(7,1).SS(1); DF.GD(7,2).SS(1); DF.GD(7,3).SS(4); DF.GD(7,4).SS(4); DF.GD(7,5).SS(4);
	DF.GD(8,0).SS(4); DF.GD(8,1).SS(1); DF.GD(8,2).SS(8); DF.GD(8,3).SS(3); DF.GD(8,4).SS(4);
	DF.GD(9,0).SS(4); DF.GD(9,1).SS(1); DF.GD(9,2).SS(2); DF.GD(9,3).SS(1); DF.GD(9,4).SS(6); DF.GD(9,5).SS(3); DF.GD(9,6).SS(1); DF.GD(9,7).SS(1);

	DF.GD(10,0).SS(4); DF.GD(10,1).SS(1); DF.GD(10,2).SS(2); DF.GD(10,3).SS(13);
	DF.GD(11,0).SS(9); DF.GD(11,1).SS(2); DF.GD(11,2).SS(8); DF.GD(11,3).SS(2);
	DF.GD(12,0).SS(3); DF.GD(12,1).SS(1); DF.GD(12,2).SS(3); DF.GD(12,3).SS(1); DF.GD(12,4).SS(4);
	DF.GD(13,0).SS(1); DF.GD(13,1).SS(1); DF.GD(13,2).SS(2); DF.GD(13,3).SS(4);
	DF.GD(14,0).SS(5); DF.GD(14,1).SS(2);

	DF.GD(15,0).SS(4);
	DF.GD(16,0).SS(4); DF.GD(16,1).SS(8); DF.GD(16,2).SS(1);
	DF.GD(17,0).SS(2); DF.GD(17,1).SS(4); DF.GD(17,2).SS(4); DF.GD(17,3).SS(2); DF.GD(17,4).SS(2);
	DF.GD(18,0).SS(2); DF.GD(18,1).SS(1); DF.GD(18,2).SS(1); DF.GD(18,3).SS(2); DF.GD(18,4).SS(1); DF.GD(18,5).SS(1); DF.GD(18,6).SS(1); DF.GD(18,7).SS(2); DF.GD(18,8).SS(3);
	DF.GD(19,0).SS(4); DF.GD(19,1).SS(2); DF.GD(19,2).SS(1); DF.GD(19,3).SS(2); DF.GD(19,4).SS(1); DF.GD(19,5).SS(3); DF.GD(19,6).SS(9);

	DF.GD(20,0).SS(3); DF.GD(20,1).SS(3); DF.GD(20,2).SS(1); DF.GD(20,3).SS(1); DF.GD(20,4).SS(1); DF.GD(20,5).SS(1); DF.GD(20,6).SS(1); DF.GD(20,7).SS(3); DF.GD(20,8).SS(4);
	DF.GD(21,0).SS(2); DF.GD(21,1).SS(1); DF.GD(21,2).SS(2); DF.GD(21,3).SS(1); DF.GD(21,4).SS(1); DF.GD(21,5).SS(3); DF.GD(21,6).SS(1); DF.GD(21,7).SS(3); DF.GD(21,8).SS(4);
	DF.GD(22,0).SS(3); DF.GD(22,1).SS(3); DF.GD(22,2).SS(1); DF.GD(22,3).SS(1); DF.GD(22,4).SS(1); DF.GD(22,5).SS(3); DF.GD(22,6).SS(4);
	DF.GD(23,0).SS(2); DF.GD(23,1).SS(4); DF.GD(23,2).SS(1); DF.GD(23,3).SS(2); DF.GD(23,4).SS(3); DF.GD(23,5).SS(12);
	DF.GD(24,0).SS(1); DF.GD(24,1).SS(1); DF.GD(24,2).SS(3); DF.GD(24,3).SS(2); DF.GD(24,4).SS(1); DF.GD(24,5).SS(1); DF.GD(24,6).SS(2); DF.GD(24,7).SS(2);
	
	DF.GD(25,0).SS(2); DF.GD(25,1).SS(2); DF.GD(25,2).SS(1); DF.GD(25,3).SS(1); DF.GD(25,4).SS(3); DF.GD(25,5).SS(7);
	DF.GD(26,0).SS(4); DF.GD(26,1).SS(2); DF.GD(26,2).SS(5); DF.GD(26,3).SS(6); DF.GD(26,4).SS(4);
	DF.GD(27,0).SS(2); DF.GD(27,1).SS(4); DF.GD(27,2).SS(2); DF.GD(27,3).SS(9);
	DF.GD(28,0).SS(4); DF.GD(28,1).SS(8); DF.GD(28,2).SS(2); DF.GD(28,3).SS(3);
	DF.GD(29,0).SS(3);
	
	unsigned int arr2[] = {2,3,5,6,7, 4,3,6,6,6, 8,7,6,5,4, 5,4,4,6,8, 8,6,5,5,7, 7,4,5,4,4};
	BrickField brickField(field,30,arr2);
	BF.GD(0,0).SS(11); BF.GD(0,1).SS(7);
	BF.GD(1,0).SS(13); BF.GD(1,1).SS(6); BF.GD(1,2).SS(2);
	BF.GD(2,0).SS(14); BF.GD(2,1).SS(4); BF.GD(2,2).SS(1); BF.GD(2,3).SS(1); BF.GD(2,4).SS(2);
	BF.GD(3,0).SS(13); BF.GD(3,1).SS(2); BF.GD(3,2).SS(1); BF.GD(3,3).SS(1); BF.GD(3,4).SS(1); BF.GD(3,5).SS(4);
	BF.GD(4,0).SS(2); BF.GD(4,1).SS(1); BF.GD(4,2).SS(1); BF.GD(4,3).SS(1); BF.GD(4,4).SS(1); BF.GD(4,5).SS(5); BF.GD(4,6).SS(1);

	BF.GD(5,0).SS(13); BF.GD(5,1).SS(2); BF.GD(5,2).SS(6); BF.GD(5,3).SS(2);
	BF.GD(6,0).SS(2); BF.GD(6,1).SS(1); BF.GD(6,2).SS(13);
	BF.GD(7,0).SS(1); BF.GD(7,1).SS(1); BF.GD(7,2).SS(1); BF.GD(7,3).SS(1); BF.GD(7,4).SS(1); BF.GD(7,5).SS(2);
	BF.GD(8,0).SS(1); BF.GD(8,1).SS(1); BF.GD(8,2).SS(1); BF.GD(8,3).SS(2); BF.GD(8,4).SS(8); BF.GD(8,5).SS(2);
	BF.GD(9,0).SS(2); BF.GD(9,1).SS(1); BF.GD(9,2).SS(1); BF.GD(9,3).SS(1); BF.GD(9,4).SS(3); BF.GD(9,5).SS(1);

	BF.GD(10,0).SS(1); BF.GD(10,1).SS(3); BF.GD(10,2).SS(2); BF.GD(10,3).SS(1); BF.GD(10,4).SS(1); BF.GD(10,5).SS(1); BF.GD(10,6).SS(1); BF.GD(10,7).SS(1);
	BF.GD(11,0).SS(1); BF.GD(11,1).SS(2); BF.GD(11,2).SS(1); BF.GD(11,3).SS(1); BF.GD(11,4).SS(1); BF.GD(11,5).SS(1); BF.GD(11,6).SS(1);
	BF.GD(12,0).SS(8); BF.GD(12,1).SS(2); BF.GD(12,2).SS(2); BF.GD(12,3).SS(1); BF.GD(12,4).SS(1); BF.GD(12,5).SS(1);
	BF.GD(13,0).SS(2); BF.GD(13,1).SS(1); BF.GD(13,2).SS(1); BF.GD(13,3).SS(1); BF.GD(13,4).SS(1);
	BF.GD(14,0).SS(1); BF.GD(14,1).SS(1); BF.GD(14,2).SS(8); BF.GD(14,3).SS(1);

	BF.GD(15,0).SS(9); BF.GD(15,1).SS(1); BF.GD(15,2).SS(1); BF.GD(15,3).SS(1); BF.GD(15,4).SS(1);
	BF.GD(16,0).SS(11); BF.GD(16,1).SS(3); BF.GD(16,2).SS(3); BF.GD(16,3).SS(1);
	BF.GD(17,0).SS(12); BF.GD(17,1).SS(3); BF.GD(17,2).SS(1); BF.GD(17,3).SS(2);
	BF.GD(18,0).SS(14); BF.GD(18,1).SS(2); BF.GD(18,2).SS(1); BF.GD(18,3).SS(1); BF.GD(18,4).SS(1); BF.GD(18,5).SS(2);
	BF.GD(19,0).SS(1); BF.GD(19,1).SS(5); BF.GD(19,2).SS(4); BF.GD(19,3).SS(2); BF.GD(19,4).SS(1); BF.GD(19,5).SS(4); BF.GD(19,6).SS(1); BF.GD(19,7).SS(1);
	
	BF.GD(20,0).SS(1); BF.GD(20,1).SS(5); BF.GD(20,2).SS(3); BF.GD(20,3).SS(1); BF.GD(20,4).SS(1); BF.GD(20,5).SS(1); BF.GD(20,6).SS(1); BF.GD(20,7).SS(1);
	BF.GD(21,0).SS(2); BF.GD(21,1).SS(5); BF.GD(21,2).SS(5); BF.GD(21,3).SS(1); BF.GD(21,4).SS(6); BF.GD(21,5).SS(2);
	BF.GD(22,0).SS(3); BF.GD(22,1).SS(11); BF.GD(22,2).SS(1); BF.GD(22,3).SS(6); BF.GD(22,4).SS(2);
	BF.GD(23,0).SS(4); BF.GD(23,1).SS(10); BF.GD(23,2).SS(1); BF.GD(23,3).SS(5); BF.GD(23,4).SS(3);
	BF.GD(24,0).SS(1); BF.GD(24,1).SS(8); BF.GD(24,2).SS(1); BF.GD(24,3).SS(1); BF.GD(24,4).SS(1); BF.GD(24,5).SS(1); BF.GD(24,6).SS(1);

	BF.GD(25,0).SS(1); BF.GD(25,1).SS(1); BF.GD(25,2).SS(2); BF.GD(25,3).SS(1); BF.GD(25,4).SS(1); BF.GD(25,5).SS(1); BF.GD(25,6).SS(1);
	BF.GD(26,0).SS(10); BF.GD(26,1).SS(1); BF.GD(26,2).SS(5); BF.GD(26,3).SS(4);
	BF.GD(27,0).SS(9); BF.GD(27,1).SS(1); BF.GD(27,2).SS(1); BF.GD(27,3).SS(6); BF.GD(27,4).SS(4);
	BF.GD(28,0).SS(9); BF.GD(28,1).SS(2); BF.GD(28,2).SS(2); BF.GD(28,3).SS(12);
	BF.GD(29,0).SS(10); BF.GD(29,1).SS(1); BF.GD(29,2).SS(1); BF.GD(29,3).SS(12);

	tabPrint(field,dataField,brickField);
	Picross picrss(field,dataField,brickField);
	picrss.start();
	tabPrint(field,dataField,brickField);
	return 0;
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