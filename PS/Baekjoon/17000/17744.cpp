#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int N, ans[MAX], M[2], A[MAX], X[2][MAX], Y[2][MAX], parent[2][MAX], in[2][MAX], out[2][MAX], G[MAX];
vector<int> adj[2][MAX], val[MAX];

int find(int t, int X) { return parent[t][X] == X ? X : parent[t][X] = find(t, parent[t][X]); }
void uni(int t, int X, int Y) {
    X = find(t, X), Y = find(t, Y);
    if (X == Y)
        return;
    if (X > Y)
        swap(X, Y);
    parent[t][Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, U, V, K;
    vector<int> queries, narr;
    vector<pr> arr;
    multiset<int> st;

    cin >> N >> M[0] >> M[1] >> Q;

    for (int i = 1; i <= M[0]; i++)
        cin >> X[0][i] >> Y[0][i];
    for (int i = 1; i <= N + M[0]; i++)
        parent[0][i] = i, in[0][i] = MAX, out[0][i] = -1;
    for (int i = 1 + M[0]; i <= N + M[0]; i++)
        in[0][i] = i - M[0], out[0][i] = i - M[0];

    for (int i = 1; i < N + M[0]; i++) {
        cin >> T >> U >> V;
        if (T == 1)
            U += M[0];
        if (Y[0][U] > Y[0][V] || (Y[0][U] == Y[0][V] && U > V))
            swap(U, V);
        arr.push_back({U, V});
    }

    sort(arr.begin(), arr.end(), [&](pr x, pr y) { return Y[0][x[1]] < Y[0][y[1]]; });
    for (pr i : arr) {
        U = find(0, i[0]), V = find(0, i[1]);
        if (U < V)
            swap(U, V);
        parent[0][U] = V;
        if (out[0][U] + 1 == in[0][V])
            val[i[1]].push_back(out[0][U]);
        else if (out[0][V] + 1 == in[0][U])
            val[i[1]].push_back(out[0][V]);
        in[0][V] = min(in[0][V], in[0][U]), out[0][V] = max(out[0][V], out[0][U]);
    }

    arr.clear();
    for (int i = 1; i <= M[1]; i++)
        cin >> X[1][i] >> Y[1][i], Y[1][i] = -Y[1][i];
    for (int i = 1; i <= N + M[1]; i++)
        parent[1][i] = i, in[1][i] = MAX, out[1][i] = -1;
    for (int i = 1 + M[1]; i <= N + M[1]; i++)
        in[1][i] = i - M[1], out[1][i] = i - M[1];

    for (int i = 1; i < N + M[1]; i++) {
        cin >> T >> U >> V;
        if (T == 1)
            U += M[1];
        if (Y[1][U] > Y[1][V] || (Y[1][U] == Y[1][V] && U > V))
            swap(U, V);
        arr.push_back({U, V});
    }

    sort(arr.begin(), arr.end(), [&](pr x, pr y) { return Y[1][x[1]] < Y[1][y[1]]; });
    for (pr i : arr) {
        U = find(1, i[0]), V = find(1, i[1]);
        if (U < V)
            swap(U, V);
        parent[1][U] = V;
        if (out[1][U] + 1 == in[1][V])
            G[out[1][U]] = Y[1][i[1]];
        else if (out[1][V] + 1 == in[1][U])
            G[out[1][V]] = Y[1][i[1]];
        in[1][V] = min(in[1][V], in[1][U]), out[1][V] = max(out[1][V], out[1][U]);
    }

    for (int i = 1; i < N; i++)
        st.insert(G[i]);
    st.insert(0);

    K = 0;
    for (int i = 1; i <= M[0]; i++)
        narr.push_back(i);
    sort(narr.begin(), narr.end(), [&](int x, int y) { return Y[0][x] < Y[0][y]; });

    for (int i = 1; i <= Q; i++)
        cin >> A[i], queries.push_back(i);
    sort(queries.begin(), queries.end(), [&](int x, int y) { return A[x] < A[y]; });

    for (int i : queries) {
        while (K < M[0] && Y[0][narr[K]] <= A[i]) {
            for (int j : val[narr[K]])
                st.erase(st.find(G[j]));
            K++;
        }
        ans[i] = -*st.rbegin();
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}