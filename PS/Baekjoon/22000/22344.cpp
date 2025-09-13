#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;

vector<pr> adj[MAX];
set<int> lst;

int V[MAX][2], depth[MAX];
bool ans_chk = true;

void dfs(int node, int par) {
    depth[node] = depth[par] + 1;
    for (pr i : adj[node]) {
        if (i[0] == par)
            continue;
        else if (!depth[i[0]]) {
            V[i[0]][0] = -V[node][0], V[i[0]][1] = i[1] - V[node][1];
            dfs(i[0], node);
        } else if (depth[i[0]] < depth[node]) {
            if (V[node][0] + V[i[0]][0] == 0)
                ans_chk &= V[node][1] + V[i[0]][1] == i[1];
            else {
                ans_chk &= (i[1] - (V[node][1] + V[i[0]][1])) % 2 == 0;
                lst.insert((i[1] - (V[node][1] + V[i[0]][1])) / (V[node][0] + V[i[0]][0]));
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, C, ans = 0;
    vector<int> arr;

    cin >> N >> M;
    while (M--) {
        cin >> A >> B >> C;
        adj[A].push_back({B, C}), adj[B].push_back({A, C});
    }

    V[1][0] = 1, V[1][1] = 0;
    dfs(1, 0), ans_chk &= lst.size() <= 1;

    for (int i = 1; i <= N; i++) {
        if (V[i][0] == 1)
            arr.push_back(-V[i][1]);
        else if (V[i][0] == -1)
            arr.push_back(V[i][1]);
    }

    sort(arr.begin(), arr.end()), A = lst.empty() ? arr[N / 2] : *lst.begin();

    if (!ans_chk)
        cout << "No" << '\n';
    else {
        cout << "Yes" << '\n';
        for (int i = 1; i <= N; i++)
            cout << V[i][0] * A + V[i][1] << ' ';
        cout << '\n';
    }

    return 0;
}