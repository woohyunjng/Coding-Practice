#include <bits/stdc++.h>

#define MAX 2000
using namespace std;

typedef array<int, 2> pr;

bool dp[MAX][MAX], root[MAX], valid[MAX];
int depth[MAX], parent[MAX];
vector<int> adj[MAX][2], arr[MAX][2];
vector<pr> ans;

void dfs(int t, int node) {
    arr[depth[node]][t].push_back(node);
    for (int i : adj[node][t])
        depth[i] = depth[node] + 1, dfs(t, i);
}

void add(int x, int y) {
    ans.push_back({x, y});
    for (int i : adj[x][0])
        adj[y][0].push_back(i);
    adj[x][0].clear();
}

void merge(int node) {
    vector<int> tmp[2];
    for (int i : adj[node][0])
        tmp[valid[i]].push_back(i);

    for (int i : tmp[0])
        for (int j : tmp[1])
            if (dp[i][j]) {
                add(i, j);
                break;
            }

    for (int i : tmp[1])
        merge(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, X, Y, R;
    bool flag;
    vector<int> st;

    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            root[i] = true;

        for (int i = 1; i < N; i++)
            cin >> X >> Y, adj[Y][0].push_back(X), root[X] = false;

        cin >> M;
        for (int i = 1; i < M; i++) {
            cin >> X >> Y, adj[Y][1].push_back(X), root[X] = false, parent[X] = Y;
            valid[X] = valid[Y] = true;
        }

        for (int i = 1; i <= N; i++)
            if (root[i])
                R = i;
        dfs(0, R), dfs(1, R);

        for (int i = N; i >= 1; i--) {
            for (int j : arr[i][0]) {
                st.clear();
                for (int k : adj[j][0]) {
                    if (valid[k])
                        continue;
                    flag = false;
                    for (int l : adj[j][1])
                        if (l != k)
                            flag |= dp[k][l];
                    if (!flag)
                        st.push_back(k);
                }

                for (int k : arr[i][1]) {
                    if (valid[j])
                        dp[j][k] = j == k;
                    else if (j > k)
                        dp[j][k] = false;
                    else {
                        dp[j][k] = true;
                        for (int l : adj[j][0])
                            if (valid[l])
                                dp[j][k] &= parent[l] == k;
                        for (int l : st) {
                            flag = false;
                            for (int m : adj[k][1])
                                flag |= dp[l][m];
                            dp[j][k] &= flag;
                        }
                    }
                }
            }
        }

        merge(R);

        cout << ans.size() << '\n';
        for (pr i : ans)
            cout << i[0] << ' ' << i[1] << '\n';

        ans.clear();
        for (int i = 1; i <= N; i++) {
            adj[i][0].clear(), adj[i][1].clear(), valid[i] = false, depth[i] = 0, parent[i] = 0;
            arr[i][0].clear(), arr[i][1].clear();
            for (int j = 1; j <= N; j++)
                dp[i][j] = false;
        }
    }

    return 0;
}