#include <bits/stdc++.h>
#define int long long

#define MAX 50010
#define MAX_K 55
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> adj[MAX];
vector<int> color[MAX_K];
int dis[MAX], S[MAX_K][MAX_K], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    string s;
    pr X;
    vector<int>::iterator it;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> B[i];
        color[B[i]].push_back(i);
    }

    for (int i = 1; i <= K; i++) {
        cin >> s;
        for (int j = 1; j <= K; j++)
            S[i][j] = s[j - 1] - '0';
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (B[i] == j) {
                if (!S[B[i]][j] && i == 1)
                    continue;
                it = lower_bound(color[j].begin(), color[j].end(), i);
                if (it != color[j].end()) {
                    it++;
                    if (it != color[j].end())
                        adj[i].push_back({*it - i, *it});
                }
            }
            if (!S[B[i]][j])
                continue;
            it = lower_bound(color[j].begin(), color[j].end(), i);
            if (it != color[j].begin())
                adj[i].push_back({i - *prev(it), *prev(it)});
            if (it == color[j].end())
                continue;

            adj[i].push_back({*it - i, *it});
        }
    }

    fill(dis, dis + N + 1, INF);
    priority_queue<pr, vector<pr>, greater<pr>> pq;

    pq.push({0, 1}), dis[1] = 0;
    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        if (dis[X.second] < X.first)
            continue;

        for (pr i : adj[X.second]) {
            if (dis[i.second] > X.first + i.first) {
                dis[i.second] = X.first + i.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }

    cout << (dis[N] == INF ? -1 : dis[N]) << '\n';

    return 0;
}