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
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, res = -1;
    pr K;

    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        adj[A].push_back(B);
    }

    queue<pr> q;
    q.push({1, 0});

    while (!q.empty()) {
        K = q.front(), q.pop();
        if (K.first == 1 && K.second != 0) {
            res = K.second;
            break;
        }

        for (int i : adj[K.first]) {
            if (checked[i])
                continue;
            checked[i] = true;
            q.push({i, K.second + 1});
        }
    }

    cout << res;

    return 0;
}