#include <bits/stdc++.h>
#define int long long

#define MAX 2000000

using namespace std;

int cnt[MAX], val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, P, H, res = 0;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cnt[i] = 1, val[i] = i;

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> P >> H, res -= cnt[val[P]] > 1, res -= cnt[H] > 1;
            cnt[val[P]]--, cnt[H]++, res += cnt[val[P]] > 1, res += cnt[H] > 1;
            val[P] = H;
        } else
            cout << res << '\n';
    }

    return 0;
}