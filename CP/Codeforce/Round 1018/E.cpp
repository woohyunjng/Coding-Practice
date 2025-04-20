#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX];

void solve() {
    int N, X = 0, Y = 0, Z = 0;
    string C;

    cin >> N >> C;
    for (int i = 1; i <= N; i++)
        A[i] = C[i - 1] == 'B';

    for (int i = N; i >= 1; i--) {
        if (A[i]) {
            X++;
            if (i % 2 == 0)
                Y++;
        } else
            Z += X;
    }

    cout << (Z + abs(X / 2 - Y)) / 2 << '\n';
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