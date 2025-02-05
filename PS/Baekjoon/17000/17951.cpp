#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, st, en, mid, res = 0, X, Y;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    st = 1, en = INF;
    while (st <= en) {
        mid = st + en >> 1, X = 0, Y = 0;

        for (int i = 1; i <= N; i++) {
            Y += A[i];
            if (Y >= mid)
                X++, Y = 0;
        }

        if (X >= K)
            res = mid, st = mid + 1;
        else
            en = mid - 1;
    }

    cout << res << '\n';

    return 0;
}