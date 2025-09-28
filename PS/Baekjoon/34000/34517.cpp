#include <bits/stdc++.h>
#define int long long
#define ll __int128_t

using namespace std;

ll TH[34];

bool chk(ll X, ll Y, ll L, ll K) {
    if (L == 0)
        return true;

    for (ll i = 2; i >= 0; i--)
        for (ll j = 2; j >= 0; j--) {
            if (X < TH[K - 1] * i || Y < TH[K - 1] * j)
                continue;
            if (i == 1 && j == 1 && (X % TH[K - 1] == 0 || Y % TH[K - 1] == 0))
                continue;
            if (i == 1 && j == 1)
                return false;
            return chk(X - TH[K - 1] * i, Y - TH[K - 1] * j, L - 1, K - 1);
        }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, A, B, P, Q, L, K;
    string _P, _Q;

    TH[0] = 1000;
    for (int i = 1; i <= 33; i++)
        TH[i] = TH[i - 1] * 3;

    cin >> T;
    while (T--) {
        cin >> A >> B >> L >> K >> _P >> _Q, P = Q = 0;
        for (int i = 0; i < (int)_P.size() - 4; i++) {
            if (_P[i] == '-')
                continue;
            P = P * 10 + (_P[i] - '0');
        }
        for (int i = 0; i < (int)_Q.size() - 4; i++) {
            if (_Q[i] == '-')
                continue;
            Q = Q * 10 + (_Q[i] - '0');
        }
        for (int i = (int)_P.size() - 3; i < (int)_P.size(); i++)
            P = P * 10 + (_P[i] - '0');
        for (int i = (int)_Q.size() - 3; i < (int)_Q.size(); i++)
            Q = Q * 10 + (_Q[i] - '0');

        if (_P[0] == '-')
            P = -P;
        if (_Q[0] == '-')
            Q = -Q;
        A *= 1000, B *= 1000;

        if ((ll)P < (ll)A || (ll)Q < (ll)B || (ll)P > (ll)(A + TH[K]) || (ll)Q > (ll)(B + TH[K]))
            cout << 0 << '\n';
        else
            cout << chk((ll)P - (ll)A, (ll)Q - (ll)B, (ll)L, (ll)K) << '\n';
    }

    return 0;
}