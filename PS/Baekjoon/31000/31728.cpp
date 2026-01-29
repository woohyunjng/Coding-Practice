#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 301;
const int INF = 0x3f3f3f3f3f3f3f3f;

int H[MAX], C[MAX], dp[MAX << 1][MAX][MAX], M[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, S, X, Y, ans = INF;
    vector<int> comp;
    set<int> st;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> H[i] >> C[i], X = H[i];
        while (st.find(X) != st.end())
            X++;
        st.insert(X);
    }

    for (int i : st)
        comp.push_back(i);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    for (int i = 1; i <= S; i++)
        for (int j = 1; j <= N; j++)
            for (int k = 0; k <= N; k++)
                dp[i][j][k] = INF;

    M[0] = INF;
    for (int i = 1; i <= N; i++) {
        H[i] = lower_bound(comp.begin(), comp.end(), H[i]) - comp.begin() + 1;
        arr[H[i]].push_back(i);
    }

    dp[1][1][0] = 0;
    for (int i = 1; i <= S; i++) {
        M[i] = M[i - 1], X = arr[i].size();
        for (int j : arr[i])
            M[i] = min(M[i], C[j]);
        for (int j = 1; j < N; j++)
            for (int k = 0; k <= N - X; k++) {
                if (dp[i][j][k] == INF)
                    continue;
                Y = max(0ll, k + X - j);
                dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i][j][k] + M[i - 1]);
                dp[i + 1][j][Y] = min(dp[i + 1][j][Y], dp[i][j][k] + Y * K * (comp[i] - comp[i - 1]));
            }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= N; j++)
            if (arr[S].size() + j <= i)
                ans = min(ans, dp[S][i][j]);
    cout << ans << '\n';

    return 0;
}