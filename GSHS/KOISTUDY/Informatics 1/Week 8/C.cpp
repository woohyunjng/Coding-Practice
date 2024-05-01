#include <iostream>
using namespace std;

int main()
{
    int W, H, N, L, D, X, Y;
    cin >> H >> W;
    int arr[H + 1][W + 1] = {};

    cin >> N;
    while (N--)
    {
        cin >> L >> D >> Y >> X;
        if (D == 0)
        {
            for (int i = 0; i < L; i++)
                arr[Y][X + i] = 1;
        }
        else
        {
            for (int i = 0; i < L; i++)
                arr[Y + i][X] = 1;
        }
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}