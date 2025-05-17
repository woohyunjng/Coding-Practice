#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int two[MAX];

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = 0, X;

    cin >> N >> M, two[0] = 1;
    for (int i = 1; i <= N; i++)
        two[i] = (two[i - 1] * 2) % M;

    for (int i = 2; i < N; i++) {
        X = gcd(i, N);
        if (X == 1)
            continue;
        ans = (ans + two[X - 1] - 1 + M) % M;
    }
    ans = ans * (N - 2) % M;

    cout << ans << '\n';

    return 0;
}
