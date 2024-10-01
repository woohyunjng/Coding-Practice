#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int C[MAX], val[MAX];
vector<int> adj[MAX];
priority_queue<int> pq[MAX];

int dfs(int K, int dep) {
    int res = 0;

    C[K] += dep;

    for (int i : adj[K]) {
        res += dfs(i, dep + 1);
        if (!pq[i].empty())
            pq[i].pop();

        if (pq[i].size() > pq[K].size())
            swap(pq[i], pq[K]);
        while (!pq[i].empty())
            pq[K].push(pq[i].top()), pq[i].pop();
    }

    pq[K].push(C[K]);
    pq[K].push(C[K]);

    res += abs(C[K] - pq[K].top());

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B;
    cin >> N >> C[1];

    for (int i = 2; i <= N; i++) {
        cin >> A >> B;
        adj[A].push_back(i);
        C[i] = B;
    }

    cout << dfs(1, 0);

    return 0;
}