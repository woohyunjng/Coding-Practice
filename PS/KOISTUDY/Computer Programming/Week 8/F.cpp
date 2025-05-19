#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 500001;

int X[MAX], Y[MAX], SC[4], V[MAX][4], tree[MAX * 4];
vector<int> arr[MAX];

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = 0;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, T, ans = -0x3f3f3f3f3f3f3f3f;
    vector<int> compX, compY;

    cin >> N;
    for (int i = 0; i < 4; i++)
        cin >> SC[i];

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        compX.push_back(X[i]), compY.push_back(Y[i]);
    }

    sort(compX.begin(), compX.end()), compX.erase(unique(compX.begin(), compX.end()), compX.end());
    sort(compY.begin(), compY.end()), compY.erase(unique(compY.begin(), compY.end()), compY.end()), S = compY.size();

    for (int i = 1; i <= N; i++) {
        X[i] = lower_bound(compX.begin(), compX.end(), X[i]) - compX.begin() + 1;
        Y[i] = lower_bound(compY.begin(), compY.end(), Y[i]) - compY.begin() + 1;
        arr[X[i]].push_back(i);
    }

    init(1, 1, S);
    for (int i = 1; i <= N; i++) {
        for (int j : arr[i]) {
            V[j][1] = query(1, 1, S, Y[j] + 1, S);
            V[j][2] = query(1, 1, S, 1, Y[j] - 1);
        }

        for (int j : arr[i])
            update(1, 1, S, Y[j], 1);
    }

    init(1, 1, S);
    for (int i = N; i >= 1; i--) {
        for (int j : arr[i]) {
            V[j][0] = query(1, 1, S, Y[j] + 1, S);
            V[j][3] = query(1, 1, S, 1, Y[j] - 1);
        }

        for (int j : arr[i])
            update(1, 1, S, Y[j], 1);
    }

    for (int i = 1; i <= N; i++) {
        T = 0;
        for (int j = 0; j < 4; j++)
            T += SC[j] * V[i][j];
        ans = max(ans, T);
    }

    cout << ans << '\n';

    return 0;
}