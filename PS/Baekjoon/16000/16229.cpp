#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int F[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, L = 0, R = 0, ans = 0;
    bool flag;
    string S;

    cin >> N >> K >> S;

    F[0] = N;
    for (int i = 1; i < N; i++) {
        if (i <= R)
            F[i] = min(R - i, F[i - L]);
        while (i + F[i] < N && S[F[i]] == S[i + F[i]])
            F[i]++;
        if (i > R)
            L = i;
        R = max(R, i + F[i] - 1);
    }

    for (int i = 1; i < N; i++) {
        flag = true, L = 0;
        for (int j = i; j + i < N; j += i)
            flag &= F[j] >= i, L = max(L, j);
        flag &= L + i * 2 <= N + K && F[L + i] == N - L - i;
        if (flag)
            ans = max(ans, i);
    }

    if (K >= N)
        ans = N;

    cout << ans << '\n';

    return 0;
}