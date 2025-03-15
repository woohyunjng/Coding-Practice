#include <bits/stdc++.h>
using namespace std;

int comb(int N, int K) {
    if (N < K || K < 0)
        return 0;
    int ans = 1;
    for (int i = 1; i <= K; i++)
        ans = ans * (N - K + i) / i;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans;

    cin >> N >> K;
    ans = comb(N - K - 1, N - K * 2) + comb(N - K, N - K * 2);

    cout << ans << '\n';

    return 0;
}