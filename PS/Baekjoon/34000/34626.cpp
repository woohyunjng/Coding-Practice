#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int N, A, ans;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A, comp.push_back(A);

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    ans = (int)comp.size() * 2 - 1;
    cout << ans << '\n';
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