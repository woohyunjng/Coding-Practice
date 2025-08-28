#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MOD = 1'000'000'007;

int in[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, ans = 0;

    cin >> N >> M;
    while (M--) {
        cin >> U >> V;
        in[U]++, in[V]++;
    }

    for (int i = 1; i <= N; i++) {
        ans += in[i] * (in[i] - 1) % MOD * (in[i] - 2) % MOD * 166666668 % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}