#include <bits/stdc++.h>
#define int long long

#define MAX 1010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int dis_r[MAX][MAX], dis_s[MAX][MAX], board[MAX][MAX];
bool vst[MAX][MAX];
vector<pr> arr[MAX], nxt;
pr go[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, D, res = 0, X, Y;
    pr K;
    string S;
    queue<pr> q;

    cin >> N >> D;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++) {
            if (S[j - 1] == '#') {
                board[i][j] = -1;
                vst[i][j] = true, q.push({i, j});
            } else if (S[j - 1] == 'S')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }

    while (!q.empty()) {
        K = q.front(), q.pop();

        for (pr i : go) {
            X = K.first + i.first, Y = K.second + i.second;
            if (X < 1 || X > N || Y < 1 || Y > N || vst[X][Y])
                continue;
            vst[X][Y] = true, q.push({X, Y});
            dis_r[X][Y] = dis_r[K.first][K.second] + 1;
        }
    }

    fill(&vst[0][0], &vst[N + 1][0], false);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 1)
                q.push({i, j}), vst[i][j] = true;
        }
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        arr[dis_r[K.first][K.second] - 1].push_back({K.first, K.second});
        res++;

        if (dis_s[K.first][K.second] >= D * dis_r[K.first][K.second])
            continue;

        for (pr i : go) {
            X = K.first + i.first, Y = K.second + i.second;
            if (X < 1 || X > N || Y < 1 || Y > N || vst[X][Y] || board[X][Y] != 0)
                continue;
            if (dis_s[K.first][K.second] > D * dis_r[X][Y])
                continue;
            vst[X][Y] = true, q.push({X, Y});
            dis_s[X][Y] = dis_s[K.first][K.second] + 1;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        nxt = arr[i + 1];

        for (pr j : nxt) {
            for (pr k : go) {
                X = j.first + k.first, Y = j.second + k.second;
                if (X < 1 || X > N || Y < 1 || Y > N || board[X][Y] != 0)
                    continue;
                if (vst[X][Y])
                    continue;
                vst[X][Y] = true, res++;
                arr[i].push_back({X, Y});
            }
        }
    }

    cout << res << '\n';

    return 0;
}