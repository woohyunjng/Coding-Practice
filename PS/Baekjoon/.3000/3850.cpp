#include <bits/stdc++.h>
#define int long long

#define MAX 22
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];

int cnt[MAX], dp[1 << MAX], parent[1 << MAX], res[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;
    queue<int> q;
    vector<int> ans;

    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0)
            break;

        while (M--) {
            cin >> X >> Y;
            adj[X].push_back(Y), adj[Y].push_back(X);
        }

        q.push((1 << N) - 1);
        fill(dp, dp + (1 << N), -1), dp[(1 << N) - 1] = 0;

        while (!q.empty()) {
            X = q.front(), q.pop(), Y = 0;
            fill(cnt, cnt + N, 0);

            for (int i = 0; i < N; i++)
                if (X & (1 << i))
                    for (int j : adj[i])
                        Y |= (1 << j), cnt[j]++;

            for (int i = 0; i < N; i++) {
                if ((X & (1 << i)) == 0)
                    continue;
                Z = Y;
                for (int j : adj[i])
                    if (cnt[j] == 1)
                        Z ^= (1 << j);
                if (dp[Z] == -1) {
                    dp[Z] = dp[X] + 1, parent[Z] = X, res[Z] = i;
                    q.push(Z);
                }
            }
        }

        if (dp[0] == -1)
            cout << "Impossible" << '\n';
        else {
            cout << dp[0] << ":";
            ans.clear();
            for (X = 0; X < (1 << N) - 1; X = parent[X])
                ans.push_back(res[X]);
            reverse(ans.begin(), ans.end());
            for (int i : ans)
                cout << ' ' << i;
            cout << '\n';
        }

        for (int i = 0; i < N; i++)
            adj[i].clear();
    }

    return 0;
}