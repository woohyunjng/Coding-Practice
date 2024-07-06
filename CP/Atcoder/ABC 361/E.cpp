#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;

typedef pair<int, int> pr;

vector<pr> arr[MAX];
int dp[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, A, B, C, res = 0, cnt, mx = 0, K;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B >> C;
        arr[A].push_back({B, C});
        arr[B].push_back({A, C});
    }

    queue<int> q;
    q.push(1);
    checked[1] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (pr i : arr[cur]) {
            if (checked[i.first])
                continue;
            checked[i.first] = true;
            q.push(i.first);
            dp[i.first] = dp[cur] + i.second;
            if (dp[i.first] > mx) {
                mx = dp[i.first];
                K = i.first;
            }
            res += i.second;
        }
    }

    fill(checked, checked + N + 1, false);
    fill(dp, dp + N + 1, 0);

    q.push(K);
    checked[K] = true;
    mx = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (pr i : arr[cur]) {
            if (checked[i.first])
                continue;
            checked[i.first] = true;
            q.push(i.first);
            dp[i.first] = dp[cur] + i.second;
            mx = max(dp[i.first], mx);
        }
    }

    cout << res * 2 - mx;

    return 0;
}