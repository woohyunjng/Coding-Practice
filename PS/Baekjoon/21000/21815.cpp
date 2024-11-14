#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int C[MAX], P[MAX][4], X = 1, parent[MAX];
bool vst[MAX];
vector<int> adj[MAX];

void dfs(int K) {
    vst[K] = true, parent[K] = X;
    for (int i : adj[K]) {
        if (vst[i])
            continue;
        dfs(i);
    }
}

int find(int K) { return parent[K] == K ? K : parent[K] = find(parent[K]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, res = 0;
    vector<tp> edges;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        for (int j = 0; j < 4; j++)
            cin >> P[i][j];
        adj[P[i][0]].push_back(P[i][1]), adj[P[i][1]].push_back(P[i][0]);
        adj[P[i][2]].push_back(P[i][3]), adj[P[i][3]].push_back(P[i][2]);
    }

    for (int i = 1; i <= N * 2; i++) {
        if (vst[i])
            continue;
        dfs(i);
        X++;
    }

    for (int i = 1; i <= N; i++) {
        if (parent[P[i][0]] == parent[P[i][2]])
            continue;
        edges.push_back({C[i], parent[P[i][0]], parent[P[i][2]]});
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= X; i++)
        parent[i] = i;

    for (tp i : edges) {
        A = find(i[1]), B = find(i[2]);
        if (A == B)
            continue;
        if (A > B)
            swap(A, B);
        parent[B] = A, res += i[0];
    }

    cout << res << '\n';

    return 0;
}