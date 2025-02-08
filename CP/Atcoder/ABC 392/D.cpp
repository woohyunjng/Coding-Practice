#include <bits/stdc++.h>
#define int long long
#define double long double

#define MAX_N 200
#define MAX 200000

using namespace std;

int A[MAX_N][MAX], K[MAX_N], cnt[MAX_N][MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, val;
    double ans = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> K[i];
        for (int j = 1; j <= K[i]; j++)
            cin >> A[i][j], cnt[i][A[i][j]]++;
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++) {
            val = 0;
            for (int k = 1; k <= K[i]; k++) {
                if (chk[A[i][k]])
                    continue;
                chk[A[i][k]] = true, val += cnt[i][A[i][k]] * cnt[j][A[i][k]];
            }
            for (int k = 1; k <= K[i]; k++)
                chk[A[i][k]] = false;
            ans = max(ans, (double)val / (K[i] * K[j]));
        }

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}