#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

int dis[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, S;
    queue<int> q;

    fill(dis, dis + MAX, -1);

    cin >> N >> M >> S, q.push(N), dis[N] = 0;

    while (S--)
        cin >> X, chk[X] = true;

    while (!q.empty()) {
        X = q.front(), q.pop();

        for (int i = 0; i < 8; i++) {
            S = (i & 1) ? 1 : -1;
            for (int j = 0; j < i / 2; j++)
                S *= 10;
            S = (S + X + 10000) % 10000;

            if (chk[S] || dis[S] != -1)
                continue;
            dis[S] = dis[X] + 1, q.push(S);
        }
    }

    cout << dis[M] << '\n';
}