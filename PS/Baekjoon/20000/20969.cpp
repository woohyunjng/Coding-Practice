#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int cur[MAX], go[MAX], res[MAX], cnt[MAX];
bool vst[MAX];
vector<pr> adj[MAX];

int visit(int X, int R) {
    int delta = 0;

    for (pr i : adj[X]) {
        if (i.second > R)
            continue;
        if (++cnt[i.first] == 1)
            delta++;
    }

    return delta;
}

int unvisit(int X, int R) {
    int delta = 0;

    for (pr i : adj[X]) {
        if (i.second > R)
            continue;
        if (cnt[i.first] == 0)
            continue;
        if (--cnt[i.first] == 0)
            delta--;
    }

    return delta;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, M, X, Y, D, R;
    vector<int> arr;
    queue<int> q, track;

    cin >> N >> K >> M;

    for (int i = 1; i <= N; i++)
        cur[i] = i, adj[i].push_back({i, 0});

    for (int i = 1; i <= K; i++) {
        cin >> X >> Y;
        adj[cur[X]].push_back({Y, i}), adj[cur[Y]].push_back({X, i});
        swap(cur[X], cur[Y]);
    }

    for (int i = 1; i <= N; i++)
        go[cur[i]] = i;

    for (int i = 1; i <= N; i++) {
        if (vst[i])
            continue;
        q.push(i), vst[i] = true;
        Y = 0;

        while (!q.empty()) {
            X = q.front(), q.pop();
            arr.push_back(X);
            if (!vst[go[X]])
                q.push(go[X]), vst[go[X]] = true;
        }

        D = M / K, R = M % K;
        if (D >= arr.size())
            D = arr.size(), R = 0;

        for (int j = 0; j <= D - 1; j++)
            Y += visit(arr[j], K);

        for (int j = 0; j < arr.size(); j++) {
            Y += visit(arr[(j + D) % arr.size()], R);

            res[arr[j]] = Y;
            Y += unvisit(arr[(j + D) % arr.size()], R);
            if (D) {
                Y += unvisit(arr[j], K);
                Y += visit(arr[(j + D) % arr.size()], K);
            }
        }

        for (int j : arr)
            unvisit(j, K);
        arr.clear();
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';

    return 0;
}