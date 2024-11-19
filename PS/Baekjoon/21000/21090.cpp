#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MAX_K 10100ll
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int C[MAX], P[MAX];

int dp[2][MAX_K];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, res = 0;
    vector<int> arr;

    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        arr.push_back(i);
    }

    for (int i = 1; i <= N; i++)
        cin >> P[i];

    sort(arr.begin(), arr.end(), [&](int a, int b) {
        return P[a] > P[b];
    });

    for (int i = 1; i < MAX_K; i++)
        dp[0][i] = S + 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= min(N, MAX_K - 1); j++) {
            dp[i & 1][j] = min(dp[(i & 1) ^ 1][j], dp[(i & 1) ^ 1][j - 1] + P[arr[i - 1]] * (j - 1) + C[arr[i - 1]]);
            if (dp[i & 1][j] <= S)
                res = max(res, j);
            else
                dp[i & 1][j] = S + 1;
        }
    }

    cout << res << '\n';

    return 0;
}