#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string X, Y;
    int XH, XM, YH, YM, XV, YV, ans;

    cin >> X >> Y;
    XH = stoi(X.substr(0, 2)), XM = stoi(X.substr(3, 2)), XV = XH * 60 + XM;
    YH = stoi(Y.substr(0, 2)), YM = stoi(Y.substr(3, 2)), YV = YH * 60 + YM;
    ans = min((YV - XV + 720) % 720 * 6, (XV - YV + 720) % 720 * 6);
    cout << ans << '\n';

    return 0;
}