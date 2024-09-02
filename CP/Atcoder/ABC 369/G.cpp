#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
priority_queue<int> pq;

int dfs(int K, int pr) {
    priority_queue<int> pq_dfs;
    int res = 0;

    for (auto i : arr[K]) {
        if (i.first == pr)
            continue;
        pq_dfs.push(i.second + dfs(i.first, K));
    }

    if (!pq_dfs.empty()) {
        res = pq_dfs.top();
        pq_dfs.pop();
    }

    while (!pq_dfs.empty()) {
        pq.push(pq_dfs.top());
        pq_dfs.pop();
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C, res = 0;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> A >> B >> C;
        arr[A].push_back({B, C});
        arr[B].push_back({A, C});
    }

    pq.push(dfs(1, 0));

    for (int i = 1; i <= N; i++) {
        if (!pq.empty())
            res += pq.top(), pq.pop();
        cout << res * 2 << '\n';
    }

    return 0;
}