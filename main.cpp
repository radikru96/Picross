#include <iostream>
#include "Picross.h"

int main ()
{
    const int x=15;
    const int y=15;
    int vsizes[x]{1,3,4,4,5,5,7,6,6,5,6,4,3,3,1};
    int hsizes[y]{1,3,6,6,6,7,5,4,4,4,5,4,3,2,1};
    int vdata[]{10,
                2,1,2,
                1,3,1,2,
                2,2,1,1,
                3,1,1,1,2,
                1,4,1,1,1,
                1,3,1,1,1,1,1,
                1,1,1,1,1,1,
                2,2,1,1,1,1,
                3,1,1,1,1,
                1,3,1,1,1,2,
                3,1,1,1,
                1,6,2,
                2,2,2,
                10};
    int hdata[]{9,
                3,2,4,
                2,1,1,1,1,2,
                1,1,1,2,1,1,
                1,1,1,2,1,1,
                1,1,1,1,1,1,1,
                1,1,5,1,1,
                1,3,2,1,
                3,5,1,1,
                2,1,1,2,
                1,1,3,1,1,
                2,1,1,2,
                2,5,2,
                3,3,
                7};
    Picross::x=x;
    Picross::y=y;
    Picross::vert=vsizes;
    Picross::hori=hsizes;
    Picross::vert_dat=vdata;
    Picross::hori_dat=hdata;
    
    cout << Picross::Start() << endl;
    return 0;
}