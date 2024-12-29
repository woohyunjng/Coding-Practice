#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX], ans[200100];
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool vst[MAX][MAX], reachable[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, res = 0, X, Y, A, B;
    pr K;
    queue<pr> q;
    vector<tp> queries;
    char C;
    cin >> N >> Q;

    fill(&arr[0][0], &arr[N + 1][N + 1], -1);

    for (int i = 0; i < Q; i++) {
        cin >> X >> Y >> C;
        queries.push_back({X, Y, C});
        if (C == 'R')
            arr[X][Y] = 1;
        else if (C == 'L')
            arr[X][Y] = 3;
        else if (C == 'U')
            arr[X][Y] = 2;
        else
            arr[X][Y] = 0;
    }

    for (int i = 0; i <= N + 1; i++)
        q.push({0, i}), q.push({N + 1, i}), vst[0][i] = vst[N + 1][i] = true;
    for (int i = 1; i <= N; i++)
        q.push({i, 0}), q.push({i, N + 1}), vst[i][0] = vst[i][N + 1] = true;

    res = 0;
    while (!q.empty()) {
        K = q.front(), q.pop();

        for (pr i : go) {
            X = K.first + i.first, Y = K.second + i.second;
            if (X < 0 || Y < 0 || X > N + 1 || Y > N + 1 || vst[X][Y])
                continue;
            reachable[X][Y] = true;
            if (arr[X][Y] == -1 || (i.first + go[arr[X][Y]].first == 0 && i.second + go[arr[X][Y]].second == 0)) {
                vst[X][Y] = true;
                q.push({X, Y}), res++;
            }
        }
    }

    reverse(queries.begin(), queries.end());
    for (int i = 0; i < Q; i++) {
        ans[Q - 1 - i] = res;
        X = queries[i][0], Y = queries[i][1], C = queries[i][2];
        arr[X][Y] = -1;

        if (!reachable[X][Y] || vst[X][Y])
            continue;

        q.push({X, Y}), vst[X][Y] = true, res++;

        while (!q.empty()) {
            K = q.front(), q.pop();
            for (pr i : go) {
                A = K.first + i.first, B = K.second + i.second;
                if (A < 0 || B < 0 || A > N + 1 || B > N + 1 || vst[A][B])
                    continue;
                reachable[A][B] = true;
                if (arr[A][B] == -1 || (i.first + go[arr[A][B]].first == 0 && i.second + go[arr[A][B]].second == 0)) {
                    vst[A][B] = true;
                    q.push({A, B}), res++;
                }
            }
        }
    }

    for (int i = 0; i < Q; i++)
        cout << N * N - ans[i] << '\n';

    return 0;
}