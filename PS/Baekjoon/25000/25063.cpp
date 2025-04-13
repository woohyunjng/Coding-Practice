#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

vector<int> adj[MAX];
int sz[MAX], A[MAX], cnt[MAX];
bitset<MAX> dp, mask;

int get_sz(int node, int par) {
    sz[node] = 1;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        sz[node] += get_sz(i, node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (int i : adj[node]) {
        if (i == par)
            continue;
        if (sz[i] * 2 > cap)
            return get_cent(i, node, cap);
    }
    return node;
}

int dfs(int node, int par) {
    int res = 0;
    for (int i : adj[node]) {
        if (i == par)
            continue;
        res += dfs(i, node) + sz[i];
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans, C, S;

    cin >> N, ans = N;
    for (int i = 2; i <= N; i++) {
        cin >> X;
        adj[X].push_back(i), adj[i].push_back(X);
    }

    C = get_cent(1, -1, get_sz(1, -1)), get_sz(C, -1);

    vector<int> arr;
    for (int i : adj[C]) {
        ans += sz[i] + dfs(i, C);
        cnt[sz[i]]++;
    }

    X = 0;
    for (int i = 1; i <= N; i++) {
        X = cnt[i], cnt[i] = 0;
        while (X) {
            cnt[(X - (X >> 1)) * i]++;
            X >>= 1;
        }
        while (cnt[i])
            arr.push_back(i), cnt[i]--;
    }

    for (int i = 0; i < arr.size(); i++)
        A[i + 1] = arr[i];
    S = arr.size();

    for (int i = 0; i <= N; i++)
        mask[i] = true;

    dp[0] = true;
    for (int i = 1; i <= S; i++)
        dp |= (dp << A[i]) & mask;

    for (int i = 1; i <= N; i++)
        if (dp[i])
            X = max(X, i * (N - 1 - i));
    ans += X;

    cout << ans << '\n';

    return 0;
}