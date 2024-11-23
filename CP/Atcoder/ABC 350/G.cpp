#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 998244353

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int parent[MAX], sz[MAX], group[MAX], X[MAX];

void dfs(int K, int P, int X) {
    group[K] = X;

    for (int i : adj[K]) {
        if (i == P)
            continue;
        parent[i] = K;
        dfs(i, K, X);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, A, B, K = 0;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        group[i] = i, sz[i] = 1;

    while (Q--) {
        cin >> T >> A >> B;
        T = 1 + (T * (1 + X[K]) % MOD) % 2, A = 1 + (A * (1 + X[K]) % MOD) % N, B = 1 + (B * (1 + X[K]) % MOD) % N;

        if (T == 1) {
            if (sz[group[A]] < sz[group[B]])
                swap(A, B);
            adj[A].push_back(B), adj[B].push_back(A);
            parent[B] = A, sz[group[A]] += sz[group[B]], dfs(B, A, group[A]);
        } else {
            K++;
            if (parent[parent[A]] == B)
                X[K] = parent[A];
            else if (parent[parent[B]] == A)
                X[K] = parent[B];
            else if (parent[A] == parent[B])
                X[K] = parent[A];
            else
                X[K] = 0;
            cout << X[K] << '\n';
        }
    }

    return 0;
}