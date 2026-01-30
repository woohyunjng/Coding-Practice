#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 31;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int DEF = (1ll << 31) - 1;

void solve() {
    int X, Y, K, ans_P = -1, ans_Q = -1, P, Q, lsb, B;
    bool flag;

    cin >> X >> Y, K = X & Y;

    P = Q = 0, flag = true, lsb = -1;
    for (int i = MAX - 1; i >= 0; i--) {
        if (K & (1 << i)) {
            lsb = i;
            break;
        }
    }

    if (lsb == -1)
        P = X, Q = Y;
    else {
        flag = false;
        for (int j = lsb + 1; j < MAX; j++) {
            if (!(X & (1 << j)) && !(Y & (1 << j))) {
                flag = true;
                B = (1 << j) - 1;
                P = X & (DEF ^ B), Q = Y & (DEF ^ B);
                if ((X & B) < (Y & B))
                    P ^= X & B, Q ^= 1 << j;
                else
                    P ^= 1 << j, Q ^= Y & B;
                break;
            }
        }
    }
    if (flag && (ans_P == -1 || (abs(P - X) + abs(Q - Y) <= abs(ans_P - X) + abs(ans_Q - Y))))
        ans_P = P, ans_Q = Q;

    P = Q = 0;
    if (lsb == -1) {
        for (int i = 0; i < MAX; i++) {
            if (X & (1 << i))
                P ^= (1 << i);
            else if (Y & (1 << i))
                Q ^= (1 << i);
        }
    } else {
        for (int i = lsb + 1; i < MAX; i++) {
            if (X & (1 << i))
                P ^= (1 << i);
            else if (Y & (1 << i))
                Q ^= (1 << i);
        }
        P ^= (1 << lsb) - 1, Q ^= 1 << lsb;
    }
    if (ans_P == -1 || (abs(P - X) + abs(Q - Y) <= abs(ans_P - X) + abs(ans_Q - Y)))
        ans_P = P, ans_Q = Q;

    P = Q = 0;
    for (int i = MAX - 1; i >= 0; i--) {
        if ((X & (1 << i)) && (Y & (1 << i)))
            P ^= (1 << i);
        else if ((X & (1 << i)) && !(Y & (1 << i)))
            P ^= (1 << i);
        else if (!(X & (1 << i)) && (Y & (1 << i)))
            Q ^= (1 << i);
    }
    if (ans_P == -1 || (abs(P - X) + abs(Q - Y) <= abs(ans_P - X) + abs(ans_Q - Y)))
        ans_P = P, ans_Q = Q;

    P = Q = 0;
    for (int i = MAX - 1; i >= 0; i--) {
        if ((X & (1 << i)) && (Y & (1 << i)))
            Q ^= (1 << i);
        else if ((X & (1 << i)) && !(Y & (1 << i)))
            P ^= (1 << i);
        else if (!(X & (1 << i)) && (Y & (1 << i)))
            Q ^= (1 << i);
    }
    if (ans_P == -1 || (abs(P - X) + abs(Q - Y) <= abs(ans_P - X) + abs(ans_Q - Y)))
        ans_P = P, ans_Q = Q;

    if (ans_P == -1)
        ans_P = ans_Q = 0;
    cout << ans_P << ' ' << ans_Q << '\n';
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