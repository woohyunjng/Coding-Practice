#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int MOD = 1'000'000'007;

vector<int> adj[MAX], val[MAX];
int D[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, ans = 0;
    vector<int> arr;

    cin >> N >> M;
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        arr.push_back(i);
    sort(arr.begin(), arr.end(), [](int x, int y) { return adj[x].size() < adj[y].size(); });

    for (int i = 0; i < N; i++)
        D[arr[i]] = i + 1;

    for (int i = 1; i <= N; i++) {
        for (int j : adj[i])
            if (D[j] < D[i])
                val[i].push_back(j);
    }

    for (int i = 1; i <= N; i++) {
        for (int j : val[i])
            for (int k : adj[j]) {
                if (D[k] >= D[i])
                    continue;
                C[k]++;
            }
        for (int j : val[i])
            for (int k : adj[j])
                ans += C[k] * (C[k] - 1) / 2, C[k] = 0, ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}