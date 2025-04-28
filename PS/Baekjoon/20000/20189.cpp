#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2001;

int D[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, Q, V = 0, X, Y;
    bool ans = true;

    cin >> N >> K >> Q;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++) {
            cin >> X, D[i] += X != i;
            if (X >= i)
                V += X - i;
            else
                V += X + N - i;
        }

    V /= N;
    if (D[1] == 0)
        V++;
    ans = V <= Q;

    cout << (ans ? 1 : 0) << '\n';

    return 0;
}