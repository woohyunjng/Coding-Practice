#include <bits/stdc++.h>
using namespace std;

bitset<1000000> V, T, B;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X;

    cin >> N >> M;

    for (int i = N - 1; i >= 0; i--)
        cin >> X, V[i] = X, B[i] = 1;

    for (int i = 29; i >= 0; i--) {
        if (!(M & (1 << i)))
            continue;
        X = (1 << i) % N, T = (V << X | V >> (N - X)) & B, V ^= T;
    }

    for (int i = N - 1; i >= 0; i--)
        cout << V[i] << '\n';

    return 0;
}