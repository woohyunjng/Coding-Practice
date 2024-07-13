#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
#define MAX 100
#define MAX_VAL 10000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], dif[MAX][MAX], dp[MAX][MAX_VAL][MAX], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, zero;
    vector<int> diff;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++)
            diff.push_back(arr[j] - arr[i]);
    }
    diff.push_back(0);

    sort(diff.begin(), diff.end());
    diff.erase(unique(diff.begin(), diff.end()), diff.end());
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++)
            dif[i][j] = lower_bound(diff.begin(), diff.end(), arr[j] - arr[i]) - diff.begin();
    }
    zero = lower_bound(diff.begin(), diff.end(), 0) - diff.begin();

    for (int i = 1; i <= N; i++) {
        dp[i][0][1] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 2; k <= j + 1; k++) {
                if (k == 2) {
                    dp[i][dif[j][i]][k]++;
                } else
                    dp[i][dif[j][i]][k] = (dp[i][dif[j][i]][k] + dp[j][dif[j][i]][k - 1]) % MOD;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < diff.size(); j++) {
            for (int k = 1; k <= N; k++)
                res[k] = (res[k] + dp[i][j][k]) % MOD;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';

    return 0;
}