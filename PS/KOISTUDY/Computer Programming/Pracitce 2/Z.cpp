#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;
const int MOD = 998244353;

int fac[MAX];
vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 1;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    fac[0] = 1;
    for (int i = 1; i <= N; i++)
        fac[i] = fac[i - 1] * i % MOD;

    for (int i = 1; i <= N; i++) {
        X = adj[i].size();
        if (i != 1)
            X--;
        ans = ans * fac[X] % MOD;
    }

    cout << ans << '\n';

    return 0;
}