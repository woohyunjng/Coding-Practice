#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MOD = 1000000007;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

int A[MAX];

void solve() {
    int N, C, ans = 1, cans = 1, K = 0;
    vector<int> arr;
    string _S;

    cin >> N >> C >> _S;
    for (int i = 1; i <= N; i++) {
        if (_S[i - 1] == '?')
            A[i] = 2;
        else
            A[i] = _S[i - 1] == '1';
    }

    A[1] = A[1] == 2 ? 1 : A[1], A[N] = A[N] == 2 ? 1 : A[N];
    ans &= A[1] == 1 && A[N] == 1, cans = ans;
    A[2] = A[2] == 2 ? 0 : A[2], A[3] = 1;

    for (int i = 2; i <= N; i++) {
        if (A[i] == 2 && (i & 1))
            A[i] = 1;
        if (A[i] != 2) {
            ans *= A[i] ? 2 : i - 1, ans %= MOD;
            cans *= A[i] ? 2 : i - 1, cans %= C;
        } else
            arr.push_back(i);
    }

    if (cans == 0) {
        cout << -1 << '\n';
        return;
    }

    C /= gcd(cans, C), reverse(arr.begin(), arr.end());
    while (C % 2 == 0)
        C /= 2, K++;

    if (C == 1) {
        if ((K - 1) >= arr.size()) {
            for (int i = 0; i < arr.size(); i++)
                ans = ans * 2 % MOD;
        } else {
            for (int i = 0; i + 1 < K; i++)
                ans = ans * 2 % MOD;
            for (int i = max(0ll, K - 1); i < arr.size(); i++)
                ans = ans * (arr[i] - 1) % MOD;
        }
    } else {
        for (int i = 0; i < arr.size(); i++)
            ans = ans * 2 % MOD;
    }

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