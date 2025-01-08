#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X = -1, Y = -1, res_len = 0;
    string S, K = "#", res, ans;
    vector<int> rad;

    cin >> S;

    for (char i : S)
        K.push_back(i), K.push_back('#');
    rad.resize(K.size());

    for (int i = 0; i < K.size(); i++) {
        if (i <= Y)
            rad[i] = min(Y - i, rad[2 * X - i]);
        while (i - rad[i] - 1 >= 0 && i + rad[i] + 1 < K.size() && K[i - rad[i] - 1] == K[i + rad[i] + 1])
            rad[i]++;
        if (Y < i + rad[i])
            Y = i + rad[i], X = i;
        if (res_len < rad[i])
            res_len = rad[i], res = K.substr(i - rad[i], 2 * rad[i] + 1);
    }

    for (int i = 0; i < res.size(); i++)
        if (res[i] != '#')
            ans.push_back(res[i]);
    cout << ans << '\n';

    return 0;
}