#include <iostream>
using namespace std;

int main()
{
    int N, A, B;
    int arr[20][20] = {};

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
            cin >> arr[i][j];
    }

    cin >> N;
    while (N--)
    {
        cin >> A >> B;
        for (int i = 1; i <= 19; i++)
        {
            arr[i][B] = !arr[i][B];
            arr[A][i] = !arr[A][i];
        }
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}