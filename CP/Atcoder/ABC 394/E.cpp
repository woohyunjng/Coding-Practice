#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200;
const int INF = 0x3f3f3f3f3f3f3f3f;

int dp[MAX][MAX];
bool vst[MAX][MAX];

vector<pr> adj[MAX], rev[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    string S;

    priority_queue<tp, vector<tp>, greater<tp>> pq;
    tp K;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= N; j++) {
            if (S[j - 1] == '-')
                dp[i][j] = -1;
            else {
                dp[i][j] = 1;
                adj[i].push_back({j, S[j - 1] - 'a' + 1});
                rev[j].push_back({i, S[j - 1] - 'a' + 1});

                if (i != j)
                    pq.push({dp[i][j], i, j});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        dp[i][i] = 0, pq.push({0, i, i});

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        for (pr i : rev[K[1]])
            for (pr j : adj[K[2]]) {
                if (i[1] != j[1])
                    continue;
                if (dp[i[0]][j[0]] == -1 || dp[i[0]][j[0]] > dp[K[1]][K[2]] + 2) {
                    dp[i[0]][j[0]] = dp[K[1]][K[2]] + 2;
                    pq.push({dp[i[0]][j[0]], i[0], j[0]});
                }
            }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}