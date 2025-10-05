#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 150001;

int S, tree[MAX], X[MAX], Y[MAX];
vector<int> arr[MAX];

int query(int n) {
    int res = 0;
    for (; n > 0; n -= (n & -n))
        res += tree[n];
    return res;
}

void update(int n) {
    for (; n <= S; n += (n & -n))
        tree[n]++;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, ans, SX;
    vector<int> comp[2];

    cin >> T;
    while (T--) {
        cin >> N, ans = 0;
        for (int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i], Y[i] = -Y[i];
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
                ans += query(Y[j]), update(Y[j]);
        }

        cout << ans << '\n';

        comp[0].clear(), comp[1].clear();
        for (int i = 1; i <= SX; i++)
            arr[i].clear();
        for (int i = 1; i <= S; i++)
            tree[i] = 0;
    }

    return 0;
}