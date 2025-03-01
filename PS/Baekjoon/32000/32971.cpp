#include <bits/stdc++.h>

using namespace std;

const int MAX = 22;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, ans = 0, K;
    string S;

    cin >> N >> M >> X >> Y;

    for (int i = 0; i < N; i++) {
        cin >> S, K = 0;
        for (int j = 0; j < M; j++)
            K = K << 1 | (S[j] == '1');
        A[i] = K;
    }

    for (int i = 0; i < (1 << M); i++) {
        K = -Y * __builtin_popcount(i);
        for (int j = 0; j < N; j++)
            K += max(__builtin_popcount(A[j] & i) - X, 0);
        ans = max(ans, K);
    }

    cout << ans << '\n';

    return 0;
}