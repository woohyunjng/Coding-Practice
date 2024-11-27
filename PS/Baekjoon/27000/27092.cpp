#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> child[MAX], depth[MAX];
int dp[MAX];

int dfs(int K) {
    int X = 0, A;
    vector<pr> arr;
    vector<int> val;

    for (int i : child[K]) {
        X += dfs(i), dp[K] += dp[i];
        arr.push_back({depth[i].size(), i});
    }
    sort(arr.begin(), arr.end(), greater<pr>());

    if (arr.size()) {
        A = arr[0].second;
        X += dp[A] + depth[A].size();
    }

    if (arr.size() > 1)
        for (int i = 1; i <= depth[arr[1].second].size(); i++)
            val.push_back(depth[A][depth[A].size() - i]);

    for (int i = 1; i < arr.size(); i++) {
        for (int j = 1; j <= depth[arr[i].second].size(); j++) {
            X = (X - val[j - 1] + MOD) % MOD;
            val[j - 1] = val[j - 1] * depth[arr[i].second][depth[arr[i].second].size() - j] % MOD;
            X = (X + val[j - 1]) % MOD;
        }
    }

    for (int i = 1; i < arr.size(); i++)
        for (int j = 1; j <= depth[arr[i].second].size(); j++)
            depth[A][depth[A].size() - j] += depth[arr[i].second][depth[arr[i].second].size() - j] - 1;

    if (arr.size() >= 1)
        swap(depth[K], depth[A]);

    depth[K].push_back(2), dp[K]++, X += 2;

    cout << K << ' ' << X << ' ' << dp[K] << '\n';
    for (int i : depth[K])
        cout << i << ' ';
    cout << '\n';
    cout << (X - dp[K] - depth[K].size() + MOD) % MOD << '\n';

    return (X - dp[K] - depth[K].size() + MOD) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X;
        if (X != -1)
            child[X].push_back(i);
    }

    cout << dfs(1) << '\n';

    return 0;
}