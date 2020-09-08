#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000000 + 10;
long long C[maxn],M,tot;

int main()
{
    int n;
    while (cin>>n)
    {
        tot = 0;
        long long x = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>x;
            tot += x;
            C[i] = tot;
        }
        M = tot/n;
        for (int i = 0; i < n;i++)
        {
            C[i] -= M*(i+1);
        }
        sort(C,C+n);
        long long x1 = C[n/2],ans = 0;
        for (int i =0; i < n; i++)
            ans += abs(x1 - C[i]);
        cout<<ans<<endl;
    }
    return 0;
}
