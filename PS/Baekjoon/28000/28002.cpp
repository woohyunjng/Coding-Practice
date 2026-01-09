#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 400001;

int S[MAX], uf[MAX], U[MAX], V[MAX], Z[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int N, M, Q, SM = 0, res = 0, R = 0, X, Y;
    vector<int> edge, ans;

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> S[i], uf[i] = i, Z[i] = S[i];
        SM = max(SM, S[i]);
        if (R == 0 || S[i] < S[R])
            R = i;
    }
    res += SM + S[R] * (N - 2);

    for (int i = 1; i <= M; i++)
        cin >> U[i] >> V[i], edge.push_back(i);

    sort(edge.begin(), edge.end(), [&](int x, int y) { return S[U[x]] + S[V[x]] < S[U[y]] + S[V[y]]; });

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    for (int i : edge) {
        X = find(U[i]), Y = find(V[i]);
        if (X == Y)
            continue;
        uf[X] = Y, pq.push({S[U[i]] + S[V[i]] - max(S[U[i]], S[V[i]]) - S[R], i});
    }

    for (int i = 1; i <= N; i++)
        uf[i] = i;

    ans.push_back(res);
    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (S[U[K[1]]] + S[V[K[1]]] - max(Z[find(U[K[1]])], Z[find(V[K[1]])]) - S[R] != K[0]) {
            pq.push({S[U[K[1]]] + S[V[K[1]]] - max(Z[find(U[K[1]])], Z[find(V[K[1]])]) - S[R], K[1]});
            continue;
        }

        res += K[0], ans.push_back(res);
        X = find(U[K[1]]), Y = find(V[K[1]]);
        uf[X] = Y, Z[Y] = min(Z[X], Z[Y]);
    }

    reverse(ans.begin(), ans.end());
    while (ans.size() <= Q)
        ans.push_back(ans.back());

    for (int i = 0; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}