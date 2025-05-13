#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int S, X[MAX], Y[MAX], A[MAX], ans[MAX], tree[MAX];
bool line;

int query(int n) {
    int res = 0;
    for (; n; n -= n & -n)
        res += tree[n];
    return res;
}

void update(int n, int v) {
    for (; n <= S; n += n & -n)
        tree[n] += v;
}

int get(int v) {
    if (line)
        return query(v) - query(v - 1);
    else
        return query(v);
}

void dnc(int l, int r, vector<int> &arr) {
    if (l == r) {
        for (int j : arr)
            ans[j] = l;
        return;
    }

    int m = l + r >> 1;
    vector<int> lft, rgt, rollback;

    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] == X[y] ? Y[x] < Y[y] : X[x] < X[y]; });

    for (int i : arr) {
        if (i <= m || get(Y[i]) >= A[i])
            lft.push_back(i), update(Y[i], 1), rollback.push_back(Y[i]);
        else
            rgt.push_back(i), A[i] -= get(Y[i]);
    }

    for (int i : rollback)
        update(i, -1);

    dnc(l, m, lft), dnc(m + 1, r, rgt);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, TX, TY, DX[2], DY[2];
    vector<int> comp[2], arr;

    cin >> N >> DX[0] >> DY[0] >> DX[1] >> DY[1];

    if (DX[0] * DY[1] - DY[0] * DX[1] < 0)
        swap(DX[0], DX[1]), swap(DY[0], DY[1]);
    else if (DX[0] * DY[1] - DY[0] * DX[1] == 0)
        line = true, DX[1] = -DY[0], DY[1] = DX[0];

    for (int i = 1; i <= N; i++) {
        cin >> TX >> TY;
        X[i] = DY[1] * TX - DX[1] * TY;
        Y[i] = DX[0] * TY - DY[0] * TX;

        comp[0].push_back(X[i]), comp[1].push_back(Y[i]);
    }

    sort(comp[0].begin(), comp[0].end()), comp[0].erase(unique(comp[0].begin(), comp[0].end()), comp[0].end());
    sort(comp[1].begin(), comp[1].end()), comp[1].erase(unique(comp[1].begin(), comp[1].end()), comp[1].end()), S = comp[1].size();

    for (int i = 1; i <= N; i++) {
        X[i] = lower_bound(comp[0].begin(), comp[0].end(), X[i]) - comp[0].begin() + 1;
        Y[i] = lower_bound(comp[1].begin(), comp[1].end(), Y[i]) - comp[1].begin() + 1;
    }

    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back(i);

    dnc(1, N, arr);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}