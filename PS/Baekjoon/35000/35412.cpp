#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, ans = "";
    int N;

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        ans += S[i];
        if (ans.size() >= 3) {
            if (ans[ans.size() - 3] == ans[ans.size() - 1])
                ans.pop_back(), ans.pop_back(), ans.pop_back();
        }
        if (ans.size() >= 2) {
            if (ans[ans.size() - 2] == ans[ans.size() - 1])
                ans.pop_back(), ans.pop_back();
        }
    }

    if (ans.empty())
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}