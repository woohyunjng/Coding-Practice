#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 5001;

int gcd(int X, int Y) {
    if (X * Y == 0)
        return X + Y;
    return Y ? gcd(Y, X % Y) : X;
}

int cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, S = 0, V, ans = 1;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X, S = max(S, X), cnt[X]++;

    for (int i = 1; i <= S; i++) {
        V = 0, X = 0;

        for (int j = 1; j <= S; j++) {
            if (!cnt[j])
                continue;
            if (j % i == 0)
                X += cnt[j];
            else
                V = gcd(V, j);
        }

        if (X > 0)
            ans = max(ans, i + V);
        if (X > 1) {
            for (int j = 1; j <= S; j++) {
                if (!cnt[j] || j % i != 0)
                    continue;
                ans = max(ans, i + gcd(V, j));
            }
        }
    }

    cout << ans << '\n';

    return 0;
}