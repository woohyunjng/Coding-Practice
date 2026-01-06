#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1'000'000'000'000'000'000;

int query(int M, int R) {
    int res;
    cout << "? " << M << ' ' << R << '\n', cout.flush();
    cin >> res;
    return res;
}

void answer(int N) { cout << "! " << N << '\n', cout.flush(); }

signed main() {
    int X = 1, Y;

    if (query(2, 0) == 0 && query(2, 1) == 1) {
        answer(1);
        return 0;
    }

    while (true) {
        if (X != 1 && query(X, 0) == 1) {
            answer(X);
            break;
        }

        Y = 0;
        for (int i = 0; i < 45 && (X * (1ll << (i + 1)) <= INF); i++) {
            if (query(X * (1ll << (i + 1)), X * (Y ^ (1ll << i))) > (i == 0))
                Y ^= (1ll << i);
            if (Y > 1 && query(INF, X * Y) > 0)
                break;
        }
        X = X * Y;
    }

    return 0;
}