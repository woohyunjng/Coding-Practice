#include <bits/stdc++.h>
using namespace std;

bool chk[1440];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, M;

    cin >> H >> M;

    fill(chk + (6 * 60 + 30), chk + 9 * 60 + 1, true);
    for (int i = 9; i <= 11; i++)
        fill(chk + (i * 60 + 50), chk + (i + 1) * 60 + 1, true);
    fill(chk + (12 * 60 + 50), chk + (13 * 60 + 50) + 1, true);
    for (int i = 14; i <= 15; i++)
        fill(chk + (i * 60 + 40), chk + (i * 60 + 50) + 1, true);
    fill(chk + 16 * 60 + 40, chk + (22 * 60 + 50) + 1, true);

    cout << (chk[H * 60 + M] ? "Yes" : "No") << '\n';

    return 0;
}