#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MAX_LOG 20

using namespace std;

int P[MAX], uf_pr[MAX], root[MAX], parent[MAX][MAX_LOG], depth[MAX], res[MAX];
vector<int> adj[MAX];

int find(int X) {
    if (uf_pr[X] != X)
        uf_pr[X] = find(uf_pr[X]);
    return uf_pr[X];
}

int lca(int A, int B) {
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[A][i] != parent[B][i])
            A = parent[A][i], B = parent[B][i];
    }
    if (A != B)
        A = parent[A][0];
    return A;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    cin >> N;

    vector<int> arr;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        arr.push_back(i), uf_pr[i] = i;
    }

    sort(arr.begin(), arr.end(), [&](int A, int B) { return P[A] < P[B]; });

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        X = st.top(), st.pop();

        for (int i : adj[X]) {
            if (i == parent[X][0])
                continue;
            parent[i][0] = X, depth[i] = depth[X] + 1;

            for (int j = 1; j < MAX_LOG; j++) {
                if (!parent[i][j - 1])
                    break;
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
            st.push(i);
        }
    }

    for (int i : arr) {
        for (int j : adj[i]) {
            if (P[j] > P[i])
                continue;

            X = find(j), Y = find(i);
            res[i] = max(
                res[i],
                res[root[X]] + depth[root[X]] + depth[i] - 2 * depth[lca(root[X], i)]);

            if (X > Y)
                swap(X, Y);
            uf_pr[Y] = X;
        }

        root[find(i)] = i;
    }

    cout << res[max_element(P + 1, P + N + 1) - P];

    return 0;
}