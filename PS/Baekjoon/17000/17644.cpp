#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;

int D[MAX], W[MAX];
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

    if (D[node] != 0) {
        while (true) {
            iter = res.lower_bound({D[node] + 1, 0});
            if (iter == res.end())
                break;
            K = *iter, X += K[1], res.erase(iter);
            if (X > W[node]) {
                res.insert({K[0], X - W[node]});
                break;
            }
        }
        res.insert({D[node], W[node]});
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, Z, ans = 0;

    cin >> N >> M >> K;
    for (int i = 2; i <= N; i++)
        cin >> X, adj[X].push_back(i);

    while (M--) {
        cin >> X >> Y >> Z;
        D[X] = Y, W[X] = Z;
    }

    multiset<pr> ret = dfs(1);
    for (pr i : ret)
        ans += i[1];

    cout << ans << '\n';

    return 0;
}