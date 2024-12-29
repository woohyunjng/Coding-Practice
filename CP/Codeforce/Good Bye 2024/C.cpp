#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

pr calc(int L, int R, int K) {
    if ((R - L + 1) < K)
        return {0, 0};

    pr res = {0, 0};
    if ((R - L + 1) % 2 == 0) {
        res = calc(L, (L + R) / 2, K);
        res.first *= 2;
        res.first += (L + R) / 2 * res.second;
        res.second *= 2;
    } else {
        res = calc(L, (L + R) / 2 - 1, K);
        res.first *= 2;
        res.first += (L + R) / 2 * (res.second + 1);
        res.second = res.second * 2 + 1;
    }

    return res;
}

void solve() {
    int N, K;
    cin >> N >> K;

    cout << calc(1, N, K).first << '\n';
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