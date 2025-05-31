#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600001;

int X[MAX], Y[MAX], Z[MAX], V[MAX], ans[MAX], A[MAX], B[MAX], in[MAX], dp[MAX];

vector<int> adj[MAX];

void solve() {
    int N, M, P, Q;
    bool flag = true;

    cin >> N >> Q, M = N;
    for (int i = 1; i <= N; i++)
        cin >> B[i], V[i] = i;
    for (int i = 1; i <= Q; i++) {
        cin >> X[i] >> Y[i] >> Z[i], M++;
        adj[M].push_back(V[X[i]]), in[V[X[i]]]++;
        adj[M].push_back(V[Y[i]]), in[V[Y[i]]]++;
        V[Z[i]] = M;
    }

    for (int i = 1; i <= N; i++)
        dp[V[i]] = B[i];

    queue<int> q;
    for (int i = 1; i <= M; i++)
        if (in[i] == 0)
            q.push(i);

    while (!q.empty()) {
        P = q.front(), q.pop();
        for (int i : adj[P]) {
            dp[i] = max(dp[i], dp[P]);
            if (--in[i] == 0)
                q.push(i);
        }
    }

    for (int i = 1; i <= N; i++)
        ans[i] = A[i] = dp[i];

    for (int i = 1; i <= Q; i++)
        A[Z[i]] = min(A[X[i]], A[Y[i]]);
    for (int i = 1; i <= N; i++)
        flag &= A[i] == B[i];

    if (flag) {
        for (int i = 1; i <= N; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    } else
        cout << -1 << '\n';

    for (int i = 1; i <= M; i++)
        adj[i].clear(), in[i] = dp[i] = 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}