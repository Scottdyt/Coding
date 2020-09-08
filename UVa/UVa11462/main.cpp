#include <iostream>
#include <string.h>

using namespace std;


int age[101];

int main()
{
    int n;
    while (cin>>n && n)
    {
        int temp;
        memset(age,0,sizeof(age));
        for (int i =0; i <n; i++)
        {
            cin>>temp;
            age[temp]++;
        }
        int first = 0;
        for (int i = 1; i<=100; i++)
        {
            for (int j = 1; j <= age[i]; j++)
            {
                if (!first)
                    first++;
                else{
                    cout<<" ";
               }
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
