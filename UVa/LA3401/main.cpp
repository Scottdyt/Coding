#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int maxn = 4;
int N,dice[maxn][6],ans;
vector<string> names;
int dice24[24][6];
int r[maxn],color[maxn][6]; // 记录每个立方体的姿态和旋转后各个面的颜色

int Left[] = {4,0,2,3,5,1};
int Up[] = {2,1,5,0,4,3};

//按照排列T旋转目前的姿态P
void rot(int T[],int p[])
{
    int q[6];
    memcpy(q,p,sizeof(q));
    for (int i = 0; i < 6; i++)
        p[i] = T[q[i]];
}

void enumerate()
{
    int p0[6] = {0,1,2,3,4,5};
    int times = 0;
    for (int i = 0; i < 6; i++)
    {
        int p[6];
        memcpy(p,p0,sizeof(p0));
        if (i == 0) rot(Up,p);
        if (i == 1)
        {
            rot(Left,p);
            rot(Up,p);
        }
        if (i == 2)
        {
            //不需要旋转
        }
        if (i ==3)
        {
            rot(Up,p);
            rot(Up,p);
        }
        if (i == 4)
        {
            rot(Left,p);
            rot(Left,p);
            rot(Left,p);
            rot(Up,p);
        }
        if (i == 5)
        {
            rot(Left,p);
            rot(Left,p);
            rot(Up,p);
        }
        for (int j = 0; j < 4; j++)
        {
            //向左转0-3次
            for (int k = 0; k < 6; k++)
            {
                dice24[times][k] = p[k];
            }
            rot(Left,p);
            times++;
        }
    }
    /*输出结果
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 6; j++)
            cout<<dice24[i][j]<<" ";
        cout<<endl;
    }*/
}

int get_ID(string name)
{
    int n = names.size();
    for (int i = 0; i < n; i++)
    {
        //若已经出现过
        if (names[i] == name)
            return i;
    }
    names.push_back(name);
    return n;
}

void check()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            //r[i] 表示第i个立方体的姿态
            color[i][dice24[r[i]][j]] = dice[i][j];
        }

    }
    int tot = 0;
    for (int j = 0; j < 6; j++)
    {
        int cnt[maxn*6];// 最多每个立方体每个面都不相同
        memset(cnt,0,sizeof(cnt)); //初始化为0
        int maxface = 0 ;
        //判断每个立方体第j个面的颜色相同的最大值
        for (int i = 0; i < N; i++)
        {
            maxface = max(maxface,++cnt[color[i][j]]);
        }
        //不相同颜色的面有N - maxface
        tot += N - maxface;
    }
    ans = min(ans,tot);
}

void dfs(int d)
{
    if (d == N) check();//如果N个立方体都旋转结束，检查最小值
    else
    {
        for (int i = 0 ; i < 24; i++)
        {
            //依次遍历24个姿态
            r[d] = i;
            //dfs下一个立方体
            dfs(d+1);
        }
    }
}

int main()
{
    enumerate();
    while (cin>>N && N)
    {
        //清空vector
        names.clear();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                string name;
                cin>>name;
                dice[i][j] = get_ID(name);
            }
        }
        ans = N*6;//最坏情况，所有面颜色都不相同，全都需要重新涂色
        r[0] = 0;//第一个立方体不旋转
        dfs(1);//从第二个立方体开始旋转
        cout<<ans<<endl;
    }
    return 0;
}
