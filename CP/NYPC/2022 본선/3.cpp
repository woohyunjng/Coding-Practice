#include <bits/stdc++.h>
#define int long long

#define MAX 250100
#define MOD 1000000007

using namespace std;

int A[MAX], Q[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, L, K, res = 0, X, Y;
    cin >> N >> M >> L;

    for (int i = 1; i <= M; i++)
        cin >> Q[i][0] >> Q[i][1];

    A[1] = 1;
    for (int i = M; i >= 1; i--)
        A[Q[i][1]] = (A[Q[i][1]] + A[Q[i][0]]) % MOD;

    while (L--) {
        cin >> K;
        res = 0;

        while (K--) {
            cin >> X >> Y;
            res = (res + A[X] * Y) % MOD;
        }

        cout << res << '\n';
    }

    return 0;
}