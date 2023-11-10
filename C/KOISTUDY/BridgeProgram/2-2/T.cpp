#include <iostream>
using namespace std;

int main()
{
    int N, A, B, arr[19][19];
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> N;
    while (N--)
    {
        cin >> A >> B;
        for (int i = 0; i < 19; i++)
            arr[i][B - 1] = !arr[i][B - 1];
        for (int i = 0; i < 19; i++)
            arr[A - 1][i] = !arr[A - 1][i];
    }

    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}