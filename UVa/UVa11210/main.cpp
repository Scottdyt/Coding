#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const string mahjong[] =
{
    "1T","2T","3T","4T","5T","6T","7T","8T","9T",
    "1S","2S","3S","4S","5S","6S","7S","8S","9S",
    "1W","2W","3W","4W","5W","6W","7W","8W","9W",
    "DONG","NAN","XI","BEI",
    "ZHONG","FA","BAI"
};

int convert(string name)
{
    for (int i = 0; i < 34; i++)
    {
        if (mahjong[i] == name) return i;
    }
    return -1;
}

int number[34],origin[34];

bool recursive(int dep)
{
    int i;
    for (i = 0; i < 34; i++)
    {
        if (number[i] >= 3)
        {
            //可以为刻子，三张相同的牌
            if (dep == 3) //每次无论是顺子还是刻子，只有4组
            {
                return true;
            }
            number[i] -= 3; //用过了这三张牌
            if (recursive(dep+1))
            {
                return true;
            }
            number[i] +=3;
        }
    }
    for (i = 0; i < 24; i++)
    {
        //要成为顺子，最大的牌为7W
        if (i%9 <= 6 && number[i] >=1 && number[i+1] >=1 && number[i+2] >=1 )
        {
            //可以为顺子
            if (dep == 3) return true;//四组都找到了
            number[i]--;
            number[i+1]--;
            number[i+2]--;
            if (recursive(dep+1))
            {
                return true;
            }
            number[i]++;
            number[i+1]++;
            number[i+2]++;
        }

    }
    return false;
}


bool check()
{
    for (int i = 0 ; i < 34; i++)
    {
        if (number[i] >= 2)
        {
            //先找将牌
            number[i] -=2;
            if (recursive(0))
                //可以和牌
                return true;
            number[i] +=2;
        }
    }
    return false;
}


int main()
{
    int kcase = 0,i,j;
    bool hu;
    string temp;
    while (cin>>temp)
    {
        if (temp[0] == '0')
            break;
        cout<<"Case "<<++kcase<<":";
        memset(number,0,sizeof(number));
        number[convert(temp)]++;
        for (i = 1; i < 13; i++)
        {
            cin>>temp;
            number[convert(temp)]++;
        }
        hu = false;
        memcpy(origin,number,sizeof(origin));
        for (i = 0 ;i < 34; i++)
        {

            if (number[i] >= 4)
                continue;//已经不能再多了
            number[i]++;
            if (check())
            {
                hu = true;
                cout<<" "<<mahjong[i];
                //如果胡牌，则number数组中的元素已经用完，需要重新赋值
                memcpy(number,origin,sizeof(number));
                continue;
            }
            //若没有胡牌，要减去当前新加进去的牌
            number[i]--;
        }
        if (!hu)
        {
            cout<<" Not ready";
        }
        cout<<"\n";

    }
    return 0;
}
