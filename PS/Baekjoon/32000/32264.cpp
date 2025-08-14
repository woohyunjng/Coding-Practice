#include "tree.h"

#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int S[MAX][2], LF, leaf[MAX], uf[MAX], M[MAX], sz[MAX];
vector<int> cnt, adj[MAX];

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }

void init(vector<signed> P, vector<signed> W) {
    vector<int> arr;
    vector<pr> val;
    int N = W.size(), X;

    for (int i = 1; i < N; i++)
        adj[P[i]].push_back(i);

    for (int i = 0; i < N; i++) {
        if (adj[i].empty())
            LF += W[i], W[i] = 0;
        else
            arr.push_back(i);
        uf[i] = i, leaf[i] = 1, M[i] = INF;
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return W[x] > W[y]; });
    for (int i : arr) {
        X = find(i);
        if (M[X] != INF)
            val.push_back({leaf[X], M[X] - W[i]});
        M[X] = min(M[X], (int)W[i]), leaf[X]--;
        for (int j : adj[i]) {
            uf[j] = X, leaf[X] += leaf[j], M[X] = min(M[X], (int)W[i]);
            if (M[j] != INF)
                val.push_back({leaf[j], M[j] - W[i]});
        }
    }
    if (M[0] != INF) {
        val.push_back({leaf[0], M[0]});
    }

    sort(val.begin(), val.end());
    for (int i = 1; i <= val.size(); i++) {
        cnt.push_back(val[i - 1][0]);
        S[i][0] = S[i - 1][0] + val[i - 1][0] * val[i - 1][1];
        S[i][1] = S[i - 1][1] + val[i - 1][1];
    }
}

int query(signed L, signed R) {
    int ans = LF * L, X = lower_bound(cnt.begin(), cnt.end(), (R + L - 1) / L) - cnt.begin();
    ans += (S[cnt.size()][0] - S[X][0]) * L;
    ans -= (S[cnt.size()][1] - S[X][1]) * R;
    return ans;
}