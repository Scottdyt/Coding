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
        double each  = circle/sum; //新的间隔
        double origin = circle/n;  //之前的间隔，一定大于新间隔
        for (int i =1 ;i < n;i++)
        {
            double position = origin*i;
            for (int j = 1;j < sum;j++)  //计算离第i个雕塑最近的位置
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
