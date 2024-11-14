#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int K, dp[MAX], depth[MAX];

void dfs(int X, int pr) {
    int A = 0, B = 0;

    for (int i : adj[X]) {
        if (i == pr)
            continue;
        depth[i] = depth[X] + 1;
        dfs(i, X);

        dp[X] += dp[i];
        if (depth[i] - depth[X] >= A)
            B = A, A = depth[i] - depth[X];
        else if (depth[i] - depth[X] > B)
            B = depth[i] - depth[X];
    }

    if (A + B >= K)
        dp[X]++, depth[X]--;
    else
        depth[X] += A;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    cin >> N >> K;

    for (int i = 1; i < N; i++) {
        cin >> A >> B;
        adj[A].push_back(B), adj[B].push_back(A);
    }

    dfs(1, 0);

    cout << dp[1] << '\n';

    return 0;
}