#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;
const int MOD = 1000000007;

int A[MAX], B[MAX];

void solve() {
    int N, ans, cur = 0, X, Y, val = 1;
    multiset<pr> st;
    multiset<pr>::iterator it;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i], X = 0, Y = 0;
        while (true) {
            it = st.lower_bound({A[i] ^ cur, 0});
            if (it == st.end() || (*it)[0] != (A[i] ^ cur))
                break;
            X += (*it)[1], st.erase(it);
        }

        Y = (X * 2 + val * 3) % MOD, val = X, cur ^= A[i];
        if (Y)
            st.insert({A[i] ^ cur, Y});
    }

    ans = val;
    for (pr i : st)
        ans = (ans + i[1]) % MOD;
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