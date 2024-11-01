#include <bits/stdc++.h>
#define int long long

#define MAX 400100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr arr[MAX];
int vis[MAX];
bool vst[MAX], chk[MAX];

vector<pr> adj[MAX], res;

int dfs(int K) {
    vector<int> edge;
    int X;

    for (pr i : adj[K]) {
        if (vst[i.first])
            continue;

        vst[i.first] = true, vis[i.first] = vis[K] + 1;
        X = dfs(i.first);

        if (X)
            res.push_back({i.second, X}), chk[i.second] = chk[X] = true;
    }

    for (pr i : adj[K]) {
        if (vis[i.first] < vis[K])
            continue;
        if (!chk[i.second])
            edge.push_back(i.second);
    }

    for (int i = 0; i * 2 + 1 < edge.size(); i++)
        res.push_back({edge[i * 2], edge[i * 2 + 1]}), chk[edge[i * 2]] = chk[edge[i * 2 + 1]] = true;
    if (edge.size() & 1)
        return edge.back();
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, A, B, X;
    vector<int> X_comp, Y_comp, rest;

    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= 2 * N; i++) {
            cin >> arr[i].first >> arr[i].second;
            X_comp.push_back(arr[i].first), Y_comp.push_back(arr[i].second);
        }

        sort(X_comp.begin(), X_comp.end()), X_comp.erase(unique(X_comp.begin(), X_comp.end()), X_comp.end());
        sort(Y_comp.begin(), Y_comp.end()), Y_comp.erase(unique(Y_comp.begin(), Y_comp.end()), Y_comp.end());

        for (int i = 1; i <= 2 * N; i++) {
            arr[i].first = lower_bound(X_comp.begin(), X_comp.end(), arr[i].first) - X_comp.begin() + 1;
            arr[i].second = lower_bound(Y_comp.begin(), Y_comp.end(), arr[i].second) - Y_comp.begin() + 1 + X_comp.size();
            adj[arr[i].first].push_back({arr[i].second, i}), adj[arr[i].second].push_back({arr[i].first, i});
        }

        X = N;
        N = X_comp.size() + Y_comp.size();

        for (int i = 1; i <= N; i++) {
            if (vst[i])
                continue;
            vst[i] = true, vis[i] = 0;
            dfs(i);
        }

        cout << res.size() << '\n';

        for (int i = 1; i <= 2 * X; i++) {
            if (chk[i])
                continue;
            rest.push_back(i);
        }

        for (int i = 0; i * 2 + 1 < rest.size(); i++)
            cout << rest[i * 2] << ' ' << rest[i * 2 + 1] << '\n';
        for (pr i : res)
            cout << i.first << ' ' << i.second << '\n';

        X_comp.clear(), Y_comp.clear();
        for (int i = 1; i <= N; i++)
            adj[i].clear();
        res.clear(), rest.clear();
        fill(vst, vst + N + 1, false), fill(chk, chk + 2 * X + 1, false);
    }

    return 0;
}