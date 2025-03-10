#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string ans;

    cin >> N;
    for (int i = 0; i < (1 << N); i++) {
        ans = "";

        for (int j = N - 1; j >= 0; j--) {
            if (i & (1 << j))
                ans.push_back('2');
            else
                ans.push_back('1');
        }

        cout << ans << '\n';
    }

    return 0;
}