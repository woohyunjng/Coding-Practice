#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

void solve() {
    int N, M, K, st, en, md, ans = 0;
    bool flag;

    cin >> N >> M >> K;

    if (N - M * K <= K)
        ans = K;
    else {
        st = K, en = N - M * K;
        while (st <= en) {
            md = st + en >> 1, flag = true;
            for (int i = 0; i < md; i++)
                flag &= (N - i + md - 1) / md > M;

            if (flag)
                st = md + 1, ans = md;
            else
                en = md - 1;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << (i - 1) % ans << ' ';
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