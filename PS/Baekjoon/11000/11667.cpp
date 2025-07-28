#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;
const int MAX_S = 100001;
const int INF = 2'000'000'000;

int A[MAX], B[MAX], dp[MAX][MAX];
vector<int> arr[MAX_S];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M = 0, P, ans = 0, S = 0;
    vector<int> lst, val;
    multiset<int> st;

    cin >> N >> P;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i], M = max(M, B[i]);
        arr[B[i]].push_back(i);
    }

    for (int i = 1; i <= M; i++) {
        sort(arr[i].begin(), arr[i].end(), [&](int x, int y) { return A[x] < A[y]; });
        for (int j : arr[i]) {
            if (st.lower_bound(A[j]) != st.end())
                lst.push_back(B[j] - A[j]);
            else
                val.push_back(j);
            st.insert(A[j]);
        }
    }

    sort(lst.begin(), lst.end(), greater<int>()), N = val.size();

    val.push_back(0);
    sort(val.begin(), val.end(), [&](int x, int y) { return B[x] < B[y]; });

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= P; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= P; j++)
            for (int k = i - 1; k >= 0 && B[val[k + 1]] > A[val[i]]; k--)
                dp[i][j] = max(dp[i][j], dp[k][j - 1] + B[val[k + 1]] - A[val[i]]);

    ans = dp[N][P];
    for (int i = 0; i < min(P, (int)lst.size()); i++)
        S += lst[i], ans = max(ans, S + (i == P ? 0 : dp[N][P - i - 1]));

    cout << ans << '\n';

    return 0;
}