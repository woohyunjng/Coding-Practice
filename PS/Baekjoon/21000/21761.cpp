#include <bits/stdc++.h>
#define int long long
#define ll __int128_t

using namespace std;

ll V[4], P, Q;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y, Z, W, T;
    char C;

    priority_queue<int> pq[4];

    cin >> N >> K >> X >> Y >> Z >> W;

    V[0] = X, V[1] = Y, V[2] = Z, V[3] = W;

    while (N--) {
        cin >> C >> X;
        pq[C - 'A'].push(X);
    }

    while (K--) {
        Q = 0, T = 0;
        for (int i = 0; i < 4; i++) {
            if (pq[i].empty())
                continue;
            P = 1;
            for (int j = 0; j < 4; j++)
                if (i != j)
                    P *= V[j];
            if (P * (ll)pq[i].top() > Q)
                Q = P * (ll)pq[i].top(), T = i;
        }
        cout << (char)('A' + T) << ' ' << pq[T].top() << '\n';
        V[T] += pq[T].top(), pq[T].pop();
    }

    return 0;
}