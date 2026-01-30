#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200002;
const int MOD = 998244353;

int A[MAX];
bitset<MAX> P, Q, tmp;

void solve() {
    int N, X, Y, K, ans = 0;
    string _S;

    vector<int> comp;

    cin >> N >> X >> Y;
    cin >> _S;
    for (int i = 1; i <= N; i++) {
        if (_S[i - 1] == '?')
            A[i] = 2;
        else
            A[i] = _S[i - 1] - '0';
    }

    P.reset(), Q.reset(); // [0, 2N], [2N, 0]

    P.set(N), Q.set(N);
    for (int i = N; i >= 1; i--) {
        P <<= 1, Q >>= 1;
        if (A[i] == 1)
            swap(P, Q);
        else if (A[i] == 2)
            P |= Q, Q = P;
    }

    for (int i = 0; i <= (N << 1); i++) {
        if (!P[i])
            continue;
        K = i - N;
        comp.push_back(K * K * X + K * (X - Y) + N * Y);
    }
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i : comp)
        ans += ((i / 2) % MOD + MOD) % MOD, ans %= MOD;
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}