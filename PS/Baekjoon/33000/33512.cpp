#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200000;

int gcd(int X, int Y) { return Y ? gcd(Y, X % Y) : X; }

int A[MAX], cnt[MAX];

int mn_gcd(int N, int K) {
    int res = gcd(A[1], K);
    for (int i = 2; i <= N; i++)
        res = min(res, gcd(A[i], K));
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, ans, X, Y, mxG, mnG;
    cin >> T;

    while (T--) {
        cin >> N >> K, X = 0;
        for (int i = 1; i <= N; i++)
            cin >> A[i], X = max(X, A[i]);

        fill(cnt, cnt + MAX, 0);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j * j <= A[i]; j++) {
                if (A[i] % j)
                    continue;
                cnt[j]++, cnt[A[i] / j]++;
                if (j * j == A[i])
                    cnt[j]--;
            }
        }

        for (int i = 1; i <= X; i++)
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;

        mxG = 0, mnG = MAX;
        for (int i = X; i > 0; i--) {
            if (cnt[i])
                mxG = max(mxG, i), mnG = min(mnG, i);
            cnt[1] -= cnt[i];
            for (int j = 2; j * j <= i; j++) {
                if (i % j)
                    continue;
                cnt[j] -= cnt[i], cnt[i / j] -= cnt[i];
                if (j * j == i)
                    cnt[j] += cnt[i];
            }
        }

        ans = mxG - mnG;

        if (K == 1)
            ans = max({ans, mxG - 1, X - mnG});
        else if (K == 2) {
            ans = max(ans, X - 1);
            for (int i = 0; i <= 2; i++)
                ans = max(ans, 100000 - i - min(mnG, mn_gcd(N, 100000 - i)));
        } else if (K >= 3)
            ans = 100000 - 1;

        cout << ans << '\n';
    }

    return 0;
}