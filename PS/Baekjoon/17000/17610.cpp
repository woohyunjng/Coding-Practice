#include <bits/stdc++.h>
using namespace std;

bool dp[6'000'000];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S = 0, X, ans = 0;
    vector<int> arr;

    cin >> N;
    while (N--)
        cin >> X, S += X, arr.push_back(X);

    sort(arr.begin(), arr.end()), dp[S] = true;

    for (int i : arr) {
        for (int j = S; j >= -S + i; j--)
            dp[j + S] |= dp[j - i + S];
        for (int j = -S; j + i <= S; j++)
            dp[j + S] |= dp[j + i + S];
    }

    for (int i = 1; i <= S; i++)
        ans += !dp[i + S];

    cout << ans << '\n';

    return 0;
}