#include <bits/stdc++.h>
#pragma GCC optimize("o3,Ofast,unroll-loops")
#define int long long

using namespace std;

const int MAX = 500001;
const int INF = 1e9;

int U[MAX], V[MAX], C[MAX], T[MAX], uf[MAX], chk[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X != Y)
        uf[Y] = X;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, W, X, ans = -1, L, R, cnt, P[2];
    vector<int> arr, ver[2];

    cin >> N >> M >> K >> W;
    while (K--)
        cin >> X, T[X] = 1;

    for (int i = 1; i <= M; i++) {
        cin >> U[i] >> V[i] >> C[i];
        chk[i] = T[U[i]] ^ T[V[i]];
        ver[chk[i]].push_back(i), arr.push_back(i);
    }

    sort(ver[0].begin(), ver[0].end(), [&](int x, int y) { return C[x] < C[y]; });
    sort(ver[1].begin(), ver[1].end(), [&](int x, int y) { return C[x] < C[y]; });

    for (int st = -INF, en = INF, md; st <= en;) {
        md = st + en >> 1, K = L = R = cnt = 0;

        for (int i = 1; i <= N; i++)
            uf[i] = i;
        arr.clear(), P[0] = P[1] = 0;
        while (P[0] < ver[0].size() || P[1] < ver[1].size()) {
            if (P[0] == ver[0].size())
                arr.push_back(ver[1][P[1]++]);
            else if (P[1] == ver[1].size())
                arr.push_back(ver[0][P[0]++]);
            else if (C[ver[0][P[0]]] < C[ver[1][P[1]]] + md)
                arr.push_back(ver[0][P[0]++]);
            else if (C[ver[1][P[1]]] + md < C[ver[0][P[0]]])
                arr.push_back(ver[1][P[1]++]);
            else
                arr.push_back(ver[0][P[0]++]);
        }
        for (int i : arr) {
            if (find(U[i]) == find(V[i]))
                continue;
            uni(U[i], V[i]), K += C[i] + (chk[i] ? md : 0), L += chk[i], cnt++;
        }

        for (int i = 1; i <= N; i++)
            uf[i] = i;
        arr.clear(), P[0] = P[1] = 0;
        while (P[0] < ver[0].size() || P[1] < ver[1].size()) {
            if (P[0] == ver[0].size())
                arr.push_back(ver[1][P[1]++]);
            else if (P[1] == ver[1].size())
                arr.push_back(ver[0][P[0]++]);
            else if (C[ver[0][P[0]]] < C[ver[1][P[1]]] + md)
                arr.push_back(ver[0][P[0]++]);
            else if (C[ver[1][P[1]]] + md < C[ver[0][P[0]]])
                arr.push_back(ver[1][P[1]++]);
            else
                arr.push_back(ver[1][P[1]++]);
        }
        for (int i : arr) {
            if (find(U[i]) == find(V[i]))
                continue;
            uni(U[i], V[i]), R += chk[i];
        }

        if (L <= W && W <= R && cnt == N - 1) {
            ans = K - W * md;
            break;
        }

        if (R < W)
            en = md - 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}