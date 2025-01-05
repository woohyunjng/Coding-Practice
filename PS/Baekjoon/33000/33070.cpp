#include <bits/stdc++.h>
#define int long long

#define MAX 300100
using namespace std;

int chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, res = 0, A = 0, B = 0;
    cin >> N >> K;

    for (int i = 1; i <= K; i++)
        cin >> X, chk[X] = 1;
    for (int i = 1; i <= N; i++)
        chk[i] += chk[i - 1];

    for (int i = 1; i <= N; i++) {
        cin >> X;
        if (X == 0) {
            A++, B++;
            continue;
        }

        if (chk[B] - chk[A - 1] > 0)
            B++;
        else
            res++;
    }

    cout << res << '\n';

    return 0;
}