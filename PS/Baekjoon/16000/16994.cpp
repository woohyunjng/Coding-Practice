#include <bits/extc++.h>
#include <bits/stdc++.h>

using namespace __gnu_cxx;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y;
    string S;
    rope<char> rp;

    cin >> S, rp.append(S.c_str()), N = (int)S.size();

    cin >> Q;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> X >> Y;
            rp = rp.substr(X, Y - X + 1) + rp.substr(0, X) + rp.substr(Y + 1, N - Y - 1);
        } else if (T == 2) {
            cin >> X >> Y;
            rp = rp.substr(0, X) + rp.substr(Y + 1, N - Y - 1) + rp.substr(X, Y - X + 1);
        } else {
            cin >> X;
            cout << rp[X] << '\n';
        }
    }

    return 0;
}