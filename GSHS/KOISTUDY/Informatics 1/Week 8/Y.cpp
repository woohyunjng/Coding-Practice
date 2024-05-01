#include <iostream>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, Q, A, B, C, D, W;
    cin >> N >> Q;

    int arr[N][N] = {}, dp[N][N] = {};
    while (Q--)
    {
        cin >> A >> B >> C >> D >> W;
        B--;
        --C;
        for (int i = --A; i <= C; i++)
        {
            dp[i][B] += W;
            if (D < N)
                dp[i][D] -= W;
        }
    }

    for (int i = 0; i < N; i++)
        arr[i][0] = dp[i][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
            arr[i][j] = arr[i][j - 1] + dp[i][j];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}