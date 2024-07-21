#include <bits/stdc++.h>
#define int long long
#define MAX 5010

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dp[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, res = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A;
        arr.push_back(A);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (!dp[i][j])
                dp[i][j] = 2;
            res = max(res, dp[i][j]);

            A = lower_bound(arr.begin(), arr.end(), arr[j] * 2 - arr[i]) - arr.begin();
            if (A <= arr.size() && arr[A] == arr[j] * 2 - arr[i])
                dp[j][A] = dp[i][j] + 1;
        }
    }

    cout << res;

    return 0;
}