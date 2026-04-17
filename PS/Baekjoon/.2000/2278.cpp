#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 101;
const int INF = 100001;

int D[MAX][MAX], DS[MAX][MAX], DJ[MAX];
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    bool chk = true;

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    vector<pr> arr;
    vector<tp> ans;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            cin >> D[i][j], arr.push_back({i, j});

    sort(arr.begin(), arr.end(), [&](pr x, pr y) { return D[x[0]][x[1]] < D[y[0]][y[1]]; });

    for (pr i : arr) {
        fill(DJ + 1, DJ + N + 1, INF);
        pq.push({0, i[0]}), DJ[i[0]] = 0;

        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (K[0] > DJ[K[1]])
                continue;

            for (pr j : adj[K[1]]) {
                if (DJ[j[0]] > K[0] + j[1]) {
                    DJ[j[0]] = K[0] + j[1];
                    pq.push({DJ[j[0]], j[0]});
                }
            }
        }

        if (DJ[i[1]] > D[i[0]][i[1]]) {
            ans.push_back({i[0], i[1], D[i[0]][i[1]]});
            adj[i[0]].push_back({i[1], D[i[0]][i[1]]}), adj[i[1]].push_back({i[0], D[i[0]][i[1]]});
        }
    }

    while (ans.size() < M && N >= 2)
        ans.push_back({1, 2, 500});

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            DS[i][j] = (i == j ? 0 : INF);

    for (tp i : ans) {
        DS[i[0]][i[1]] = min(DS[i[0]][i[1]], i[2]);
        DS[i[1]][i[0]] = min(DS[i[1]][i[0]], i[2]);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                DS[i][j] = min(DS[i][j], DS[i][k] + DS[k][j]);

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            chk &= D[i][j] == DS[i][j];
    chk &= ans.size() == M;

    if (chk) {
        cout << 1 << '\n';
        for (tp i : ans)
            cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    } else
        cout << 0 << '\n';

    return 0;
}
