#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int D[MAX][2];
bool vst[MAX];

vector<int> adj[MAX], val[MAX];
set<int> st[MAX], chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, A, B, X, Y;
    vector<int> tmp;

    cin >> N >> M >> K >> A >> B;
    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
        val[X].push_back(Y), val[Y].push_back(X);
        chk[X].insert(Y), chk[Y].insert(X);
    }

    for (int i = 1; i <= N; i++)
        D[i][0] = D[i][1] = INF;

    queue<int> q;
    vst[K] = true, D[K][0] = 0, q.push(K);

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : adj[X]) {
            if (vst[i])
                continue;
            vst[i] = true, D[i][0] = D[X][0] + 1, q.push(i);
        }
    }

    fill(vst + 1, vst + N + 1, false);
    vst[K] = true, D[K][1] = 0, q.push(K);

    while (!q.empty()) {
        X = q.front(), q.pop();
        for (int i : adj[X]) {
            tmp.clear();
            for (int j : val[i]) {
                if (vst[j] || chk[X].find(j) != chk[X].end()) {
                    tmp.push_back(j);
                    continue;
                }
                vst[j] = true, D[j][1] = D[X][1] + 1, q.push(j);
            }
            val[i].clear();
            for (int j : tmp)
                val[i].push_back(j);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << min(D[i][0] / 2 * min(A << 1, B) + (D[i][0] & 1) * A, D[i][1] == INF ? INF : (D[i][1] * min(A << 1, B))) << '\n';

    return 0;
}