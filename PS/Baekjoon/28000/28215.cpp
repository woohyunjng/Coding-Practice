#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 51;

int N, K, X[MAX], Y[MAX], ans = 0x3f3f3f3f3f3f3f3f;
vector<int> arr;

void dfs(int node, int cnt) {
    int res = 0, V;
    if (cnt == K) {
        for (int i = 0; i < N; i++) {
            V = 0x3f3f3f3f3f3f3f3f;
            for (int j : arr)
                V = min(V, abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
            res = max(res, V);
        }
        ans = min(ans, res);
        return;
    }
    if (node >= N)
        return;

    dfs(node + 1, cnt);
    arr.push_back(node), dfs(node + 1, cnt + 1), arr.pop_back();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    dfs(0, 0);

    cout << ans << '\n';

    return 0;
}