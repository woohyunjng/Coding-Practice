#include <bits/stdc++.h>
#define int long long

#define MAX 400100
using namespace std;

int L[MAX], R[MAX], res[MAX], sm[MAX], chk[MAX];

void solve() {
    int N;
    cin >> N;

    fill(res + 1, res + N + 1, 1), fill(sm + 1, sm + 2 * N + 1, 0), fill(chk + 1, chk + 2 * N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        if (L[i] == R[i])
            chk[L[i]]++;
    }

    for (int i = 1; i <= 2 * N; i++)
        sm[i] = sm[i - 1] + (chk[i] >= 1);

    for (int i = 1; i <= N; i++) {
        if (L[i] == R[i])
            res[i] = chk[L[i]] <= 1;
        else
            res[i] = (sm[R[i]] - sm[L[i] - 1]) != (R[i] - L[i] + 1);
    }

    for (int i = 1; i <= N; i++)
        cout << res[i];
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