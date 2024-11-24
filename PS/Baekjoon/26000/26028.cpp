#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> adj[MAX];
int dis[MAX], cnt[MAX];
bool vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, K = INF, res = 0;
    pr A;
    queue<pr> q;
    cin >> N >> M;

    while (M--) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    for (int i = 1; i <= N; i++) {
        fill(vst, vst + N + 1, false), fill(dis, dis + N + 1, 0);
        q.push({i, 0}), vst[i] = true;

        while (!q.empty()) {
            A = q.front(), q.pop();

            for (int j : adj[A.first]) {
                if (vst[j]) {
                    if (j != A.second)
                        K = min(K, dis[j] + dis[A.first] + 1);
                    continue;
                }
                q.push({j, A.first}), vst[j] = true, dis[j] = dis[A.first] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        fill(vst, vst + N + 1, false), fill(dis, dis + N + 1, 0), fill(cnt, cnt + N + 1, 0);
        q.push({i, 0}), vst[i] = true, cnt[i] = 1;

        while (!q.empty()) {
            A = q.front(), q.pop();

            for (int j : adj[A.first]) {
                if (vst[j]) {
                    if (dis[j] + 1 == dis[A.first])
                        cnt[A.first] += cnt[j];
                    continue;
                }
                q.push({j, A.first}), vst[j] = true, dis[j] = dis[A.first] + 1;
            }
        }

        for (int j = 1; j <= N; j++) {
            if (K & 1) {
                if (dis[j] * 2 + 1 != K)
                    continue;
                for (int k : adj[j]) {
                    if (dis[k] == K / 2)
                        res += cnt[j] * cnt[k];
                }
            } else {
                if (dis[j] == K / 2)
                    res += cnt[j] * (cnt[j] - 1);
            }
        }
    }

    cout << res / K / 2 << '\n';

    return 0;
}