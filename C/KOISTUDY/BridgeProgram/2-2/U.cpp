#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H, W, N, L, D, X, Y, arr[101][101] = {};
    cin >> W >> H;
    cin >> N;

    while (N--)
    {
        cin >> L >> D >> X >> Y;
        for (int i = 0; i < L; i++)
        {
            if (!D)
                arr[X][Y + i] = 1;
            else
                arr[X + i][Y] = 1;
        }
    }

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}