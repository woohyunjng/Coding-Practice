#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    if (N == M) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = N - M; i < N - M + K - 1; i++)
        cout << i << ' ';
    cout << N << ' ';
    for (int i = N - M + K - 1; i < N; i++)
        cout << i << ' ';
    for (int i = N - M - 1; i >= 1; i--)
        cout << i << ' ';
    cout << '\n';

    return 0;
}
