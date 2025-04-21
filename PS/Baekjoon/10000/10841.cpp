#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 5> tp;

const int MAX = 3001;

int P[MAX], L[MAX], R[MAX], H[MAX], K[MAX], dp[MAX][MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, W, ans = 0;
    vector<int> comp;
    vector<tp> lst;

    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> L[i] >> R[i] >> H[i] >> K[i];
        comp.push_back(L[i]), comp.push_back(R[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= N; i++) {
        L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1;
        R[i] = lower_bound(comp.begin(), comp.end(), R[i]) - comp.begin() + 1;
        lst.push_back({L[i], R[i], H[i], K[i], P[i]});
    }

    sort(lst.begin(), lst.end());

    for (int i = 1; i <= N; i++) {
        L[i] = lst[i - 1][0], R[i] = lst[i - 1][1], H[i] = lst[i - 1][2], K[i] = lst[i - 1][3], P[i] = lst[i - 1][4];
        arr[L[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        dp[i][0] = K[i];
        for (int j = 1; j <= S; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            for (int k : arr[j]) {
                if (!(R[i] <= L[k] || R[k] <= L[i]) && ((P[i] == P[k]) || H[i] + H[k] > W))
                    continue;
                if (R[i] >= R[k])
                    dp[i][R[k]] = max(dp[i][R[k]], K[k] + dp[i][j]);
                ` else dp[k][R[i]] = max(dp[k][R[i]], K[k] + dp[i][j]);
            }
        }
        ans = max(ans, dp[i][S]);
    }

    cout << ans << '\n';

    return 0;
}