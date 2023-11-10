#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[10][10], i = 1, j = 1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cin >> arr[i][j];
    }

    arr[1][1] = 9;
    while ((arr[i + 1][j] != 1) || (arr[i][j + 1] != 1))
    {
        if (arr[i][j + 1] != 1)
            j += 1;
        else
            i += 1;

        if (arr[i][j] == 2)
        {
            arr[i][j] = 9;
            break;
        }
        arr[i][j] = 9;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}