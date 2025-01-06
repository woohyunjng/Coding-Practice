#include <bits/stdc++.h>
#define int long long

#define MAX 110

using namespace std;
typedef pair<int, int> pr;

vector<int> arr[MAX];
bool checked[MAX];
int dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    string S;
    pr K;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++) {
            X = S[j - 1] - '0';
            if (X == 1)
                arr[i].push_back(j);
        }
    }

    dp[3] = 1, dp[4] = 2;
    for (int i = 5; i <= N; i++)
        dp[i] = dp[i - i / 3] + 1;

    queue<pr> q;
    q.push({1, 0}), checked[1] = true;

    while (!q.empty()) {
        K = q.front(), q.pop();

        for (int i : arr[K.first]) {
            if (checked[i])
                continue;

            if (i == 2) {
                cout << dp[K.second + 2] << '\n';
                return 0;
            }

            q.push({i, K.second + 1}), checked[i] = true;
        }
    }

    cout << -1 << '\n';

    return 0;
}