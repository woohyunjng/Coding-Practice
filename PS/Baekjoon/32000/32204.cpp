#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int left_dp[MAX], right_dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<pr> arr;

    int N, X, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X;
        if (!arr.empty() && arr.back().first == X)
            arr.back().second++;
        else
            arr.push_back({X, 1});
    }

    N = arr.size();
    left_dp[0] = arr[0].second, right_dp[N - 1] = arr[N - 1].second;

    for (int i = 1; i < N; i++) {
        if (arr[i].first > arr[i - 1].first)
            left_dp[i] = left_dp[i - 1] + arr[i].second;
        else
            left_dp[i] = arr[i].second;
    }

    for (int i = N - 2; i >= 0; i--) {
        if (arr[i].first > arr[i + 1].first)
            right_dp[i] = right_dp[i + 1] + arr[i].second;
        else
            right_dp[i] = arr[i].second;
    }

    for (int i = 0; i < N; i++)
        res += (left_dp[i] - arr[i].second) * (right_dp[i] - arr[i].second) + arr[i].second * (left_dp[i] + right_dp[i] - arr[i].second * 2) + arr[i].second * (arr[i].second + 1) / 2;

    cout << res;

    return 0;
}