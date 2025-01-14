#include <bits/stdc++.h>
#define int long long

#define MAX 100100
using namespace std;

int D, dp[MAX], T[MAX], V[MAX];

void dnc_opt(int l, int r, int s, int e) {
    if (l > r)
        return;
    int mid = l + r >> 1, opt = -1, res = -1, val;

    for (int i = max(s, mid - D); i <= min(mid, e); i++) {
        val = (mid - i) * T[mid] + V[i];
        if (val > res)
            res = val, opt = i;
    }
    dp[mid] = res;

    dnc_opt(l, mid - 1, s, opt), dnc_opt(mid + 1, r, opt, e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    cin >> N >> D;

    for (int i = 1; i <= N; i++)
        cin >> T[i];
    for (int i = 1; i <= N; i++)
        cin >> V[i];

    dnc_opt(1, N, 1, N);

    for (int i = 1; i <= N; i++)
        res = max(res, dp[i]);
    cout << res << '\n';

    return 0;
}