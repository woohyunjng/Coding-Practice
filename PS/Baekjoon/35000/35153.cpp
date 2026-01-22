#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 1'000'000;

int fsqrt(int X) {
    int res = 1;
    for (int st = 1, en = MAX, md; st <= en;) {
        md = st + en >> 1;
        if (md * md <= X)
            res = md, st = md + 1;
        else
            en = md - 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, X, Y, P, Q;

    cin >> N, S = fsqrt(N * 2) * 2;

    if (N == 1) {
        cout << 2 << '\n';
        cout << 1 << ' ' << 2 << '\n';
        return 0;
    }

    for (int i = 1; i <= S; i++) {
        if (i * (i - 1) / 2 == N) {
            cout << i + 1 << '\n';
            for (int j = 1; j <= i; j++)
                cout << 1 << ' ' << j + 1 << '\n';
            return 0;
        }
    }

    for (int i = S; i >= 1; i--) {
        if (N < i * (i - 1) / 2)
            continue;
        X = N - i * (i - 1) / 2, Y = X / i;
        if (X % i != 0)
            continue;
        if (1 + 2 * i + 1 + Y > MAX)
            continue;
        cout << 1 + 2 * i + 1 + Y << '\n';
        cout << 1 << ' ' << 2 << '\n';
        for (int j = 1; j <= Y; j++)
            cout << 2 << ' ' << 2 + j << '\n';
        for (int j = 0; j < i; j++) {
            cout << 1 << ' ' << (Y + 3) + (j << 1) << '\n';
            cout << (Y + 3) + (j << 1) << ' ' << (Y + 3) + (j << 1 | 1) << '\n';
        }
        return 0;
    }

    for (int i = S; i >= 1; i--) {
        if (N < i * (i - 1) / 2)
            continue;
        X = N + i * (i + 1) / 2;
        for (int j = i + 1; j * j <= X; j++) {
            if (X % j)
                continue;
            P = j - i, Q = X / j - i;
            if (P + Q + 2 + 2 * i + 1 > MAX)
                continue;
            cout << P + Q + 2 + 2 * i + 1 << '\n';
            cout << 1 << ' ' << 2 << '\n';
            for (int j = 1; j <= P; j++)
                cout << 2 << ' ' << 2 + j << '\n';
            cout << 1 << ' ' << P + 3 << '\n';
            for (int j = 1; j <= Q; j++)
                cout << P + 3 << ' ' << P + 3 + j << '\n';
            for (int j = 0; j < i; j++) {
                cout << 1 << ' ' << (P + Q + 4 + (j << 1)) << '\n';
                cout << (P + Q + 4 + (j << 1)) << ' ' << (P + Q + 4 + (j << 1 | 1)) << '\n';
            }
            return 0;
        }
    }

    assert(false);

    return 0;
}