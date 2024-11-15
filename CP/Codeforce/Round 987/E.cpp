#include <bits/stdc++.h>
#define int long long

#define MAX 1000100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], dp[MAX];
vector<int> child[MAX];

void dfs(int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int X, Y;

    for (int i : child[K]) {
        dfs(i);
        pq.push(dp[i]);
    }

    while (pq.size() > 2) {
        X = pq.top(), pq.pop();
        Y = pq.top(), pq.pop();

        pq.push(Y + 1);
    }

    if (pq.empty())
        dp[K] = 0;
    else {
        X = 0;
        while (!pq.empty())
            X = max(X, pq.top()), pq.pop();
        dp[K] = X + 1;
    }
}

void solve() {
    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        cin >> P[i];
        child[P[i]].push_back(i);
    }

    dfs(1);

    cout << dp[1] << '\n';

    for (int i = 1; i <= N; i++)
        child[i].clear();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}