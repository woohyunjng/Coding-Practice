#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 300001;

vector<pr> adj[MAX], st, val;
vector<tp> cnt;
vector<int> lst;

int N, ans[MAX][2], sz[MAX], S[MAX], C[MAX], CV[MAX], AS, T[MAX], P[MAX][2], SM[MAX][2], PV;
bool vst[MAX];

int get_sz(int node, int par) {
    sz[node] = 1;
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        sz[node] += get_sz(i[0], node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        if (sz[i[0]] * 2 > cap)
            return get_cent(i[0], node, cap);
    }
    return node;
}

void dfs(int node, int par, int dis, int min_dis, int max_dis, int t) {
    pr V;
    int X = PV, Y = -1;
    bool pushed = false;

    C[node] = max_dis;

    for (int str = 0, en = PV, md; str <= en;) {
        md = str + en >> 1;
        if (st[md][0] > dis)
            Y = md, str = md + 1;
        else
            en = md - 1;
    }

    CV[node] = Y < 0 ? 0 : (st[Y][1] + 1), PV = Y;
    if (PV + 1 < st.size())
        V = st[++PV], st[PV] = {dis, CV[node]};
    else
        pushed = true, st.push_back({dis, CV[node]}), PV++;

    AS += dis, S[t] += dis, T[node] = t;
    val.push_back({min_dis, t}), lst.push_back(node);
    for (pr i : adj[node]) {
        if (i[0] == par || vst[i[0]])
            continue;
        if (dis + i[1] < min_dis)
            cnt.push_back({dis + i[1], sz[i[0]], t});
        dfs(i[0], node, dis + i[1], min(min_dis, dis + i[1]), max(max_dis, dis + i[1]), t);
    }

    if (pushed)
        st.pop_back();
    else
        st[PV] = V;
    PV = X;
}

void dnc(int node) {
    int cent = get_cent(node, -1, get_sz(node, -1)), X, Y, SX, SY;
    vst[cent] = true, get_sz(cent, -1);

    val.clear(), cnt.clear(), lst.clear();
    val.push_back({0, 0}), AS = 0;

    lst.push_back(cent);
    T[cent] = C[cent] = CV[cent] = 0;
    P[0][0] = P[0][1] = SM[0][0] = SM[0][1] = 0;

    st.clear(), st.push_back({0, 0}), PV = 0;

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;

        S[i[0]] = 0;
        P[i[0]][0] = P[i[0]][1] = 0;
        SM[i[0]][0] = SM[i[0]][1] = 0;

        if (i[1] < 0)
            cnt.push_back({i[1], sz[i[0]], i[0]});

        dfs(i[0], cent, i[1], min(0ll, i[1]), max(0ll, i[1]), i[0]);
    }

    sort(val.begin(), val.end()), sort(cnt.begin(), cnt.end());
    sort(lst.begin(), lst.end(), [&](int x, int y) { return C[x] > C[y]; });
    X = Y = SX = SY = 0;

    for (int i : lst) {
        ans[i][0] += AS - S[T[i]] + ((int)val.size() - sz[T[i]]) * C[i];
        ans[i][1] += ((int)val.size() - sz[T[i]]) * CV[i];

        while (X < (int)val.size() && val[X][0] < -C[i])
            P[val[X][1]][0]++, SM[val[X][1]][0] += val[X][0], SX += val[X++][0];
        while (Y < (int)cnt.size() && cnt[Y][0] < -C[i])
            P[cnt[Y][2]][1]++, SM[cnt[Y][2]][1] += cnt[Y][1], SY += cnt[Y++][1];

        ans[i][0] -= SX + X * C[i], ans[i][1] += SY;
        ans[i][0] += P[T[i]][0] * C[i] + SM[T[i]][0], ans[i][1] -= SM[T[i]][1];
    }

    for (pr i : adj[cent]) {
        if (vst[i[0]])
            continue;
        dnc(i[0]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, W;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V >> W;
        adj[U].push_back({V, W});
        adj[V].push_back({U, W});
    }

    dnc(1);

    cout << 1 << '\n';
    for (int i = 1; i <= N; i++)
        cout << ans[i][0] << ' ';
    cout << '\n';
    for (int i = 1; i <= N; i++)
        cout << ans[i][1] << ' ';
    cout << '\n';

    return 0;
}