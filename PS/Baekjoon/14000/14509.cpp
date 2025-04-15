#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;

int V[MAX];
vector<int> adj[MAX];

multiset<pr> dfs(int node) {
    multiset<pr> res, tmp;
    multiset<pr>::iterator iter;

    int X = 0;
    pr K;

    for (int i : adj[node]) {
        tmp = dfs(i);
        if (tmp.size() > res.size())
            swap(res, tmp);
        for (pr j : tmp)
            res.insert(j);
    }

    while (true) {
        iter = res.lower_bound({V[node], 0});
        if (iter == res.end())
            break;
        K = *iter, X += K[1], res.erase(iter);
        if (X > 1) {
            res.insert({K[0], X - 1});
            break;
        }
    }
    res.insert({V[node], 1});

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> V[i] >> X;
        adj[X].push_back(i);
    }

    multiset<pr> ret = dfs(1);
    for (pr i : ret)
        ans += i[1];

    cout << ans << '\n';

    return 0;
}