#include <bits/stdc++.h>
#define int long long

#define MAX 2100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], C[MAX], X[MAX];

int dp[MAX][MAX * 2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, K;
    vector<int> arr;
    cin >> N >> A >> B;

    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> C[i] >> X[i];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int A, int B) { return X[A] < X[B]; });

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= A + B; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j)
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);

            if (j <= B) {
                if (j + C[arr[i - 1]] * X[arr[i - 1]] <= B)
                    dp[i][j + C[arr[i - 1]] * X[arr[i - 1]]] = max(dp[i][j + C[arr[i - 1]] * X[arr[i - 1]]], dp[i - 1][j] + P[arr[i - 1]]);
                else if (C[arr[i - 1]] - (B - j) / X[arr[i - 1]] <= A)
                    dp[i][B + C[arr[i - 1]] - (B - j) / X[arr[i - 1]]] = max(dp[i][B + C[arr[i - 1]] - (B - j) / X[arr[i - 1]]], dp[i - 1][j] + P[arr[i - 1]]);
            } else {
                if (j + C[arr[i - 1]] <= A + B)
                    dp[i][j + C[arr[i - 1]]] = max(dp[i][j + C[arr[i - 1]]], dp[i - 1][j] + P[arr[i - 1]]);
            }
        }
    }

    cout << dp[N][A + B] << '\n';

    return 0;
}