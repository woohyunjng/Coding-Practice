#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M[11], N, B, L, S, ans = 0;
    string _L;

    for (int i = 0; i < 11; i++)
        cin >> M[i];
    cin >> N;

    while (N--) {
        cin >> B >> _L >> S, L = 0;
        for (int i = 0; i < _L.size(); i++) {
            if (_L[i] == '.')
                continue;
            L = L * 10 + (_L[i] - '0');
        }

        if (L >= 200 && S >= 17)
            ans += M[B];
    }

    cout << ans << '\n';

    return 0;
}