#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;

vector<int> adj[MAX];
int in[MAX], C[MAX][MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, X, Y, ans_t;
    queue<int> q;
    vector<int> ans;

    cin >> T;
    while (T--) {
        cin >> N, ans_t = 0, ans.clear();
        for (int i = 1; i <= N; i++)
            cin >> X, A[X] = i;

        cin >> M;
        while (M--)
            cin >> X >> Y, C[X][Y] = 1;

        for (int i = 1; i <= N; i++)
            for (int j = i + 1; j <= N; j++) {
                if ((A[i] < A[j]) ^ C[i][j])
                    adj[i].push_back(j), in[j]++;
                else
                    adj[j].push_back(i), in[i]++;
            }

        for (int i = 1; i <= N; i++)
            if (!in[i])
                q.push(i);

        while (!q.empty()) {
            if (q.size() > 1)
                ans_t = 1;
            X = q.front(), q.pop(), ans.push_back(X);
            for (int i : adj[X])
                if (!--in[i])
                    q.push(i);
        }

        for (int i = 1; i <= N; i++)
            if (in[i])
                ans_t = 2;

        if (ans_t == 2)
            cout << "IMPOSSIBLE" << '\n';
        else if (ans_t == 1)
            cout << "?" << '\n';
        else {
            for (int i : ans)
                cout << i << ' ';
            cout << '\n';
        }

        for (int i = 1; i <= N; i++) {
            in[i] = 0, adj[i].clear();
            for (int j = 1; j <= N; j++)
                C[i][j] = 0;
        }
    }

    return 0;
}