#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int arr[N][N];
    for (int i = 0; i <= (N - 1) / 2; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            arr[j - 1][N - 1 - i] = j * (i + 1);
            arr[j - 1][i] = j * (i + 1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}