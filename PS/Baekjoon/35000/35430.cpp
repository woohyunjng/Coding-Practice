#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;

    cin >> N >> M >> X;

    for (int i = 1; i <= N; i++) {
        if (X % i == 0 && (X / i <= M)) {
            cout << 1 << '\n';
            cout << 0 << ' ' << 0 << ' ' << i << ' ' << (X / i) << '\n';
            return 0;
        }
    }

    assert(X > N);

    cout << 2 << '\n';
    cout << 0 << ' ' << 0 << ' ' << N << ' ' << (X / N) << '\n';
    cout << 0 << ' ' << X / N << ' ' << (X % N) << ' ' << (X / N) + 1 << '\n';

    return 0;
}