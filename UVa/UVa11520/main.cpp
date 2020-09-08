#include <iostream>
#include <string.h>

using namespace std;

int N;

int alphabets[11][11];

int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1}; /* up down left right */

/* return 0 means OK, else indicats the dirction */
int check(int row, int col)
{
    for (int i = 0; i < 4; i++)
    {
        int n_row = dir[i][0] + row;
        int n_col = dir[i][1] + col;
        // cout << "x: " << row << " y: " << col << endl;
        // cout << "new x: " << n_row << " new y: " << n_col << endl;
        /* if bounded */
        if (n_row >= 1 && n_row <= N && n_col >= 1 && n_col <= N)
        {
            if (alphabets[n_row][n_col] == alphabets[row][col])
                return i + 1;
        }
    }
    return 0;
}

void init()
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
            alphabets[i][j] = -1;
    }
    return;
}

void read_data()
{
    cin >> N;
    init();
    char temp;
    int i = 1, j = 1;
    while (i <= N)
    {
        if (j > N)
        {
            j = 1;
            i++;
        }
        else
        {
            cin >> temp;
            if (temp != '.')
                alphabets[i][j] = (int)(temp - 'A');
            j++;
        }
    }
}

void print()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            char temp = 'A' + alphabets[i][j];
            cout << temp;
        }
        cout << endl;
    }
}

int procss(int row, int col)
{
    int flag = 0;
    if (row > N)
        return 1;
    /* if the char has been setted */
    if (alphabets[row][col] != -1)
        flag = 1;

    /* find the least alphabets */
    for (int i = 0; i < 26; i++)
    {
        if (flag)
            break;

        alphabets[row][col] = i;

        if (check(row, col) == 0)
            break;
    }
    /* look for next position */
    if (col == N)
        procss(row + 1, 1);
    else
        procss(row, col + 1);
}

int main()
{
    int kcase, number = 1;
    cin >> kcase;
    while (kcase--)
    {
        read_data();
        procss(1, 1);
        cout << "Case " << number++ << ":" << endl;
        print();
    }
    return 0;
}
