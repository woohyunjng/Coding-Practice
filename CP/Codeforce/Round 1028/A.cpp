#include <bits/stdc++.h>
using namespace std;

const int MAX = 5001;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

int A[MAX], V[MAX];

void solve() {
    int N, S = 0, X, ans, cnt = 0;
    bool flag = false;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    X = A[1];
    for (int i = 2; i <= N; i++)
        X = gcd(X, A[i]);
    for (int i = 1; i <= N; i++) {
        A[i] /= X, S = max(S, A[i]);
        cnt += A[i] == 1;
    }

    if (cnt > 0) {
        cout << N - cnt << '\n';
        return;
    }

    for (int i = 1; i <= S; i++)
        V[i] = N;
    V[A[1]] = 1;

    for (int i = 2; i <= N; i++) {
        V[A[i]] = min(V[A[i]], 1);
        for (int j = 1; j <= S; j++) {
            if (V[j] == N)
                continue;
            V[gcd(j, A[i])] = min(V[gcd(j, A[i])], V[j] + 1);
        }
    }

    ans = V[1] + N - 2;
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