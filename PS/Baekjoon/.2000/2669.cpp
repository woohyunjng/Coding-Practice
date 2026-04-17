#include <bits/stdc++.h>
#define int long long

#define MAX 2000
using namespace std;

int X1[4], Y1[4], X2[4], Y2[4];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    bool flag;
    int ans = 0;

    for (int i = 0; i < 4; i++)
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];

    for (int i = 1; i < 1000; i++)
        for (int j = 1; j < 1000; j++) {
            flag = false;
            for (int k = 0; k < 4; k++)
                flag |= (X1[k] <= i && i < X2[k]) && (Y1[k] <= j && j < Y2[k]);
            ans += flag ? 1 : 0;
        }

    cout << ans << '\n';

    return 0;
}