#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1 << 19;

int B[MAX], tree[MAX][2], V[MAX][2];

void merge(int n) {
    if (B[n] == 1) {
        V[n][0] = V[n << 1][0] - V[n << 1 | 1][1];
        V[n][1] = V[n << 1][1] - V[n << 1 | 1][0];
    } else if (B[n] == 0) {
        V[n][0] = V[n << 1][0] + V[n << 1 | 1][0];
        V[n][1] = V[n << 1][1] + V[n << 1 | 1][1];
    } else {
        V[n][0] = V[n << 1][0] + max(abs(V[n << 1 | 1][0]), abs(V[n << 1 | 1][1]));
        V[n][1] = V[n << 1][1] - max(abs(V[n << 1 | 1][0]), abs(V[n << 1 | 1][1]));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, N, Q, X, Y;
    char C;

    cin >> K, N = 1 << K;

    for (int i = 1; i <= N; i++)
        cin >> X, V[i + N - 1][0] = V[i + N - 1][1] = X;
    for (int i = 1; i <= N - 1; i++)
        cin >> B[i];

    for (int i = N - 1; i > 0; i--)
        merge(i);
    cout << V[1][0] << '\n';

    cin >> Q;
    while (Q--) {
        cin >> C >> X >> Y;
        if (C == 'A') {
            V[X + N - 1][0] = V[X + N - 1][1] = Y, X += N - 1, X >>= 1;
            while (X > 0)
                merge(X), X >>= 1;
        } else if (C == 'B') {
            B[X] = Y;
            while (X > 0)
                merge(X), X >>= 1;
        }
        cout << V[1][0] << '\n';
    }

    return 0;
}