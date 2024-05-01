#include <iostream>
#define int long long
using namespace std;

int arr[1010][1010], dp[1010][1010];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, A, B, C, D, W;
    cin >> N >> M >> K;

    while (K--)
    {
        cin >> A >> B >> C >> D >> W;
        dp[A][B] += W;
        dp[C + 1][D + 1] += W;
        dp[A][D + 1] -= W;
        dp[C + 1][B] -= W;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = arr[i][j - 1] + arr[i - 1][j] + dp[i][j] - arr[i - 1][j - 1];
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}