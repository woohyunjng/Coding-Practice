#include <bits/stdc++.h>
#define int long long

using namespace std;

bool query(int X, int Y) {
    string res;
    cout << "? " << X << ' ' << Y << '\n', cout.flush();
    cin >> res;
    return res == "YES";
}

int get(int X, int Y) { return (int)pow(2, X) * pow(5, Y); }

signed main() {
    int T, V, X, F1, F2, st, en, md;
    cin >> T;

    while (T--) {
        st = 0, en = 6, F1 = 7;
        while (st <= en) {
            md = st + en >> 1;
            if (query(9, 9 + get(md, 7)))
                en = md - 1, F1 = md;
            else
                st = md + 1;
        }

        st = 0, en = 6, F2 = 7;
        while (st <= en) {
            md = st + en >> 1;
            if (query(9, 9 + get(9, md)))
                en = md - 1, F2 = md;
            else
                st = md + 1;
        }

        X = get(F1, F2);
        st = 0, en = 7, V = 8;
        while (st <= en) {
            md = st + en >> 1;
            if (query(md, md + X))
                en = md - 1, V = md;
            else
                st = md + 1;
        }

        cout << "! " << V + X << '\n', cout.flush();
    }

    return 0;
}