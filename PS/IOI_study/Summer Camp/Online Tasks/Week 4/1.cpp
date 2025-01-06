#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

int sm[MAX][3];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, C, res = 0;
    cin >> N >> Q;

    while (Q--) {
        cin >> L >> R >> C, C--;
        sm[L][C]++, sm[R + 1][C]--;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++)
            sm[i][j] += sm[i - 1][j];
        if (sm[i][0] > 0 && sm[i][1] > 0 && sm[i][2] == 0)
            res++;
    }

    cout << res;

    return 0;
}