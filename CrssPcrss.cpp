using namespace std;
enum orientation{VERTICAL,HORIZONTAL};
enum state{RUN,FINISH};
enum pix{FULL,EMPTY,NON};
#include "dat_table.h"
#include "table.h" /*x&&y<100*/
#include <ncurses.h>

start_color();
init_pair( 1, COLOR_GREEN, COLOR_BLACK );
init_pair( 2, COLOR_YELLOW, COLOR_BLACK );
init_pair( 3, COLOR_CYAN, COLOR_BLACK );

int col,row,wy,wx,xoffset=1,yoffset=1;

void CursInit()
{
    initscr();
    curs_set(0);
    noecho();
    keypad( stdscr, true );
}

void GetFieldSize()
{
    bool end = 0;
    clear();
    printw( "Enter number of cols and rows.\nFor example \"5 5\"\n" );
    echo();
    scanw("%d %d", col, row );
    noecho();
}

void FillData()
{
    int *VertData = new int[col];
    int *HoriData = new int[row];
    int curs_posx;
    int curs_posy
    bool end = 0;
    for ( int i = 0; i < col; i++ );
    {
        VertData[i] = yoffset;
    }
    for ( int i = 0; i < row; i++ );
    {
        HoriData[i] = xoffset;
    }
    while ( !end )
    {
        clear();
        attron( COLOR_PAIR(2) | A_REVERSE );
        for ( int i = 0; i < yoffset; i++ )
        {
            for ( int j = xoffset; j < col + xoffset; j++ )
            {
                if ( yoffset - VertData[j-xoffset] >= i )
                {
                    mvprintw( i, j*2, "  ");
                }
            }
        }
        for ( int i = 0; i < row; i++ )
        {
            for ( int j = xoffset-HoriData[i]; j < xoffset; j++)
            {
                mvprintw( i+yoffset, (j)*2, "  ");
            }
        }
        attroff( COLOR_PAIR(2) | A_REVERSE );
        attron( COLOR_PAIR(1) | A_REVERSE );
        mvprintw( curs_posy, curs_posx*2, "  " );
        attroff( COLOR_PAIR(1) | A_REVERSE );
        switch ( getch() )
        {
            case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case KEY_LEFT:
                if ( curs_posx !> xoffset)
                break;
            case KEY_RIGHT:
                break;
            default:
                break;
        }
    }
    delete [] VertData;
    VertData = nullptr;
    delete [] HoriData;
    HoriData = nullptr;
}

int main()
{
    CursInit();
	flushinp();
    clear();
    GetFieldSize();
    table board( col, row );
    getmaxyx( scr, wy, wx );
    if ( row > wy - 6 || col > (wx/2) - 6 )
        return 1;
    
    while ( 1 )
    {
        clear
    }
    refresh();
    getch();
	endwin();
    return 0;
}