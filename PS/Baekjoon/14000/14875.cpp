#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef array<ll, 2> pr;

const int MAX = 300001;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], R[MAX], C[MAX];
pr dp[MAX];
vector<int> adj[MAX];

void dfs1(int node, int par) {
    dp[node] = {A[node], -node};
    for (int i : adj[node]) {
        if (i == par)
            continue;
        dfs1(i, node), dp[node] = max(dp[node], {dp[i][0] - 1, dp[i][1]});
    }
}

void dfs2(int node, int par, pr val) {
    pr X, FM = val, SM = {-INF, 0};

    for (int i : adj[node]) {
        if (i == par)
            continue;
        X = {dp[i][0] - 1, dp[i][1]};
        if (X > FM)
            SM = FM, FM = X;
        else if (X > SM)
            SM = X;
    }

    R[node] = -FM[1], X = {A[node], -node};
    if (X > FM)
        SM = FM, FM = X;
    else if (X > SM)
        SM = X;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        X = (FM == pr{dp[i][0] - 1, dp[i][1]}) ? SM : FM;
        dfs2(i, node, {X[0] - 1, X[1]});
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;
    ll K, X = 0;
    vector<int> arr;

    cin >> N >> K;
    for (int i = 1 ; i <= N ; i ++)
        cin >> A[i], C[i] = -1;
    for (int i = 1 ; i < N ; i ++) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    dfs1(1, 0), dfs2(1, 0, {-INF, 0});
    
    V = 1, C[1] = 0, arr.push_back(V);
    while (X < K) {
        if (C[R[V]] != -1) {
            K = (K - X - 1) % (X - C[R[V]] + 1);
            cout << arr[C[R[V]] + K] << '\n';
            return 0;
        }
        V = R[V], C[V] = arr.size(), arr.push_back(V), X ++;
    }
    cout << V << '\n';

    return 0;
}