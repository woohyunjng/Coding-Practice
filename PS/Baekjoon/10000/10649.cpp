#include <bits/stdc++.h>
#define int long long

#define MAX 21
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int T[MAX], W[MAX], F[MAX], dp[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, H, res = -1, X, Y;

    cin >> N >> H;
    fill(dp, dp + (1 << N), -1);

    for (int i = 0; i < N; i++)
        cin >> T[i] >> W[i] >> F[i], dp[1 << i] = F[i];

    for (int i = 0; i < (1 << N); i++) {
        X = 0, Y = 0;
        for (int j = 0; j < N; j++)
            if (i & (1 << j))
                X += T[j], Y += W[j];
        if (X >= H)
            res = max(res, dp[i]);

        for (int j = 0; j < N; j++) {
            if ((i & (1 << j)) || F[j] < Y)
                continue;
            dp[i | (1 << j)] = max(dp[i | (1 << j)], min(dp[i], F[j] - Y));
        }
    }

    if (res == -1)
        cout << "Mark is too tall\n";
    else
        cout << res << endl;

    return 0;
}