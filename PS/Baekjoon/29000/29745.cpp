#include "closing.h"

#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 400001;
const int INF = 0x3f3f3f3f3f3f3f3f;

vector<pr> adj[MAX];
int D[MAX][2], parent[MAX], V[MAX][4], L[4];
bool vst[MAX];

void dfs(int node, int par, int t) {
    parent[node] = par;
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        D[i[0]][t] = D[node][t] + i[1];
        dfs(i[0], node, t);
    }
}

void dnc(int l, int r, int optl, int optr) {
    if (l > r)
        return;
    int m = l + r >> 1, opt = -1, val;
    V[m][3] = INF;
    for (int i = max(m - L[1], optl); i <= min(m, optr); i++) {
        val = V[m - i][1] + V[i][2];
        if (val < V[m][3])
            V[m][3] = val, opt = i;
    }

    dnc(l, m - 1, optl, opt), dnc(m + 1, r, opt, optr);
}

signed max_score(signed N, signed X, signed Y, int K,
                 vector<signed> _U, vector<signed> _V, vector<signed> _W) {
    for (int i = 0; i < N; i++) {
        adj[i].clear(), D[i][0] = D[i][1] = 0;
        parent[i] = -1, vst[i] = false;
    }

    for (int i = 1; i <= N << 1; i++)
        fill(V[i], V[i] + 4, INF);
    fill(V[0], V[0] + 4, 0), fill(L, L + 4, 0);

    int ans = 0, A, B, S = 0, val;
    vector<int> arr, path;
    vector<pr> lst;

    for (int i = 0; i < N - 1; i++) {
        adj[_U[i]].push_back({_V[i], _W[i]});
        adj[_V[i]].push_back({_U[i], _W[i]});
    }

    dfs(X, -1, 0), dfs(Y, -1, 1);
    A = X;
    while (A != parent[Y])
        path.push_back(A), A = parent[A];

    for (int i = 0; i < N; i++) {
        if (D[i][0] > D[i][1])
            swap(D[i][0], D[i][1]);
        arr.push_back(D[i][0]);
    }

    sort(arr.begin(), arr.end());
    for (int i : arr)
        if (S + i <= K)
            S += i, ans++;
    arr.clear();

    val = 0;
    L[0] = (int)path.size(), V[L[0]][0] = 0;

    for (int i : path) {
        arr.push_back(D[i][1] - D[i][0]);
        vst[i] = true, V[L[0]][0] += arr.back();
        K -= D[i][0], val++;
    }
    if (K < 0)
        return ans;

    sort(arr.begin(), arr.end());
    for (int i = L[0] - 1; i >= 0; i--)
        V[i][0] = V[i + 1][0] - arr.back(), arr.pop_back();
    arr.clear();

    multiset<int> st[2];

    for (int i = 0; i < N; i++) {
        if (vst[i])
            continue;
        if (D[i][0] * 2 <= D[i][1])
            arr.push_back(D[i][0]), arr.push_back(D[i][1] - D[i][0]);
        else {
            lst.push_back({D[i][0], D[i][1] - D[i][0]});
            st[0].insert(D[i][0]);
        }
    }

    sort(arr.begin(), arr.end());

    L[1] = arr.size();
    for (int i = 1; i <= L[1]; i++)
        V[i][1] = V[i - 1][1] + arr[i - 1];
    arr.clear();

    sort(lst.begin(), lst.end(), [&](pr x, pr y) { return x[0] + x[1] < y[0] + y[1]; });
    L[2] = lst.size() << 1;

    for (int i = 0; i < lst.size(); i++) {
        V[i << 1 | 1][2] = V[i << 1][2] + (*st[0].begin());
        V[(i + 1) << 1][2] = V[i << 1][2] + lst[i][0] + lst[i][1];

        st[0].erase(st[0].find(lst[i][0])), st[1].insert(lst[i][1]);
        V[i << 1 | 1][2] = min(V[i << 1 | 1][2], V[(i + 1) << 1][2] - (*st[1].rbegin()));
    }

    L[3] = L[1] + L[2];
    dnc(1, L[3], 0, L[2]);

    for (int i = 0; i <= L[0]; i++) {
        while (L[3] >= 0 && V[i][0] + V[L[3]][3] > K)
            L[3]--;
        if (L[3] >= 0)
            ans = max(ans, i + L[3] + val);
    }

    return ans;
}