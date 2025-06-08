#include <bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

int div_sum(int P, int Q, int N) {
    int G = gcd(P, Q);
    P /= G, Q /= G;
    if (N == 0 || P == 0)
        return 0;
    else if (Q == 1)
        return P * N * (N + 1) / 2;
    else if (P > Q)
        return div_sum(P % Q, Q, N) + N * (N + 1) / 2 * (P / Q);
    else
        return N * (N * P / Q) + N / Q - div_sum(Q, P, N * P / Q);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int W, P, Q, N;

    cin >> W;
    while (W--) {
        cin >> P >> Q >> N;
        cout << P * N * (N + 1) / 2 - Q * div_sum(P, Q, N) << '\n';
    }

    return 0;
}