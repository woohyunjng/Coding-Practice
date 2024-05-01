#include <iostream>
using namespace std;

int main()
{
    int arr[10][10] = {}, y = 1, x = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];
    }

    while (true)
    {
        arr[y][x] = 9;
        if (!arr[y][x + 1])
            x += 1;
        else if (!arr[y + 1][x])
            y += 1;
        else
        {
            if (arr[y][x + 1] == 2)
                arr[y][x + 1] = 9;
            if (arr[y + 1][x] == 2)
                arr[y + 1][x] = 9;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}