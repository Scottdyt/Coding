#include <iostream>
#include <vector>
#include <set>
#include <string.h>

using namespace std;

int N;       /* numbers of node */
int n, s, k; /* n is the nodes, s is server,k is distance */

const int maxn = 1000 + 10; /* max nodes */

vector<int> nodes[maxn];

vector<int> depth[maxn];

bool covered[maxn];

int fa[maxn];

void get_father(int point, int father, int dis)
{
    fa[point] = father;
    int num = nodes[point].size();
    if (num == 1 && dis > k)
        /* if point is client and depth >k , store the depth*/
        depth[dis].push_back(point);
    for (int i = 0; i < num; i++)
    {
        int child = nodes[point][i];
        if (child != father)
            get_father(child, point, dis + 1);
    }
}

/* set server on point */
void dfs(int point, int father, int dis)
{
    covered[point] = true;
    int num = nodes[point].size();
    for (int i = 0; i < num; i++)
    {
        int child = nodes[point][i];
        /* be careful child != father */
        if (child != father && dis < k)
            dfs(child, point, dis + 1);
    }
}

int solve()
{
    int ans = 0;
    memset(covered, 0, sizeof(covered));
    for (int d = n - 1; d > k; d--)
    {
        for (int i = 0; i < depth[d].size(); i++)
        {
            int point = depth[d][i];
            if (covered[point])
                continue;
            int temp = point;
            /* find dis = k father */
            for (int j = 0; j < k; j++)
                temp = fa[temp];

            dfs(temp, -1, 0);
            ans++;
        }
    }
    return ans;
}

int main()
{
    int kcase;

    cin >> kcase;
    for (int kk = 1; kk <= kcase; kk++)
    {
        cin >> n >> s >> k;
        for (int i = 1; i <= n; i++)
        {
            nodes[i].clear();
            depth[i].clear();
        }

        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }
        get_father(s, -1, 0);
        cout << solve() << endl;
    }
    return 0;
}
