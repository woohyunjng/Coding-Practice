#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

map<pr, int> dis;
pr go[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, K, ans = 0;
    bool chk = false;
    pr Z;

    cin >> N >> M >> X >> Y >> K;

    queue<pr> q;
    q.push({X, Y}), dis[{X, Y}] = 0;

    while (!q.empty()) {
        Z = q.front(), q.pop();
        if (dis[Z] % 2 == K % 2)
            ans++;

        if (dis[Z] >= K) {
            chk = true;
            continue;
        }

        for (pr i : go) {
            X = Z[0] + i[0], Y = Z[1] + i[1];
            if (X < 1 || X > N || Y < 1 || Y > M || dis.find({X, Y}) != dis.end())
                continue;
            dis[{X, Y}] = dis[Z] + 1, q.push({X, Y});
        }
    }

    if (!chk)
        ans = 0;

    cout << N * M - ans << '\n';
}