#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, K, X;
    vector<int> ans;

    cin >> N >> K, X = K - 1;

    while (X)
        ans.push_back(X - (X >> 1)), X >>= 1;
    ans.push_back(K + 1);
    if (N / K >= 3)
        ans.push_back(K * 3);

    for (int i = 1; (K << i) <= N; i++)
        ans.push_back(K << i);

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}