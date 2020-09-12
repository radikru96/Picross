# Picross
The Nonogram Solver

vsizes- amount of data per column. Order: left to right.
hsizes- amount of data per line. Order: bottom to top.
vdata-  data for columns. Order: left to right, bottom to top
hdata-  data for lines. Order: bottom to top, right to left

Start()- to start solving.

    Classes:
pixel.h-        Fields pixel.
table.h-        Field. Pixels array.
data.h-         Initial data unit.
dat_stack.h-    Data stack. The height is determined by the unit of vsizes or hsizes.
dat_table.h-    Data field. Consists of stacks.
Picross.h-      Main class. All logical solution methods are here.