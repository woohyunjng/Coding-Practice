#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
int dp[MAX][2], sm[MAX];

int dfs(int K, int pr, int dep) {
    int X = dep;

    dp[K][0] = dep;

    for (int i : arr[K]) {
        if (i == pr)
            continue;

        X = max(X, dfs(i, K, dep + 1));
    }

    dp[K][1] = X;

    return X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, A, B, res;
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 1; i < N; i++) {
            cin >> A >> B;
            arr[A].push_back(B);
            arr[B].push_back(A);
        }

        dfs(1, 0, 1);

        fill(sm, sm + N + 1, 0);

        for (int i = 1; i <= N; i++) {
            sm[dp[i][0]]++;
            sm[dp[i][1] + 1]--;
        }

        res = 0;
        for (int i = 1; i <= N; i++) {
            sm[i] += sm[i - 1];
            res = max(res, sm[i]);
        }

        cout << N - res << '\n';

        for (int i = 1; i <= N; i++)
            arr[i].clear();
    }

    return 0;
}