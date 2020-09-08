#include <iostream>

using namespace std;

int n;

const int maxn = 1000000 + 10;
int guard[maxn], Left[maxn], Right[maxn];

int test(int p)
/* Left = [1,...,r1]
   Right = [r1+1,...p]
 */
{
    int x = guard[1], y = p - guard[1];
    Left[1] = x;
    Right[1] = 0;
    for (int i = 2 ;i <= n; i++)
    {
        if (i % 2)
        /* if odd */
        {
            /* get Right side as much as posible, except those token by i-1 */
            Right[i] = min(y - Right[i - 1], guard[i]);
            Left[i] = guard[i] - Right[i];
        }
        else
        /* if even */
        {
            /* get Left side as much as posible, except those token by i -1 */
            Left[i] = min(x - Left[i - 1], guard[i]);
            Right[i] = guard[i] - Left[i];
        }
    }
    /* test Left side of n is zero,if zero, p is ok */
    return Left[n] == 0;
}

int main()
{
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> guard[i];
        }
        guard[n + 1] = guard[1];

        if (n == 1)
        {
            cout << guard[1] << endl;
            continue;
        }
        int R = 0, L = 0;
        for (int i = 1; i <= n; i++)
            L = max(L, guard[i + 1]+guard[i]);
        if (n % 2)
        {
            for (int i = 1; i <= n; i++)
                R = max(R, guard[i] * 3);
            while (L < R)
            {
                int middle = (R + L) / 2;
                if (test(middle))
                    R = middle;
                else
                    L = middle + 1;
            }
        }
        cout << L << endl;
    }
    return 0;
}
