#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int P[MAX], D[MAX], ans;
vector<int> adj[MAX], cnt[MAX], sum[MAX];

void dfs(int node) {
    int X, Y;
    D[node] = 0, cnt[node].clear(), sum[node].clear();

    for (int i : adj[node]) {
        dfs(i), Y = 0;
        if (D[i] >= D[node])
            swap(cnt[node], cnt[i]), swap(sum[node], sum[i]), swap(D[node], D[i]);
        for (int j = D[i] - 1; j >= 0; j--) {
            X = D[i] - j, Y += cnt[node][D[node] - X] * X;
            ans += X * sum[node][D[node] - X] * cnt[i][j], ans += cnt[i][j] * Y;
            cnt[node][D[node] - X] += cnt[i][j], sum[node][D[node] - X] += sum[i][j];
        }
    }
    cnt[node].push_back(1), sum[node].push_back((sum[node].empty() ? 0 : sum[node].back()) + 1), D[node]++;
}

void solve() {
    int N, M, U, V;

    cin >> N >> M, ans = 0;
    for (int i = 1; i < N; i++)
        P[i] = i + 1;
    while (M--)
        cin >> U >> V, P[U] = max(P[U], V);

    for (int i = 1; i < N; i++)
        adj[P[i]].push_back(i);
    dfs(N), cout << ans << '\n';

    for (int i = 1; i <= N; i++)
        adj[i].clear();
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