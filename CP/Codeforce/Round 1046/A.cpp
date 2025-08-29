#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int A[MAX], dp[MAX];
vector<int> arr[MAX];

void solve() {
    int N, ans;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr[A[i]].clear();

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1], arr[A[i]].push_back(i);
        if (arr[A[i]].size() < A[i])
            continue;
        dp[i] = max(dp[i], dp[arr[A[i]][((int)arr[A[i]].size() - A[i])] - 1] + A[i]);
    }

    ans = dp[N];
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
