#include <iostream>
#include <stdio.h>

using namespace std;

/**
 * time: O(n), 50ms
 * space: O(1) 
 */ 
int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int a,  gap = 0, maxn ;
        scanf("%d%d", &a, &maxn);
        gap = a - maxn;
        maxn = max(a, maxn);
        n -= 2;
        while (n--)
        {
            scanf("%d", &a);
            int temp = maxn - a;
            gap = max(temp,gap);
            /* prepare for next one */
            maxn = max(a,maxn);
        }
        printf("%d\n",gap);
    }
    return 0;
}
