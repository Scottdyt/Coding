#include <iostream>

using namespace std;


int N;

int recursive(int n)
{
    if (n == 1) return 1;
    else
        return recursive(n/2) + 1;
}

int main()
{
    while (cin>>N)
    {
        cout<<recursive(N)<<endl;
    }
    return 0;
}
