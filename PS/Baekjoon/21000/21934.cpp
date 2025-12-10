#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 10001;
const int MOD = 1'000'000'007;

int CT[MAX], A[MAX], M[MAX], dp[2][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, S = 0, L = 0, ans;
    char C;

    cin >> N, X = 0;
    for (int i = 1; i <= (N << 1); i++) {
        cin >> C >> A[i], CT[A[i]]++;
        M[i] = C == 'I' ? 1 : -1;
    }

    vector<int> arr;
    for (int i = 1; i <= (N << 1); i++) {
        if (A[i] != 0 && CT[A[i]] > 1)
            continue;
        A[++X] = A[i], M[X] = M[i];
        L += A[X] == 0 ? 1 : -1;
    }
    N = X, X = 0;

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        fill(dp[i & 1], dp[i & 1] + (N / 2) + 2, 0);
        for (int j = 0; j <= X + M[i]; j++) {
            if (M[i] == 1 && A[i] == 0 && j > 0)
                dp[i & 1][j] = dp[i & 1 ^ 1][j - 1];
            else if (M[i] == 1 && A[i] != 0)
                dp[i & 1][j] = dp[i & 1 ^ 1][j];
            else if (M[i] == -1 && A[i] == 0)
                dp[i & 1][j] = (dp[i & 1 ^ 1][j + 1] * (j + 1) % MOD + dp[i & 1 ^ 1][j] * (X - j) % MOD) % MOD;
            else if (M[i] == -1 && A[i] != 0)
                dp[i & 1][j] = dp[i & 1 ^ 1][j + 1] * (j + 1) % MOD;
        }
        X += M[i];
    }

    ans = dp[N & 1][0];
    for (int i = 1; i <= (L >> 1); i++)
        ans = (ans * i) % MOD;

    cout << ans << '\n';

    return 0;
}