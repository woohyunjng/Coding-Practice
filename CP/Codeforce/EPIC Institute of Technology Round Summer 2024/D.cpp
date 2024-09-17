#include <bits/stdc++.h>
#define int long long

#define MAX 5010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int cnt[MAX], dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res, X, Y;
    vector<int> arr;
    cin >> T;

    while (T--) {
        cin >> N;

        fill(cnt, cnt + N + 1, 0);
        fill(dp[0], dp[N + 1], INF);

        for (int i = 1; i <= N; i++) {
            cin >> X;
            cnt[X]++;
        }

        arr.clear();
        for (int i = 1; i <= N; i++) {
            if (!cnt[i])
                continue;
            arr.push_back(cnt[i]);
        }

        N = arr.size();
        for (int i = 0; i < N; i++) {
            dp[i][0] = 0;
            for (int j = 1; j < i + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                if (dp[i - 1][j - 1] + arr[i] <= i - (j - 1))
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + arr[i]);
            }
        }

        X = 0;
        for (int i = 0; i <= N; i++) {
            if (dp[N - 1][i] != INF)
                X = i;
        }

        cout << N - X << '\n';
    }

    return 0;
}