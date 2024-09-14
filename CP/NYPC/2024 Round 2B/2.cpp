#include <bits/stdc++.h>
#define int long long

#define MAX 2010
#define MOD 1000000007
using namespace std;

int arr[MAX], dp[MAX][MAX], val[MAX][MAX];
vector<int> comp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, X;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++)
            comp[j].push_back(arr[j] - arr[i]);
    }

    for (int i = 1; i <= N; i++) {
        sort(comp[i].begin(), comp[i].end());
        comp[i].erase(unique(comp[i].begin(), comp[i].end()), comp[i].end());
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            auto K = lower_bound(comp[i].begin(), comp[i].end(), arr[j] - arr[i]);
            if (K != comp[i].end() && *K == arr[j] - arr[i])
                dp[i][j] = (1 + val[i][K - comp[i].begin()]) % MOD;
            else
                dp[i][j] = 1;

            X = lower_bound(comp[j].begin(), comp[j].end(), arr[j] - arr[i]) - comp[j].begin();
            val[j][X] = (val[j][X] + dp[i][j]) % MOD;
            res = (res + dp[i][j]) % MOD;
        }
    }

    cout << res;

    return 0;
}