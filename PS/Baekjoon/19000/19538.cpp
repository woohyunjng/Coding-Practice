#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int res[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, M;
    cin >> N;

    for (int i = 1; i <= N; i++)
        while (cin >> X, X)
            adj[i].push_back(X);

    cin >> M;
    fill(res + 1, res + N + 1, -1);

    queue<int> q;

    for (int i = 1; i <= M; i++) {
        cin >> X;
        res[X] = 0;
        q.push(X);
    }

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : adj[X]) {
            cnt[i]++;
            if (res[i] == -1 && cnt[i] * 2 >= adj[i].size()) {
                res[i] = res[X] + 1;
                q.push(i);
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';

    return 0;
}