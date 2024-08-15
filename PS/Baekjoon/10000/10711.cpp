#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX], visited[MAX][MAX];
pr go[8] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, res = 0, cnt;
    bool changed;

    string S;
    pr K;

    queue<pr> q;

    cin >> H >> W;

    for (int i = 1; i <= H; i++) {
        cin >> S;
        for (int j = 1; j <= W; j++) {
            if (S[j - 1] == '.') {
                arr[i][j] = 0;
                visited[i][j] = 0;
                q.push({i, j});
            } else
                arr[i][j] = S[j - 1] - '0';
        }
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        for (int i = 0; i < 8; i++) {
            if (arr[K.first + go[i].first][K.second + go[i].second]) {
                arr[K.first + go[i].first][K.second + go[i].second]--;
                visited[K.first + go[i].first][K.second + go[i].second] = max(visited[K.first + go[i].first][K.second + go[i].second], visited[K.first][K.second]);
                if (arr[K.first + go[i].first][K.second + go[i].second] == 0) {
                    q.push({K.first + go[i].first, K.second + go[i].second});
                    visited[K.first + go[i].first][K.second + go[i].second]++;
                }
            }
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++)
            res = max(res, visited[i][j]);
    }

    cout << res;

    return 0;
}