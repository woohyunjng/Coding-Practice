#include <bits/stdc++.h>
#define int long long

#define MAX 200000
using namespace std;

int A[MAX], ans[MAX], query[MAX][2], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, Q, res = 0, X, Y, Z;
    cin >> N >> K >> Q;

    for (int i = Q; i >= 1; i--)
        cin >> query[i][0] >> query[i][1], query[i][1] = (N * 100000 - query[i][1]) % N;

    for (int i = 1; i <= Q; i++) {
        if (query[i][0] == 2) {
            sm[0] += query[i][1] / K, Z = query[i][1] % K;
            if (Z == 0)
                continue;
            X = (K * 2 - res - Z) % K, Y = (K * 2 - res - 1) % K;
            if (X <= Y)
                sm[X]++, sm[Y + 1]--;
            else
                sm[X]++, sm[0]++, sm[Y + 1]--;
        }
        res = (res + query[i][1]) % K;
    }

    for (int i = 1; i < K; i++)
        sm[i] += sm[i - 1];

    for (int i = 0; i < N; i++) {
        cin >> X;
        ans[((i % K + res) % K + (i / K + sm[i % K]) * K) % N] = X;
    }

    for (int i = 0; i < N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}