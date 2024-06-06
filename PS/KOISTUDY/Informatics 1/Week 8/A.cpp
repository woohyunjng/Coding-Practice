#include <iostream>
using namespace std;

int main()
{
    int N, A, B;
    int arr[20][20] = {};

    cin >> N;
    while (N--)
    {
        cin >> A >> B;
        arr[A][B] = 1;
    }

    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}