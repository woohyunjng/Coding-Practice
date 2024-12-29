#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;

int res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, C, D, X = 0;
    bool flag = true;
    cin >> H >> W >> C >> D;

    if (H * (H - 1) / 2 > D)
        flag = false;

    for (int i = 0; i < H; i++)
        res[i] = i, D -= i;

    X = D % H;
    for (int i = H - 1; i >= H - X; i--)
        res[i]++, D--;
    D /= H;

    for (int i = 0; i < H; i++)
        res[i] += D, flag = flag && res[i] <= W;

    if (!flag) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < res[i]; j++)
            cout << 9 << ' ';
        for (int j = res[i]; j < W; j++)
            cout << 1 << ' ';
        cout << '\n';
    }

    return 0;
}