#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int cur[MAX], go[MAX], res[MAX];
bool vst[MAX], child[MAX];
vector<int> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, Y;
    vector<pr> arr;
    queue<int> q, track;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cur[i] = i;

    for (int i = 1; i <= K; i++) {
        cin >> X >> Y;
        adj[cur[X]].push_back(Y), adj[cur[Y]].push_back(X);
        swap(cur[X], cur[Y]);
    }

    for (int i = 1; i <= N; i++)
        go[i] = cur[i];

    for (int i = 1; i <= N; i++) {
        if (vst[i])
            continue;
        q.push(i), vst[i] = true;
        Y = 0;

        while (!q.empty()) {
            X = q.front(), q.pop();
            track.push(X);

            if (!child[X])
                Y++, child[X] = true;

            for (int j : adj[X]) {
                if (child[j])
                    continue;
                Y++, child[j] = true;
            }

            if (!vst[go[X]])
                q.push(go[X]), vst[go[X]] = true;
        }

        while (!track.empty()) {
            X = track.front(), track.pop();
            for (int j : adj[X]) {
                if (!child[j])
                    continue;
                child[j] = false;
            }
            res[X] = Y;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';

    return 0;
}