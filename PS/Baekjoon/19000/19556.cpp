#include <bits/stdc++.h>
#define int long long

using namespace std;

bool query(int X) {
    int res;
    cout << "? " << X << '\n', cout.flush();
    cin >> res;
    return res == 1;
}

void answer(int X) { cout << "= " << X << '\n', cout.flush(); }

signed main() {
    int N, ans, T = 1, L, R, X;
    bool flag;

    cin >> N, ans = N;

    L = R = X = 0;
    for (int st = 1, en = N - 1, md; st <= en;) {
        md = st + en >> 1;
        X += md * (T ? 1 : -1), T ^= 1;
        L = min(L, X), R = max(R, X);
        st = md + 1;
    }

    X = 1 - L, T = 1, query(X);
    for (int st = 1, en = N - 1, md; st <= en;) {
        md = st + en >> 1;
        X += md * (T ? 1 : -1), T ^= 1;
        if (query(X))
            en = md - 1, ans = md;
        else
            st = md + 1;
    }

    answer(ans);

    return 0;
}