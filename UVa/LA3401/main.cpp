#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

const int maxn = 4;
int N,dice[maxn][6],ans;
vector<string> names;
int dice24[24][6];
int r[maxn],color[maxn][6]; // ��¼ÿ�����������̬����ת����������ɫ

int Left[] = {4,0,2,3,5,1};
int Up[] = {2,1,5,0,4,3};

//��������T��תĿǰ����̬P
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
            //����Ҫ��ת
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
            //����ת0-3��
            for (int k = 0; k < 6; k++)
            {
                dice24[times][k] = p[k];
            }
            rot(Left,p);
            times++;
        }
    }
    /*������
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
        //���Ѿ����ֹ�
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
            //r[i] ��ʾ��i�����������̬
            color[i][dice24[r[i]][j]] = dice[i][j];
        }

    }
    int tot = 0;
    for (int j = 0; j < 6; j++)
    {
        int cnt[maxn*6];// ���ÿ��������ÿ���涼����ͬ
        memset(cnt,0,sizeof(cnt)); //��ʼ��Ϊ0
        int maxface = 0 ;
        //�ж�ÿ���������j�������ɫ��ͬ�����ֵ
        for (int i = 0; i < N; i++)
        {
            maxface = max(maxface,++cnt[color[i][j]]);
        }
        //����ͬ��ɫ������N - maxface
        tot += N - maxface;
    }
    ans = min(ans,tot);
}

void dfs(int d)
{
    if (d == N) check();//���N�������嶼��ת�����������Сֵ
    else
    {
        for (int i = 0 ; i < 24; i++)
        {
            //���α���24����̬
            r[d] = i;
            //dfs��һ��������
            dfs(d+1);
        }
    }
}

int main()
{
    enumerate();
    while (cin>>N && N)
    {
        //���vector
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
        ans = N*6;//��������������ɫ������ͬ��ȫ����Ҫ����Ϳɫ
        r[0] = 0;//��һ�������岻��ת
        dfs(1);//�ӵڶ��������忪ʼ��ת
        cout<<ans<<endl;
    }
    return 0;
}
