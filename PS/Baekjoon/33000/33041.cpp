#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;

int W[MAX], res[MAX], cur[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, C, D, X;
    bool flag = true;

    cin >> H;
    for (int i = 1; i <= H; i++)
        cin >> W[i], cur[i] = W[i];
    cin >> C >> D;

    for (int i = 2; i <= H; i++) {
        if (cur[i] <= cur[i - 1])
            res[i] += (cur[i - 1] - cur[i] + 8) / 8, D -= (cur[i - 1] - cur[i] + 8) / 8, cur[i] += (cur[i - 1] - cur[i] + 8) / 8 * 8;
    }

    flag = D >= 0;
    for (int i = 1; i <= H; i++)
        flag = flag && res[i] <= W[i];

    X = min(W[H] - res[H], D);
    res[H] += X, D -= X, cur[H] += X * 8;

    for (int i = H - 1; i >= 1; i--) {
        X = min({(cur[i + 1] - cur[i] - 1) / 8, W[i] - res[i], D});
        res[i] += X, D -= X, cur[i] += X * 8;
    }

    for (int i = 1; i <= H; i++)
        flag = flag && res[i] <= W[i];
    flag = flag && D == 0;

    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= res[i]; j++)
            cout << 9 << ' ';
        for (int j = res[i] + 1; j <= W[i]; j++)
            cout << 1 << ' ';
        cout << '\n';
    }

    return 0;
}