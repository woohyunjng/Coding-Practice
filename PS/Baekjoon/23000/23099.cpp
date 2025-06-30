#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 100001;
const int MAX = 17;

int C[MAX_H], D[MAX], L[MAX], V[MAX], M[1 << MAX][2];
bool dp[MAX][1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, T, S, X = 0, ans = 0;
    bool flag = true;
    vector<int> arr;

    cin >> H >> T;
    for (int i = 1; i <= H; i++)
        cin >> C[i], flag &= C[i] <= T;
    for (int i = 0; i < T; i++)
        cin >> D[i] >> L[i];

    if (!flag) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= C[i]; j++)
            V[j]++;
        if (X > C[i]) {
            for (int j = C[i] + 1; j <= X; j++)
                arr.push_back(V[j]), V[j] = 0;
        }
        X = C[i];
    }

    for (int i = 1; i <= T; i++) {
        if (V[i] > 0)
            arr.push_back(V[i]), V[i] = 0;
    }

    if (arr.size() > T || accumulate(arr.begin(), arr.end(), 0) > accumulate(D, D + T, 0)) {
        cout << 0 << '\n';
        return 0;
    }

    S = arr.size();
    for (int i = 1; i <= S; i++)
        V[i] = V[i - 1] + arr[i - 1];

    for (int i = 0; i < (1 << T); i++) {
        for (int j = 0; j < T; j++)
            if (i & (1 << j))
                M[i][0] += D[j], M[i][1] += L[j];
    }

    dp[0][0] = true;
    for (int i = 1; i <= S; i++) {
        for (int j = 0; j < (1 << T); j++) {
            dp[i][j] |= dp[i - 1][j];
            for (int k = 0; k < T; k++)
                if (!(j & (1 << k)))
                    dp[i][j | (1 << k)] |= dp[i][j];
        }
        for (int j = 0; j < (1 << T); j++)
            dp[i][j] &= V[i] == M[j][0];
    }

    for (int i = 0; i < (1 << T); i++)
        if (dp[S][i])
            ans = max(ans, M[i][1]);
    cout << ans << '\n';

    return 0;
}