#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 400001;

int parent[MAX], sz[MAX], U[MAX], V[MAX], S[MAX], ans[MAX], A[MAX], B[MAX];
vector<int> rollback_st;
map<pr, vector<int>> edge, queries;

int find(int X) { return parent[X] == X ? X : find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (sz[X] < sz[Y])
        swap(X, Y);
    rollback_st.push_back(Y);
    sz[X] += sz[Y], parent[Y] = X;
}

void rollback() {
    int K = rollback_st.back();
    rollback_st.pop_back();
    sz[parent[K]] -= sz[K], parent[K] = K;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, C, Q;
    set<pr> st;

    cin >> N >> M >> K;

    for (int i = 1; i <= M; i++)
        cin >> U[i] >> V[i];
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        parent[i] = i, sz[i] = 1;
    }

    for (int i = 1; i <= M; i++) {
        if (S[U[i]] == S[V[i]])
            uni(U[i], V[i]);
        else {
            if (S[U[i]] > S[V[i]])
                swap(U[i], V[i]);
            edge[{S[U[i]], S[V[i]]}].push_back(i);
        }
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> A[i] >> B[i];
        if (S[A[i]] > S[B[i]])
            swap(A[i], B[i]);
        queries[{S[A[i]], S[B[i]]}].push_back(i), st.insert({S[A[i]], S[B[i]]});
    }

    for (pr i : st) {
        C = 0;
        for (int j : edge[i]) {
            X = U[j], Y = V[j];
            if (find(X) != find(Y))
                uni(X, Y), C++;
        }

        for (int j : queries[i]) {
            X = A[j], Y = B[j];
            ans[j] = find(X) == find(Y);
        }

        while (C--)
            rollback();
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}