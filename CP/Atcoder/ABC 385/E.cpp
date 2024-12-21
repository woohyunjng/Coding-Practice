#include <bits/stdc++.h>
#define int long long

#define MAX 300100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, res = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++) {
        X = adj[i].size();
        for (int j : adj[i])
            pq.push(adj[j].size() - 1);
        while (!pq.empty()) {
            res = max(res, 1 + X + pq.top() * X);
            pq.pop(), X--;
        }
    }

    cout << N - res << '\n';

    return 0;
}