#include <bits/stdc++.h>
#define int long long

#define MAX_K 20
#define MAX 50100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int ans[MAX], visited[MAX];
map<int, bool> rt[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, R, K, A, B, D;
    tp X;

    vector<int> ans;
    priority_queue<tp, vector<tp>, greater<tp>> pq;

    cin >> N >> M >> C >> R >> K;

    while (M--) {
        cin >> A >> B >> D;
        adj[A].push_back({B, D});
        adj[B].push_back({A, D});
    }

    for (int i = 1; i <= C; i++)
        pq.push({0, i, i});

    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        D = X[0], A = X[1], B = X[2];

        if (rt[A].count(B) || visited[A] == K)
            continue;
        rt[A][B] = true;
        visited[A]++;

        for (pr i : adj[X[1]]) {
            if (D + i.second > R || visited[i.first] >= K)
                continue;

            pq.push({D + i.second, i.first, B});
        }
    }

    for (int i = C + 1; i <= N; i++) {
        if (visited[i] == K)
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << '\n';

    return 0;
}