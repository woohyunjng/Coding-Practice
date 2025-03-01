#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

map<int, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, ans = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        while (K--)
            cin >> X, cnt[X]++;
    }

    for (pr i : cnt)
        ans += i.second >= M;

    cout << ans << '\n';

    return 0;
}