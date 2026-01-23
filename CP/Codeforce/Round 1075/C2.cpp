#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

void solve() {
    int N, X = 1;

    cin >> N;
    if (N & 1) {
        cout << N - 1 << ' ';
        for (int i = 2; i < N - 1; i++)
            cout << (i ^ 1) << ' ';
        cout << 1 << ' ' << N << '\n';
    } else {
        while ((X << 1) <= N)
            X <<= 1;
        if (X == N)
            cout << -1 << '\n';
        else {
            X = N - X;
            cout << (X ^ 1) << ' ';
            for (int i = 2; i < N - 1; i++)
                cout << (i == X ? N : (i ^ 1)) << ' ';
            cout << N - 2 << ' ' << 1 << '\n';
        }
    }
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