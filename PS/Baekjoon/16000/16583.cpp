#include <bits/stdc++.h>
#define int long long

#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
vector<tp> ans;
int vis[MAX], chk[MAX];

int dfs(int X) {
    vector<int> arr;
    int K;

    for (pr i : adj[X]) {
        if (vis[i.first])
            continue;
        vis[i.first] = vis[X] + 1, K = dfs(i.first);
        if (K) {
            chk[i.second] = 1;
            ans.push_back({X, i.first, K});
        }
    }

    for (pr i : adj[X]) {
        if (vis[i.first] > vis[X] && !chk[i.second])
            arr.push_back(i.first);
    }

    for (int i = 0; i * 2 + 1 < arr.size(); i++)
        ans.push_back({arr[i * 2], X, arr[i * 2 + 1]});
    if (arr.size() & 1)
        return arr.back();
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> X >> Y;
        adj[X].push_back({Y, i}), adj[Y].push_back({X, i});
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i])
            continue;
        vis[i] = 1, dfs(i);
    }

    cout << ans.size() << '\n';
    for (tp i : ans)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

    return 0;
}