#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MOD = 1000000007;

int A[MAX];

void solve() {
    int N, C, ans = 1, cans = 1;
    string _S;

    cin >> N >> C >> _S;
    for (int i = 1; i <= N; i++)
        A[i] = _S[i - 1] == '1';

    ans &= A[1] == 1 && A[N] == 1, cans = ans;
    for (int i = 1; i < N; i++) {
        ans *= A[i] ? 2 : i - 1, ans %= MOD;
        cans *= A[i] ? 2 : i - 1, cans %= C;
    }
    if (cans == 0)
        ans = -1;
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