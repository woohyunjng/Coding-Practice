#include <bits/stdc++.h>
using namespace std;

const int MAX = 3001;

string S[MAX];
vector<int> adj[MAX];

int P[MAX][3], in[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, V = 0;
    queue<int> q;

    vector<string> ans;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i] >> P[i][0] >> P[i][1] >> P[i][2];

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            X = Y = 0;
            for (int k = 0; k < 3; k++)
                X += P[i][k] >= P[j][k], Y += P[i][k] <= P[j][k];

            if (X == Y)
                continue;
            else if (X > Y)
                adj[i].push_back(j), in[j]++;
            else
                adj[j].push_back(i), in[i]++;
        }

    for (int i = 0; i < N; i++) {
        if (in[i] == 0)
            q.push(i), ans.push_back(S[i]);
    }

    while (!q.empty()) {
        X = q.front(), q.pop(), V++;
        for (int i : adj[X]) {
            if (!--in[i])
                q.push(i);
        }
    }

    if (V != N)
        cout << "Paradoxe Absurdo" << '\n';
    else {
        sort(ans.begin(), ans.end());
        for (string i : ans)
            cout << i << '\n';
    }

    return 0;
}