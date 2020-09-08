#include <iostream>

using namespace std;

long long recursive(int p[],int i,int target)
{
    if (i == 0) return 0;
    if (p[i] == target)
        return recursive(p, i-1 ,target);
    return recursive(p, i-1 , 6 - p[i] - target) + (1LL<<(i-1));
}

const int maxn = 60+5;

int main()
{
    int start[maxn],finish[maxn],N;
    int kcase = 1;
    while (cin>>N && N)
    {
        for (int i = 1; i <= N; i++)
        {
            cin>>start[i];
        }
        for (int i = 1; i <= N; i++)
        {
            cin>>finish[i];
        }
        int k = N;
        long long  ans = 0;
        while (k >= 1 && start[k] == finish[k])
        {k--;
        }
        if (k >=1)
        {
            int other = 6 - start[k] - finish[k];
            ans = recursive(start,k-1,other) + recursive(finish,k-1,other) + 1;

        }
        cout<<"Case "<<kcase++<<": "<<ans<<endl;
    }
    return 0;
}
