#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX], val[MAX];
map<int, bool> chk;

void solve() {
    int N, ans = 0, cnt = 0, X, K = 1;
    bool flag;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], cnt += A[i] == 0;

    val[1] = A[1];
    for (int i = 2; i <= N; i++) {
        val[i] = val[i - 1];
        if (A[i] != 0)
            val[i] = min(val[i], A[i]);
    }

    if (cnt == 0)
        ans = N;
    else {
        ans = N - cnt, flag = true;
        for (int i = 1; i <= N; i++)
            if (A[i] == 0) {
                X = i;
                break;
            }
        for (int i = N; i >= X + 1; i--) {
            if (A[i] == 0)
                continue;
            chk[A[i]] = true;
            while (chk[K])
                K++;
        }
        for (int i = X; i > 1; i--) {
            chk[A[i]] = true;
            while (chk[K])
                K++;
            flag &= val[i - 1] >= K;
        }
        if (flag)
            ans++;
    }

    cout << ans << '\n';
    chk.clear();
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