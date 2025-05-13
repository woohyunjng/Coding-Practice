#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
typedef array<int, 2> pr;

vector<pr> adj[MAX];
int S, T[MAX], C[MAX], R[MAX], D[MAX], A[MAX], B[MAX], ans[MAX], depth[MAX], in[MAX], out[MAX], cnt, tree[MAX * 8]; // B[i] -> 어디까지, A[i] -> 자기 인덱스
bool chk[MAX];

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void dfs(int node, int par) {
    in[node] = ++cnt;
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        depth[i[0]] = depth[node] + i[1], dfs(i[0], node);
    }
    out[node] = ++cnt;
}

void dnc(int l, int r, vector<int> &arr) {
    if (l == r) {
        for (int j : arr)
            ans[j] = l;
        return;
    }

    int m = l + r >> 1;

    vector<int> lft, rgt;

    sort(arr.begin(), arr.end(), [&](int x, int y) {
        int xv = x > 0 ? in[x] : out[-x], yv = y > 0 ? in[y] : out[-y];
        return xv < yv;
    });

    for (int i : arr) {
        if (i > 0) {
            if (T[i] <= m || query(1, 1, S, A[i], S) >= C[i])
                lft.push_back(i), update(1, 1, S, B[i], D[i]), chk[i] = true;
            else
                rgt.push_back(i), C[i] -= query(1, 1, S, A[i], S);
        } else {
            if (chk[-i])
                chk[-i] = false, update(1, 1, S, B[-i], -D[-i]), lft.push_back(i);
            else
                rgt.push_back(i);
        }
    }

    dnc(l, m, lft), dnc(m + 1, r, rgt);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z;
    vector<int> arr, comp;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), adj[Y].push_back({X, Z});
    }

    for (int i = 1; i <= N; i++)
        cin >> X, T[X] = i;
    for (int i = 1; i <= N; i++)
        cin >> C[i] >> R[i] >> D[i], arr.push_back(i), arr.push_back(-i);

    dfs(1, 0);
    for (int i = 1; i <= N; i++)
        comp.push_back(depth[i]), comp.push_back(depth[i] + R[i]);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++)
        A[i] = lower_bound(comp.begin(), comp.end(), depth[i]) - comp.begin() + 1, B[i] = lower_bound(comp.begin(), comp.end(), depth[i] + R[i]) - comp.begin() + 1;

    dnc(1, N, arr);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}