#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxn  = 1000 + 10;
int cnt = 0;

int  n; //预算和组件数目
int budget;

struct Compont {
	int price;
	int quality;
};


std::vector<Compont> comp[maxn]; //每一项都是vector的数组
std::map<string, int> ID;

int convert(string type)
{
	if (!ID.count(type))
	{	//如果还没有这个类型的组件
		ID[type] = cnt++;
	}
	return ID[type];
}

//看品质不小于q的组件是否能在预算范围内组装
bool judge(int q)
{
	int  sum = 0;
	for (int i = 0 ; i < cnt; i++)
	{
		int cheapest = budget;
		int m = comp[i].size();
		for (int j = 0; j < m; j++)
		{
			if (comp[i][j].quality >= q)
				cheapest = min(cheapest, comp[i][j].price);
		}
		sum += cheapest;
		//若没加这一句，则不能AC
		if(cheapest == budget)
            return false;

		if (sum > budget)
			return false;
	}
	return true;
}





int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		cin >> n >> budget;
		cnt = 0;
		for (int i = 0 ; i < n ; i++)
		{
			comp[i].clear();
		}
		ID.clear();
		int maxq = 0;
		for (int i  = 0 ; i < n; i++)
		{
			string type, name;
			int p, q;
			cin >> type >> name >> p >> q;
			maxq = max(maxq, q);
			comp[convert(type)].push_back((Compont) {p, q});
		}

        //使用二分法来加快速度
		int left = 0,right = maxq;
		while (left < right)
		{
		    int middle = (right+left+1)/2 ;
		    //int middle = (right+left)/2 ; 为什么不可以？
			if (judge(middle))
				left = middle;
            else
            {
                right = middle - 1;
            }
		}
		cout << left << endl;
	}



	return 0;
}
