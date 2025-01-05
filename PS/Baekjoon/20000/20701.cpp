#include <bits/stdc++.h>
#define int long long

#define MAX 200100
using namespace std;

vector<int> adj[MAX], res[MAX];

void dfs(int K) {
    vector<int> cur, ims;
    res[K].push_back(K);

    for (int i : adj[K]) {
        dfs(i);

        ims = cur;
        cur.clear();

        for (int j : ims)
            cur.push_back(j);
        for (int j = 0; j < res[i].size(); j++) {
            cur.push_back(res[i][j]);
            reverse(ims.begin(), ims.end());
            for (int k : ims)
                cur.push_back(k);
        }
    }

    for (int i : cur)
        res[K].push_back(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        cin >> A;
        adj[A].push_back(i);
    }

    dfs(1);

    cout << res[1].size() - 1 << '\n';
    for (int i = 1; i < res[1].size(); i++)
        cout << res[1][i] << ' ';

    return 0;
}