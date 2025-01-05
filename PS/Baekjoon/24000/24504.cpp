#include <bits/stdc++.h>
#define int long long

#define MAX 300100

using namespace std;
typedef pair<int, int> pr;

vector<pr> adj[MAX];
vector<int> ans;
int vst[MAX], num = 0;

pr dfs(int node, int par) {
    int res = ++num, cnt = 0;
    pr X;

    vst[node] = res;

    for (pr i : adj[node]) {
        if (i.first == par)
            continue;
        else if (vst[i.first]) {
            res = min(res, vst[i.first]);
            if (vst[i.first] > vst[node])
                ans.push_back(i.second), cnt++;
        } else {
            X = dfs(i.first, node), res = min(res, X.first);
            cnt += X.second + 1;
            if (X.first > vst[node]) {
                if (X.second % 2 == 0)
                    ans.push_back(i.second);
            } else
                ans.push_back(i.second);
        }
    }

    return {res, cnt};
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> U >> V;
        adj[U].push_back({V, i}), adj[V].push_back({U, i});
    }

    if (M & 1)
        dfs(1, -1);

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
    if (!ans.empty()) {
        for (int i : ans)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}