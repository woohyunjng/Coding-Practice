#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int C;

    cin >> C;

    if (C == 0) {
        cout << "? / ? / ?" << '\n';
        return 0;
    }

    cout << "a = ? max ?" << '\n';
    cout << "b = (a max a) / a" << '\n';
    for (int i = 1; i < 8; i++)
        cout << (char)('b' + i) << " = " << (char)('a' + i) << " + " << (char)('a' + i) << '\n';

    vector<char> ans;

    for (int i = 0; i < 8; i++)
        if (C & (1 << i))
            ans.push_back('b' + i);

    for (int i = 0; i + 1 < ans.size(); i++)
        cout << ans[i] << " + ";
    cout << ans.back() << '\n';

    return 0;
}