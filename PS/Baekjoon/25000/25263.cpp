#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int S[MAX], V[MAX], ans[MAX], parent[MAX];
bool vst[MAX];
vector<int> adj[MAX], child[MAX];

int find(int X) { return parent[X] == X ? X : parent[X] = find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    parent[Y] = X, V[X] += V[Y];
}

void dfs(int node) {
    ans[node] = 1;
    for (int i : child[node])
        dfs(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, Z;
    vector<int> arr;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S[i], arr.push_back(i);
        parent[i] = i, V[i] = S[i];
    }

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return S[x] < S[y]; });
    for (int i : arr) {
        for (int j : adj[i]) {
            if (!vst[j] || find(i) == find(j))
                continue;
            if (V[find(j)] >= S[i])
                child[i].push_back(find(j));
            uni(i, j);
        }
        vst[i] = true;
    }

    dfs(arr.back());

    for (int i = 1; i <= N; i++)
        cout << ans[i];
    cout << '\n';

    return 0;
}