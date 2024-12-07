#include <bits/stdc++.h>
#define int long long

#define MAX 510
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], U[MAX], C[MAX], dp[MAX][50010];
vector<int> colors[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, K, A, res = 0;
    vector<int> comp;
    cin >> N >> X >> K;

    for (int i = 1; i <= N; i++)
        cin >> P[i] >> U[i] >> C[i], comp.push_back(C[i]);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 1; i <= N; i++)
        colors[lower_bound(comp.begin(), comp.end(), C[i]) - comp.begin() + 1].push_back(i);
    A = comp.size();

    for (int i = 1; i <= A; i++) {
        for (int j = 0; j <= X; j++)
            dp[i][j] = dp[i - 1][j];

        for (int j : colors[i]) {
            for (int k = X; k >= 0; k--) {
                if (k >= P[j])
                    dp[i][k] = max({dp[i][k], dp[i - 1][k - P[j]] + U[j] + K, dp[i][k - P[j]] + U[j]});
                res = max(res, dp[i][k]);
            }
        }
    }

    cout << res << '\n';

    return 0;
}