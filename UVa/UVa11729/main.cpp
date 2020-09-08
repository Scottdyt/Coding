#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct work
{
    int b, j;
    bool operator < (const work& x)const
    {
        return j > x.j;   //在这里操作符只能重载<号，因此return为>即可实现递减序列排序
    }
    work(int x, int y)
    {
        b = x;
        j = y;
    }
};

int main()
{
    int n, b, j, CASE = 1;
    while (cin >> n && n)
    {
        vector<work> temp;
        for (int i = 0; i < n; i++)
        {
            cin >> b >> j;
            temp.push_back(work(b, j)); //(work){b,j}
        }
        sort(temp.begin(), temp.end());
        int worktime = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            worktime += temp[i].b;
            ans = max(ans, worktime + temp[i].j);
        }
        cout << "Case " << CASE++ << ": " << ans << endl;
    }
    return 0;
}


