#include <bits/stdc++.h>
#define int long long
#define ll __int128_t

using namespace std;

const int MAX = 100;

int _V[MAX][3];
ll A[MAX], B[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, TA, TB;
    ll X, Y, L, R, ans;

    cin >> T;
    while (T--) {
        cin >> N >> TA >> TB, ans = TA + TB;
        for (int i = 0; i < N; i++) {
            cin >> _V[i][0] >> _V[i][1] >> _V[i][2];
            A[i] = _V[i][0], B[i] = _V[i][1], C[i] = _V[i][2];
        }

        for (ll st = 0, en = TA + TB, md; st <= en;) {
            md = st + en >> 1, L = max((ll)0, md - (ll)TB + 1), R = min(md, (ll)TA - 1);
            for (int i = 0; i < N; i++) {
                X = (ll)A[i] * (ll)TA + (ll)B[i] * (ll)TB - C[i] - B[i] * md, Y = A[i] - B[i];
                if (X > 0 && Y > 0)
                    L = max(L, (X + Y - 1) / Y);
                else if (X > 0 && Y <= 0)
                    R = min(R, (ll)-1);
                else if (Y < 0)
                    R = min(R, (-X) / (-Y));
            }

            if (L <= R)
                ans = md, en = md - 1;
            else
                st = md + 1;
        }

        cout << (int)ans << '\n';
    }

    return 0;
}