#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N, i, j, arr[19][19];
    memset(arr, 0, sizeof(arr));
    cin >> N;

    while (N--)
    {
        cin >> i >> j;
        arr[--i][--j] = 1;
    }

    for (i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}