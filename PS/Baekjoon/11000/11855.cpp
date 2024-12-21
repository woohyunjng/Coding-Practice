#include <bits/stdc++.h>
#define int long long

#define MAX 21
using namespace std;

int A[MAX], B[MAX], dp[1 << MAX], val[1 << MAX], sm[MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> A[i], sm[i] = sm[i - 1] + A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    for (int i = 0; i < (1 << M); i++)
        for (int j = 0; j < M; j++)
            if (i & (1 << j))
                val[i] += B[j];

    for (int i = 0; i < (1 << M); i++) {
        for (int j = 1; j <= N; j++) {
            if (dp[i] == j - 1 && sm[dp[i]] + A[j] == val[i])
                dp[i] = j;
        }
        for (int j = 0; j < M; j++)
            if (!(i & (1 << j)))
                dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i]);
    }

    cout << (*max_element(dp, dp + (1 << M)) == N ? "YES" : "NO") << '\n';

    return 0;
}