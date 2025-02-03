#include <bits/stdc++.h>
#define int long long

#define MAX 600000
#define MOD 1000000007

using namespace std;

int A[MAX], dp[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S[2] = {0, 0}, X = 0, K, P = 0;
    vector<int> arr, tmp;
    string s;

    cin >> N >> s;

    for (int i = 1; i <= N; i++) {
        if (s[i - 1] == 'R')
            A[i] = 1;
        else if (s[i - 1] == 'B')
            A[i] = 2;
        chk[i] = true;
    }

    dp[0] = S[0] = 1, chk[0] = true;

    for (int i = 1; i <= N; i++) {
        if (A[i] == 1)
            X = i;
        K = max(0ll, 2 * X - i - 1);

        if (A[i - 1] == 2)
            arr.push_back(i - 1);

        tmp.clear();
        for (int j : arr) {
            if (j >= 1 && chk[j - 1]) {
                chk[j - 1] = false, tmp.push_back(j - 1);
                if (j - 1 >= P)
                    S[j & 1 ^ 1] = (S[j & 1 ^ 1] - dp[j - 1] + MOD) % MOD;
            }
        }
        arr = tmp;

        while (P < K)
            S[P & 1] = (S[P & 1] - dp[P] * chk[P] + MOD) % MOD, P++;
        while (P > K)
            P--, S[P & 1] = (S[P & 1] + dp[P] * chk[P]) % MOD;

        dp[i] = S[i & 1];
        if (A[i] == 0)
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
        S[i & 1] = (S[i & 1] + dp[i]) % MOD;
    }

    cout << dp[N] << '\n';

    return 0;
}