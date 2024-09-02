#include <bits/stdc++.h>
#define int long long

#define MAX 300100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, cnt = 0, arr[20][MAX], inp[MAX], cur[MAX], dp[MAX];

void dfs(int K, int depth) {
    if (K > N)
        return;
    dfs(K << 1, depth + 1);
    arr[depth][++cnt] = inp[K];
    dfs(K << 1 | 1, depth + 1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res = -INF;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> inp[i];

    for (int i = 1; (1 << i) - 1 <= N; i++)
        fill(arr[i], arr[i] + MAX, -INF);

    dfs(1, 1);

    for (int i = 1; (1 << i) - 1 <= N; i++) {
        for (int j = 1; j <= N; j++)
            cur[j] = -INF;

        for (int j = i; (1 << j) - 1 <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (arr[j][k] == -INF)
                    continue;
                cur[k] = arr[j][k];
            }

            for (int k = 1; k <= N; k++) {
                if (cur[k] == -INF)
                    dp[k] = dp[k - 1];
                else {
                    dp[k] = max(dp[k - 1], 0ll) + cur[k];
                    res = max(res, dp[k]);
                }
            }
        }
    }

    cout << res;

    return 0;
}