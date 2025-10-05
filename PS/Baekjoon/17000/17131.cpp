#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MOD = 1'000'000'007;

int S, tree[MAX][2], X[MAX], Y[MAX], V[MAX];
vector<int> arr[MAX];

int query(int t, int n) {
    int res = 0;
    for (; n > 0; n -= (n & -n))
        res += tree[n][t], res %= MOD;
    return res;
}

void update(int t, int n, int v) {
    for (; n <= S; n += (n & -n))
        tree[n][t] += v, tree[n][t] %= MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans, SX;
    vector<int> comp[2];

    cin >> N, ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        comp[0].push_back(X[i]), comp[1].push_back(Y[i]);
    }

    sort(comp[0].begin(), comp[0].end()), comp[0].erase(unique(comp[0].begin(), comp[0].end()), comp[0].end()), SX = comp[0].size();
    sort(comp[1].begin(), comp[1].end()), comp[1].erase(unique(comp[1].begin(), comp[1].end()), comp[1].end()), S = comp[1].size();

    for (int i = 0; i < N; i++) {
        X[i] = lower_bound(comp[0].begin(), comp[0].end(), X[i]) - comp[0].begin() + 1;
        Y[i] = lower_bound(comp[1].begin(), comp[1].end(), Y[i]) - comp[1].begin() + 1;
        arr[X[i]].push_back(i);
    }

    for (int i = 1; i <= SX; i++) {
        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return Y[x] < Y[y]; });
        for (int j : arr[i])
            V[j] = query(0, S) - query(0, Y[j]), update(0, Y[j], 1);
        reverse(arr[i].begin(), arr[i].end());
        for (int j : arr[i])
            ans += query(1, Y[j] - 1), ans %= MOD, update(1, Y[j], V[j]);
    }

    cout << ans << '\n';

    return 0;
}