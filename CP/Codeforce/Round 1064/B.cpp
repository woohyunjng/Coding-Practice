#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;
const int MOD = 998244353;

int A[MAX], S[MAX], dp[MAX];

void solve() {
    int N, ans = 1;
    vector<int> arr;

    cin >> N, fill(S, S + N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[A[i]]++;

    for (int i = 1; i <= N; i++) {
        ans = ans * (S[i] + 1) % MOD;
        if (S[i] > 0)
            arr.push_back(S[i]);
    }

    sort(arr.begin(), arr.end()), N = arr.size();
    for (int i = 1; i <= N; i++)
        A[i] = arr[i - 1];

    fill(dp, dp + A[N], 0), dp[0] = 1;
    for (int i = 1; i < N; i++)
        for (int j = A[N] - 1; j >= A[i]; j--)
            dp[j] += dp[j - A[i]] * A[i] % MOD, dp[j] %= MOD;

    for (int i = 0; i < A[N]; i++)
        ans = (ans - dp[i] + MOD) % MOD;

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