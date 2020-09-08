#include <iostream>
#include <math.h>
#include<iomanip>//指定输出精度
using namespace std;


const int maxn = 10000 + 5;
double pie[maxn];

int n,f;

bool IsOK(double area)
{
    int sum = 0;
    for (int i =0; i < n ; i++)
    {
        sum += floor(pie[i]/area);
    }
    return (sum>=f+1);
}

int main()
{
    int kcase ;
    cin >>kcase;
    while (kcase--)
    {
        cin>>n>>f;
        double maxarea = -1;
        for (int i=0; i< n; i++ )
        {
            int r;
            cin>>r;;
            pie[i] = M_PI*r*r;
            maxarea = max(maxarea,pie[i]);
        }
        double left = 0,right = maxarea;
        while (right-  left > 1e-6)
        {
            double middle = (left + right)/2;
            if (IsOK(middle))
                left = middle;
            else
                right = middle;
        }
        cout << fixed<<setprecision(4) << right << endl;
    }

    return 0;
}
