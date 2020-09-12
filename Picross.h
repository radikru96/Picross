using namespace std;
    enum orientation{VERTICAL,HORIZONTAL};
    enum state{RUN,FINISH};
    enum pix{FULL,EMPTY,NON};
    #include "dat_table.h"
    #include "table.h" /*x&&y<100*/
    #include <stack>
    #include <thread>

class Picross
{
    Picross();
    ~Picross();
    Picross(Picross const&) = delete;
    Picross& operator=(Picross const&) = delete;


    static int count;
    static void fill_dat_table(dat_table &Vert,dat_table &Hori);
    static bool solve(dat_table &Vert,dat_table &Hori,stack<table> &PTable);
    static bool vert_solve(const int &width, dat_table &Vert,stack<table> &PTable);
    static bool hori_solve(const int &width, dat_table &Hori,stack<table> &PTable);
    static bool fill_vert_empty(dat_table &Vert, stack<table> &PTable);
    static bool fill_hori_empty(dat_table &Hori, stack<table> &PTable);
    static void refresh_count(dat_table &Vert,dat_table &Hori,stack<table> &PTable);
public:
    static int x,y;
    static int *vert,*hori; // длинны индексов
    static int *vert_dat,*hori_dat; // данные полей
    static bool Start();
};
int Picross::count=0;
int Picross::x=0;
int Picross::y=0;
int *Picross::vert=nullptr;
int *Picross::hori=nullptr;
int *Picross::vert_dat=nullptr;
int *Picross::hori_dat=nullptr;
bool Picross::Start()
{
    if (x==0||x>=100||y==0||y>=100||vert==nullptr||hori==nullptr||
        vert_dat==nullptr||hori_dat==nullptr)   {return false;}
    stack<table> PTable;
    dat_table Vert_dat(x,vert,VERTICAL);
    dat_table Hori_dat(y,hori,HORIZONTAL);
    fill_dat_table(Vert_dat,Hori_dat);
    PTable.push(table(x,y));
    while (count<(x*y))
    {
        if (solve(Vert_dat,Hori_dat,PTable))
        {
            bool found=false;
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (PTable.top().get_table(i,j)==NON)
                    {
                        found=true;
                        PTable.top().set_pos(i,j);
                        PTable.push(PTable.top());
                        cout << "stack=" << PTable.size() << endl;
                        PTable.top().set_table(i,j,FULL);
                        count++;
                    }
                    if (found) {break;}
                }
                if (found) {break;}
            }
        }
        else
        {
            while (true)
            {
                if (PTable.size()==1) { return false;}
                PTable.pop();
                refresh_count(Vert_dat,Hori_dat,PTable);
                bool change=false;
                for (int i = PTable.top().get_pos()/100; i < x; i++)
                {
                    for (int j = PTable.top().get_pos()%100+1; j < y; j++)
                    {
                        if (PTable.top().get_table(i,j)==NON)
                        {
                            change=true;
                            PTable.top().set_pos(i,j);
                            PTable.push(PTable.top());
                            cout << "stack=" << PTable.size() << endl;
                            PTable.top().set_table(i,j,FULL);
                            count++;
                            break;
                        }
                    }
                    if (change) { break;}
                }
                if (change) { break;}
            }
        }
    }
    //******************************************************************************
    cout << "Picross/Nonogram.\n";
    cout << "  1  1\n  1 2 1\n3 1 2 1 3\n";
    for (int i = y-1; i >= 0; i--)
    {
        for (int j = 0; j < x; j++)
        {
            switch (PTable.top().get_table(j,i))
            {
            case FULL:
                cout << "@ ";
                break;
            case NON:
                cout << "  ";
                break;
            case EMPTY:
                cout << ". ";
                break;
            }
        }
        for (int j = Hori_dat.get_size(i)-1; j >= 0 ; j--)
        {
            cout << Hori_dat.get_table(i,j);
        }
        cout << endl;
    }
    cout << count << endl;
    //******************************************************************************
    return true;
}

void Picross::fill_dat_table(dat_table &Vert,dat_table &Hori)
{
    int j=0;
    for (int i = 0; i < x; i++)
    {
        for (int k = j; k < j+vert[i]; k++)
        {
            Vert.set_table(i,k-j,vert_dat[k]);
        }
        j+=vert[i];
    }
    j=0;
    for (int i = 0; i < y; i++)
    {
        for (int k = j; k < j+hori[i]; k++)
        {
            Hori.set_table(i,k-j,hori_dat[k]);
        }
        j+=hori[i];
    }
}

bool Picross::solve(dat_table &Vert,dat_table &Hori,stack<table> &PTable)
{
    int value;
    do
    {
        value=count;
        thread hori_th[y];
        bool h_result[y];
        for (int i = 0; i < y; i++)
        {
            hori_th[i] = std::thread( [&h_result,i,&Hori,&PTable](){h_result[i] = hori_solve(i,Hori,PTable);});
        }

        for (int i = 0; i < y; i++)
        {
            hori_th[i].join();
        }
        
        for (int i = 0; i < y; i++)
        {
            if (!h_result[i]) {return false;}
        }
        thread vert_th[x];
        bool v_result[x];
        for (int i = 0; i < x; i++)
        {
            vert_th[i] = std::thread( [&v_result,i,&Vert,&PTable]() {v_result[i] = vert_solve(i,Vert,PTable);} );
        }
        for (int i = 0; i < x; i++)
        {
            vert_th[i].join();
        }
        
        for (int i = 0; i < x; i++)
        {
            if (!v_result[i]) {return false;}
        }
        
        if (!fill_hori_empty(Hori,PTable)) {return false;}
        if (!fill_vert_empty(Vert,PTable)) {return false;}
        //******************************************************************************
        for (int i = y-1; i >= 0; i--)
        {
            for (int j = 0; j < x; j++)
            {
                switch (PTable.top().get_table(j,i))
                {
                case FULL:
                    cout << "@ ";
                    break;
                case NON:
                    cout << "  ";
                    break;
                case EMPTY:
                    cout << ". ";
                    break;
                }
            }
            for (int j = Hori.get_size(i)-1; j >= 0 ; j--)
            {
                cout << Hori.get_table(i,j) << " " << Hori.get_state(i,j) << " ";
            }
            cout << endl;
        }
        cout << endl << count << endl << count-value << endl;;
        //******************************************************************************
    } while (count<=x*y&&count!=value);
    return true;
}

bool Picross::vert_solve(const int &width, dat_table &Vert,stack<table> &PTable)
{
    int up_edge,down_edge;
    for (int i = 0; i < Vert.get_size(width); i++) //выбор ячейки данных
    {
        if (Vert.get_table(width,i)==0) { return true; }  
        if (i==0)
        {
            bool found=false;
            int value=0;
            for (int j = value; j < Vert.get_table(width,i); j++, value++)
            {
                if (!found&&PTable.top().get_table(width,value)==FULL)
                {
                    found=true;
                }
                else if (PTable.top().get_table(width,value)==EMPTY)
                {
                    j--;
                }
                if (found)
                {
                    if (PTable.top().get_table(width,value)==NON)
                    {
                        PTable.top().set_table(width,value,FULL);
                        count++;
                    }
                }
            }
            
        }
        if (i==Vert.get_size(width)-1)
        {
            bool found=false;
            int value=y-1;
            for (int j = value; j >= y-Vert.get_table(width,i); j--, value--)
            {
                if (!found&&PTable.top().get_table(width,value)==FULL)
                {
                    found=true;
                }
                else if (PTable.top().get_table(width,value)==EMPTY)
                {
                    j++;
                }
                if (found)
                {
                    if (PTable.top().get_table(width,value)==NON)
                    {
                        PTable.top().set_table(width,value,FULL);
                        count++;
                    }
                }
            }
        }
        up_edge=0;
        down_edge=(y-1);
        for (int j = 0; j <= i; j++) //перебор данных до выбранной ячейки вверх
        {
            for (int k = 0; k < Vert.get_table(width,j); ) //размещение данных в поле
            {
                if (PTable.top().get_table(width,up_edge)!=EMPTY)
                {
                    k++;
                    up_edge++;
                }
                else
                {
                    k=0;
                    up_edge++;
                }
            }
            if (j==i)
            {
                while (up_edge<y&&PTable.top().get_table(width,up_edge)==FULL){up_edge++;}
                up_edge--;
            }
            else 
            {
                while (PTable.top().get_table(width,up_edge)==FULL) {up_edge++;}
                up_edge++;
            }
            if (up_edge>=y) {return false;}
        }
        for (int j = Vert.get_size(width)-1; j >= i; j--) //перебор данных до выбранной ячейки вниз
        {
            for (int k = 0; k < Vert.get_table(width,j); ) //размещение данных в поле
            {
                if (PTable.top().get_table(width,down_edge)!=EMPTY)
                {
                    k++;
                    down_edge--;
                }
                else
                {
                    k=0;
                    down_edge--;
                }
            }
            if (j==i)
            {
                while (down_edge>=0&&PTable.top().get_table(width,down_edge)==FULL) {down_edge--;}
                down_edge++;
            }
            else
            {
                while (PTable.top().get_table(width,down_edge)==FULL) {down_edge--;}
                down_edge--;
            }
            if (down_edge<0) {return false;}
        }
        if ((up_edge-down_edge)>=Vert.get_table(width,i) ) {return false;}
        for (int j = down_edge; j <= up_edge; j++)
        {
            if (PTable.top().get_table(width,j)==NON)
            {
                PTable.top().set_table(width,j,FULL);
                count++;
            }
        }
        if (((up_edge-down_edge)+1)==Vert.get_table(width,i))
        {
            if (up_edge+1<y&&PTable.top().get_table(width,up_edge+1)==NON)
            {
                PTable.top().set_table(width,up_edge+1,EMPTY);
                count++;
            }
            if (down_edge-1>=0&&PTable.top().get_table(width,down_edge-1)==NON)
            {
                PTable.top().set_table(width,down_edge-1,EMPTY);
                count++;
            }
            Vert.finish(width,i,down_edge,up_edge);
        }
    }
    return true;
}

bool Picross::hori_solve(const int &width, dat_table &Hori,stack<table> &PTable)
{
    int right_edge,left_edge;
    for (int i = 0; i < Hori.get_size(width); i++) //выбор ячейки данных
    {
        if (Hori.get_table(width,i)==0) { return true; }
        if (i==Hori.get_size(width)-1)
        {
            bool found=false;
            int value=0;
            for (int j = value; j < Hori.get_table(width,i); j++, value++)
            {
                if (!found&&PTable.top().get_table(value,width)==FULL)
                {
                    found=true;
                }
                else if (PTable.top().get_table(value,width)==EMPTY)
                {
                    j--;
                }
                if (found)
                {
                    if (PTable.top().get_table(value,width)==NON)
                    {
                        PTable.top().set_table(value,width,FULL);
                        count++;
                    }
                }
            }
        }
        if (i==0)
        {
            bool found=false;
            int value=x-1;
            for (int j = value; j >= x-Hori.get_table(width,i); j--, value--)
            {
                if (!found&&PTable.top().get_table(value,width)==FULL)
                {
                    found=true;
                }
                else if (PTable.top().get_table(value,width)==EMPTY)
                {
                    j++;
                }
                if (found)
                {
                    if (PTable.top().get_table(value,width)==NON)
                    {
                        PTable.top().set_table(value,width,FULL);
                        count++;
                    }
                }
            }
        }
        right_edge=0;
        left_edge=(x-1);
        for (int j = 0; j <= i; j++) //перебор данных до выбранной ячейки вверх
        {
            for (int k = 0; k < Hori.get_table(width,j)&&left_edge>=0; ) //размещение данных в поле
            {
                if (PTable.top().get_table(left_edge,width)!=EMPTY)
                {
                    k++;
                    left_edge--;
                }
                else
                {
                    k=0;
                    left_edge--;
                }
            }
            if (j==i)
            {
                while (left_edge>=0&&PTable.top().get_table(left_edge,width)==FULL) {left_edge--;}
                left_edge++;
            }
            else
            {
                while (PTable.top().get_table(left_edge,width)==FULL) {left_edge--;}
                left_edge--;
            }
            if (left_edge<0) {return false;}
        }
        for (int j = Hori.get_size(width)-1; j >= i; j--) //перебор данных до выбранной ячейки вниз
        {
            for (int k = 0; k < Hori.get_table(width,j)&&right_edge<x; ) //размещение данных в поле
            {
                if (PTable.top().get_table(right_edge,width)!=EMPTY)
                {
                    k++;
                    right_edge++;
                }
                else
                {
                    k=0;
                    right_edge++;
                }
            }
            if (j==i)
            {
                while (right_edge<x&&PTable.top().get_table(right_edge,width)==FULL) {right_edge++;}
                right_edge--;
            }
            else
            {
                while (right_edge<x&&PTable.top().get_table(right_edge,width)==FULL) {right_edge++;}
                right_edge++;
            }
            if (right_edge>=x) {return false;}
        }
        if ((right_edge-left_edge)>=Hori.get_table(width,i) ) {return false;}
        for (int j = left_edge; j <= right_edge; j++)
        {
            if (PTable.top().get_table(j,width)==NON)
            {
                PTable.top().set_table(j,width,FULL);
                count++;
            }
        }
        if (((right_edge-left_edge)+1)==Hori.get_table(width,i))
        {
            if (right_edge+1<x&&PTable.top().get_table(right_edge+1,width)==NON)
            {
                PTable.top().set_table(right_edge+1,width,EMPTY);
                count++;
            }
            if (left_edge-1>=0&&PTable.top().get_table(left_edge-1,width)==NON)
            {
                PTable.top().set_table(left_edge-1,width,EMPTY);
                count++;
            }
            Hori.finish(width,i,left_edge,right_edge);
        }
    }
    return true;
}

bool Picross::fill_vert_empty(dat_table &Vert, stack<table> &PTable)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < Vert.get_size(i); j++)
        {
            if (Vert.get_state(i,j)==FINISH)
            {
                if (j==0)
                {
                    for (int k = 0; k < Vert.get_range_from(i,j); k++)
                    {
                        if (PTable.top().get_table(i,k)==NON)
                        {
                            PTable.top().set_table(i,k,EMPTY);
                            count++;
                        }
                    }
                }
                if (j==Vert.get_size(i)-1)
                {
                    for (int k = Vert.get_range_to(i,j)+1; k < y; k++)
                    {
                        if (PTable.top().get_table(i,k)==NON)
                        {
                            PTable.top().set_table(i,k,EMPTY);
                            count++;
                        }
                    }
                }
                if (Vert.get_size(i)>j+1 && Vert.get_state(i,j+1)==FINISH)
                {
                    for (int k = Vert.get_range_to(i,j)+1; k < Vert.get_range_from(i,j+1); k++)
                    {
                        if (PTable.top().get_table(i,k)==NON)
                        {
                            PTable.top().set_table(i,k,EMPTY);
                            count++;
                        }
                    }
                }
            }
            if (Vert.get_size(i)==1)
            {
                int range_from,range_to;
                bool first=true;
                bool hole=false;
                for (int k = 0; k < y; k++)
                {
                    if (PTable.top().get_table(i,k)==FULL)
                    {
                        if (first)
                        {
                            range_from=k;
                            first=false;
                        }
                        range_to=k;
                    }
                }
                if (first) {return true;}
                if (range_to-range_from+1>Vert.get_table(i,0))
                {
                    return false;
                }
                for (int k = range_from+1; k < range_to; k++)
                {
                    if (PTable.top().get_table(i,k)==NON)
                    {
                        PTable.top().set_table(i,k,FULL);
                        count++;
                    }
                }
                for (int k = range_from+Vert.get_table(i,0); k < y; k++)
                {
                    if (PTable.top().get_table(i,k)==NON)
                    {
                        PTable.top().set_table(i,k,EMPTY);
                        count++;
                    }
                }
                for (int k = 0; k < range_to-Vert.get_table(i,0)+1; k++)
                {
                    if (PTable.top().get_table(i,k)==NON)
                    {
                        PTable.top().set_table(i,k,EMPTY);
                        count++;
                    }
                }
            }
        }
    }
    return true;
}

bool Picross::fill_hori_empty(dat_table &Hori, stack<table> &PTable)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < Hori.get_size(i); j++)
        {
            if (Hori.get_state(i,j)==FINISH)
            {
                if (j==0)
                {
                    for (int k = Hori.get_range_to(i,j)+1; k < x; k++)
                    {
                        if (PTable.top().get_table(k,i)==NON)
                        {
                            PTable.top().set_table(k,i,EMPTY);
                            count++;
                        }
                    }
                }
                if (Hori.get_size(i)-1==j)
                {
                    for (int k = 0; k < Hori.get_range_from(i,j); k++)
                    {
                        if (PTable.top().get_table(k,i)==NON)
                        {
                            PTable.top().set_table(k,i,EMPTY);
                            count++;
                        }
                    }
                }
                if (Hori.get_size(i)>j+1 && Hori.get_state(i,j+1)==FINISH)
                {
                    for (int k = Hori.get_range_to(i,j+1)+1; k < Hori.get_range_from(i,j); k++)
                    {
                        if (PTable.top().get_table(k,i)==NON)
                        {
                            PTable.top().set_table(k,i,EMPTY);
                            count++;
                        }
                    }
                }
            }
            if (Hori.get_size(i)==1)
            {
                int range_from,range_to;
                bool first=true;
                bool hole=false;
                for (int k = 0; k < x; k++)
                {
                    if (PTable.top().get_table(k,i)==FULL)
                    {
                        if (first)
                        {
                            range_from=k;
                            first=false;
                        }
                        range_to=k;
                    }
                }
                if (first) {return true;}
                if (range_to-range_from+1>Hori.get_table(i,0))
                {
                    return false;
                }
                for (int k = range_from+1; k < range_to; k++)
                {
                    if (PTable.top().get_table(k,i)==NON)
                    {
                        PTable.top().set_table(k,i,FULL);
                        count++;
                    }
                }
                for (int k = range_from+Hori.get_table(i,0); k < x; k++)
                {
                    if (PTable.top().get_table(k,i)==NON)
                    {
                        PTable.top().set_table(k,i,EMPTY);
                        count++;
                    }
                }
                for (int k = 0; k < range_to-Hori.get_table(i,0)+1; k++)
                {
                    if (PTable.top().get_table(k,i)==NON)
                    {
                        PTable.top().set_table(k,i,EMPTY);
                        count++;
                    }
                }
            }
        }
    }
    return true;
}

void Picross::refresh_count(dat_table &Vert,dat_table &Hori,stack<table> &PTable)
{
    count=0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (PTable.top().get_table(i,j)!=NON)
            {
                count++;
            }
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < Vert.get_size(i); j++)
        {
            Vert.reset(i,j);
        }
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < Hori.get_size(i); j++)
        {
            Hori.reset(i,j);
        }   
    }
}
//класс ячеек данных не более 100,с меткой исполненности
//класс вертикального и горизонтального поля данных
//класс/метод действий/логики колонн/строк
