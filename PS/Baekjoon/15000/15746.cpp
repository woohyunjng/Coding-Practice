#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int L[MAX], dp[MAX], cnt[MAX];
bool T[MAX];

void dfs(int K) {
    cnt[K] = adj[K].empty();
    for (int i : adj[K]) {
        dfs(i);
        cnt[K] += cnt[i], dp[K] += dp[i] + L[i] * cnt[i];
    }
}

int dfs2(int K, int X) {
    int res = adj[K].empty() ? INF : dp[K] + X;
    for (int i : adj[K])
        res = min(res, dfs2(i, X + dp[K] - dp[i] - L[i] * cnt[i] + (cnt[1] - cnt[i]) * 3));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 0, K;
    string S;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> S >> M;
        if (M) {
            T[i] = false, L[i] = S.size() + 1;
            while (M--)
                cin >> K, adj[i].push_back(K);
        } else
            res += S.size(), T[i] = true;
    }

    dfs(1);
    cout << res + dfs2(1, 0) << '\n';

    return 0;
}