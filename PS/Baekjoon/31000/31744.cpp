#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int T, A[MAX], parent[MAX], depth[MAX];
vector<pr> adj[MAX];
priority_queue<pr, vector<pr>, greater<pr>> pq[MAX];

int find(int K) { return parent[K] == K ? K : parent[K] = find(parent[K]); }

void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X > Y)
        swap(X, Y);
    if (X != Y)
        parent[Y] = X;
}

void dfs(int K, int P) {
    pr X, Y;
    priority_queue<pr, vector<pr>, greater<pr>> temp;

    for (pr i : adj[K]) {
        if (i.first == P)
            continue;
        depth[i.first] = depth[K] + i.second;
        dfs(i.first, K);

        if (pq[i.first].size() > pq[K].size())
            swap(pq[i.first], pq[K]);
        while (!pq[i.first].empty())
            pq[K].push(pq[i.first].top()), pq[i.first].pop();
    }

    if (!pq[K].empty()) {
        X = pq[K].top(), pq[K].pop();
        while (!pq[K].empty()) {
            Y = pq[K].top(), pq[K].pop();
            if (X.first + Y.first - depth[K] * 2 <= T)
                uni(X.second, Y.second);
            else {
                pq[K].push(Y);
                break;
            }
        }
        pq[K].push(X);
    }

    if (A[K]) {
        while (!pq[K].empty()) {
            X = pq[K].top(), pq[K].pop();
            if (X.first - depth[K] <= T)
                uni(K, X.second);
        }
        pq[K].push({depth[K], K});
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z;
    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        parent[i] = i;
    }

    for (int i = 1; i < N; i++) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z});
        adj[Y].push_back({X, Z});
    }

    dfs(1, 0);

    cin >> Q;
    while (Q--) {
        cin >> X >> Y;
        cout << (find(X) == find(Y)) << '\n';
    }

    return 0;
}