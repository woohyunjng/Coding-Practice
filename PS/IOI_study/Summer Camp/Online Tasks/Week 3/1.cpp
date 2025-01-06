#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, C, res = 0;
    cin >> A >> B >> C;

    if (A + C < B * 2)
        res = B * 2 - (A + C);
    else if (A + C > B * 2)
        res = (A + C) % 2 + (A + C - B * 2 + 1) / 2;

    cout << res;

    return 0;
}