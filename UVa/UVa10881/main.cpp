#include <iostream>
#include <algorithm>
using namespace std;

int Length;
int Time;
int Number;
const int maxn = 10000 + 5;

struct ant
{
    int status;//1 stands for right, -1 stands for left,0 stands for turning
    int pos;
    int id;
    ant(int s,int p,int d)
    {
        status = s;
        pos = p;
        id = d;
    }
    ant(){};
    bool operator < (const ant& a)const
    {
        return pos < a.pos;
    }
} before[maxn],after[maxn];

const char dirName[][10] = {"L","Turning","R"};

int order[maxn];//输入的第i只蚂蚁是排序后的order[i]只蚂蚁

int main()
{
    int n;
    cin>>n;
    for (int kase = 1;kase <= n;kase++)
    {
        cin>>Length>>Time>>Number;
        for (int i = 0; i < Number; i++)               //输入
        {
            int p;
            char ch;
            cin>>p>>ch;
            if (ch == 'R')
            {
                before[i] = ant(1,p,i);
                after[i] = ant(1,p+Time,0);//id not known yet
            }
            else//left
            {
                before[i] = ant(-1,p,i);
                after[i] = ant(-1,p-Time,0);//id not known yet
            }
        }

        sort(before,before+Number);
        for (int i = 0; i < Number; i++)
        {
            order[before[i].id] = i;
        }

        sort(after,after+Number);
        for (int i = 0; i < Number-1; i++)
        {
            if (after[i].pos == after[i+1].pos)
                after[i].status = after[i+1].status = 0;//Turining status
        }


        cout<<"Case #"<<kase<<":"<<endl;
        for (int i = 0 ;i < Number;i++)
        {
            int a = order[i];
            if (after[a].pos < 0 || after[a].pos > Length)
                cout<<"Fell off"<<endl;
            else
            {
                cout<<after[a].pos<<" "<<dirName[after[a].status+1]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
