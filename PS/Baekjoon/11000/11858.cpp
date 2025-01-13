#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MAX_K 110
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 2> pr;

int dp[MAX_K][MAX], A[MAX];

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int N, K, X;
    vector<pr> st;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++)
        dp[1][i] = max(dp[1][i - 1], A[i]);

    for (int i = 2; i <= K; i++) {
        st.clear();
        for (int j = i; j <= N; j++) {
            X = dp[i - 1][j - 1];
            while (!st.empty() && st.back()[0] <= A[j])
                X = min(X, st.back()[1]), st.pop_back();
            if (st.empty() || X + A[j] < st.back()[0] + st.back()[1])
                st.push_back({A[j], X});
            dp[i][j] = st.back()[0] + st.back()[1];
        }
    }

    cout << dp[K][N] << '\n';

    return 0;
}