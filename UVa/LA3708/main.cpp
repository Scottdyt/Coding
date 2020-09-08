#include <iostream>
#include <cstdio>

using namespace std;

int n,m;
double circle = 10000;

int main()
{
    while (scanf("%d%d",&n,&m)==2)
    {
        int sum = n+m;
        double ans = 0;
        double each  = circle/sum; //�µļ��
        double origin = circle/n;  //֮ǰ�ļ����һ�������¼��
        for (int i =1 ;i < n;i++)
        {
            double position = origin*i;
            for (int j = 1;j < sum;j++)  //�������i�����������λ��
            {
                if (position == j*each)
                    break;
                double temp1 = (j-1)*each;
                double temp2 = j*each;
                if (position >  temp1 && position < temp2)
                {
                    ans += min(position - temp1,temp2 - position);
                    break;
                }
            }
        }
        printf("%.4f\n",ans);
    }
    return 0;
}
