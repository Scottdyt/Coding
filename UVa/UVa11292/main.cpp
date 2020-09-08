#include <iostream>
#include <algorithm>
using namespace std;

int man[20000];
int head[20000];
int m,n;

int main()
{
    while (1)
    {
        cin>>n>>m;
        if (m == 0 && n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin>>head[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin>>man[i];
        }
        int cost = 0;
        int cur = 0;
        sort(head,head+n);
        sort(man,man+m);
        for (int i = 0;i < m;i++)
        {
            if (man[i] >= head[cur])
            {
                cost += man[i];
                if (++cur == n) break;
            }
        }
        if (cur < n) cout<<"Loowater is doomed!"<<endl;
        else cout<<cost<<endl;
    }
    return 0;
}


