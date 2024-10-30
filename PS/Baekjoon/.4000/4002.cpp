#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, M, parent[MAX], cost[MAX], leader[MAX], res = 0;
vector<int> child[MAX];
priority_queue<int> pq[MAX];

int dfs(int K) {
    int val = 0;

    pq[K].push(cost[K]);
    val += cost[K];

    for (int i : child[K]) {
        val += dfs(i);
        if (pq[K].size() < pq[i].size())
            swap(pq[K], pq[i]);

        while (!pq[i].empty())
            pq[K].push(pq[i].top()), pq[i].pop();

        while (val > M && !pq[K].empty())
            val -= pq[K].top(), pq[K].pop();
    }

    res = max(res, leader[K] * (int)pq[K].size());
    return val;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int root;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> parent[i] >> cost[i] >> leader[i];
        child[parent[i]].push_back(i);
        if (parent[i] == 0)
            root = i;
    }

    dfs(root);

    cout << res;

    return 0;
}