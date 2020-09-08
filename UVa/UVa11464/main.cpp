#include <iostream>
#include <algorithm>
using namespace std;

const int N = 20;
const int INF = 1<<30;

int dx[] = {0,0,-1};
int dy[] = {-1,1,0};

int a[N][N];
int tmp[N][N];

int ans;


int getSum(int x, int y, int n)
{
    int ret = 0;
    for(int i = 0; i < 3; i++)
    {
        /*ֻ����ǰ��������������Ϊ�Ǵ�ǰ����ɨ�裬
        �·���Ŀ��Ը���ǰ��ĺͽ��и���*/
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 1 && tx <= n && ty >= 1 && ty <= n)
            ret += tmp[tx][ty];
    }
    return ret;
}

int check(int s, int n)
{
    //�ȼ����һ��
    for(int i = 1; i <= n; i++)
    {
        //��s�Ķ�������ʽд�������
        tmp[1][i] = s&1;
        if(tmp[1][i] == 0 && a[1][i] == 1)
            //��ֻ�ܽ�1��Ϊ0�����㣬�򲻺�����
            return INF;
        //������һλ
        s>>=1;
    }
    //���μ�������
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int ret = getSum(i-1,j,n);
            //����ǰһ��������������ܺͣ����Ѿ�Ϊż������ǰԪ����0
            tmp[i][j] = ret & 1;
            if(tmp[i][j] == 0 && a[i][j] == 1)
                //��ֻ�ܽ�1��Ϊ0�����㣬�򲻺�����
                return INF;
        }
    }
    int cnt = 0;
    for(int i =1 ; i <= n; i++)
        for(int j = 1; j <= n; j++)
            //ͨ���Ƚ��Ƿ���ͬ���������
            cnt += (a[i][j] != tmp[i][j]);
    return cnt;
}

int main()
{
    int t,n;
    cin>>t;
    for(int kcase = 1; kcase <= t; kcase++)
    {
        cin>>n;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
            {
                cin>>a[i][j];
            }
        }
        ans = INF;
        for(int s=0; s<=(1<<n)-1; s++)
        {
            ans = min(ans,check(s,n));
        }
        if(ans == INF)
            ans = -1;
        cout<<"Case "<<kcase<<": "<<ans<<endl;
    }
    return 0;
}
