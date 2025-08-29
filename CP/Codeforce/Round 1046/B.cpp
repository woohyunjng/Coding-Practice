#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 101;
const int INF = 1'000'000'000;

int move(int dir, int k) {
    char X;
    int res;

    if (dir == 0)
        X = 'U';
    else if (dir == 1)
        X = 'D';
    else if (dir == 2)
        X = 'L';
    else
        X = 'R';

    cout << "? " << X << ' ' << k << '\n', cout.flush();
    cin >> res;
    return res;
}

void answer(int X, int Y) { cout << "! " << X << ' ' << Y << '\n', cout.flush(); }

int X[MAX], Y[MAX], U[MAX], V[MAX];

void solve() {
    int N, U_mx = -INF * 2, V_mx = -INF * 2, K, ans_U, ans_V;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        U[i] = X[i] + Y[i], V[i] = X[i] - Y[i];

        U_mx = max(U_mx, U[i]), V_mx = max(V_mx, V[i]);
    }

    move(1, INF), move(1, INF), move(3, INF), K = move(3, INF);
    ans_V = K + V_mx - INF * 4;

    for (int i = 0; i < 4; i++)
        K = move(0, INF);
    ans_U = K + U_mx - INF * 4;

    answer((ans_U + ans_V) / 2, (ans_U - ans_V) / 2);
    return;
}

signed main() {
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}