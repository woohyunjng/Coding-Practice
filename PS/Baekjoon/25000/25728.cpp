#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;
const int MOD = 998244353;

int X[MAX][2], Y[MAX][2], SX[MAX], SY[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X1, X2, Y1, Y2, K, ans = 0;
    vector<int> XV, YV;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i][0] >> Y[i][0] >> X[i][1] >> Y[i][1];
        XV.push_back(X[i][1]), YV.push_back(Y[i][1]);
    }

    sort(XV.begin(), XV.end()), sort(YV.begin(), YV.end());
    SX[0] = XV[0], SY[0] = YV[0];
    for (int i = 1; i < N; i++)
        SX[i] = SX[i - 1] + XV[i], SY[i] = SY[i - 1] + YV[i];

    for (int i = 0; i < N; i++) {
        K = lower_bound(XV.begin(), XV.end(), X[i][0]) - XV.begin() - 1;
        if (K >= 0)
            ans += X[i][0] * (K + 1) - SX[K], ans %= MOD;
        K = lower_bound(YV.begin(), YV.end(), Y[i][0]) - YV.begin() - 1;
        if (K >= 0)
            ans += Y[i][0] * (K + 1) - SY[K], ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}