#include <bits/stdc++.h>
#define int long long

#define MAX 310
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int N, M, arr[MAX][MAX];
bool checked[MAX][MAX];
pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int res = 0, X, A, B;
    tp K;
    pr P;

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    queue<pr> q;

    cin >> M >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            pq.push({arr[i][j], i, j});
        }
    }

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (arr[K[1]][K[2]] != K[0])
            continue;

        fill(&checked[0][0], &checked[N][M] + 1, false);

        q.push({K[1], K[2]});
        checked[K[1]][K[2]] = true;

        X = INF;

        while (!q.empty()) {
            P = q.front(), q.pop();
            if (P.first == 1 || P.first == N || P.second == 1 || P.second == M) {
                X = 0;
                break;
            }

            for (pr i : go) {
                A = P.first + i.first, B = P.second + i.second;
                if (A < 1 || A > N || B < 1 || B > M || checked[A][B])
                    continue;

                if (arr[A][B] == K[0]) {
                    q.push({A, B});
                    checked[A][B] = true;
                } else
                    X = min(X, arr[A][B]);
            }
        }

        while (!q.empty())
            q.pop();

        if (X <= K[0])
            continue;

        q.push({K[1], K[2]});
        checked[K[1]][K[2]] = false;

        while (!q.empty()) {
            P = q.front(), q.pop();
            res += X - K[0];
            arr[P.first][P.second] = X;

            for (pr i : go) {
                A = P.first + i.first, B = P.second + i.second;
                if (A < 1 || A > N || B < 1 || B > M || !checked[A][B])
                    continue;

                q.push({A, B});
                checked[A][B] = false;
            }
        }
    }

    cout << res;

    return 0;
}