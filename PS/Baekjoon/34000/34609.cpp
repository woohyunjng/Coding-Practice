#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int type_query(int x) {
    string val;
    cout << "type " << x << '\n', cout.flush();
    cin >> val;
    return val == "rose";
}

int multi_query(int x) {
    if (x == 0)
        return 0;

    int val;
    cout << "multi " << x << '\n', cout.flush();
    cin >> val;
    return val;
}

void answer(int x) {
    cout << "answer " << x << '\n', cout.flush();
    return;
}

signed main() {
    int T, N, st, en, md, V, X, Y, Z, L, R;
    cin >> T;

    while (T--) {
        cin >> N;

        st = 0, en = N;
        while (st <= en) {
            md = st + en >> 1;
            if (md == 0 || type_query(md))
                st = md + 1, V = md;
            else
                en = md - 1;
        }

        if (V == 0)
            X = multi_query(1), answer(X);
        else if (V == N)
            X = multi_query(N - 1), answer(N - X);
        else {
            X = multi_query(V - 1), Y = multi_query(V), Z = multi_query(V + 1);
            L = X - Y, R = Z - Y;
            answer(V - L + R);
        }
    }

    return 0;
}