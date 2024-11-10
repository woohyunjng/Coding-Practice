#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], lft[MAX], rgt[MAX], sm[MAX];

void solve() {
    int N, M, V, X = 0, L, R, res = -1;
    cin >> N >> M >> V;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sm[i] = sm[i - 1] + A[i];
    }

    lft[0] = 0, rgt[N + 1] = 0;

    for (int i = 1; i <= N; i++) {
        lft[i] = lft[i - 1];
        X += A[i];

        if (X >= V)
            lft[i]++, X = 0;
    }

    X = 0;

    for (int i = N; i >= 1; i--) {
        rgt[i] = rgt[i + 1];
        X += A[i];

        if (X >= V)
            rgt[i]++, X = 0;
    }

    R = N;
    while (R > 0 && rgt[R] < M)
        R--;
    if (R > 0)
        res = max(res, sm[R - 1]);

    for (L = 1; L <= N; L++) {
        while (R < N + 1 && lft[L] + rgt[R + 1] >= M)
            R++;

        if (lft[L] + rgt[R] >= M) {
            res = max(res, sm[R - 1] - sm[L]);
        }
    }

    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}