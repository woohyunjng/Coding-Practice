#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int S[MAX], in_degree[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, C, X, Y, Z;
    cin >> N >> M >> C;

    for (int i = 1; i <= N; i++)
        cin >> S[i];

    while (C--) {
        cin >> X >> Y >> Z;
        adj[X].push_back({Y, Z}), in_degree[Y]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (!in_degree[i])
            q.push(i);

    while (!q.empty()) {
        X = q.front(), q.pop();

        for (pr i : adj[X]) {
            Y = i.first, Z = i.second;
            S[Y] = max(S[Y], S[X] + Z);
            if (!--in_degree[Y])
                q.push(Y);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << S[i] << '\n';

    return 0;
}