#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2001;

int E[MAX][MAX], S[MAX], D[MAX], assign[MAX];
bool chk[MAX], vst[MAX];
vector<int> adj[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (chk[i])
            continue;
        chk[i] = true;
        if (assign[i] == -1 || dfs(assign[i])) {
            assign[i] = node, assign[node] = i;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, ans, X;
    bool flag;

    vector<int> arr;
    queue<int> q;

    cin >> T;
    while (T--) {
        cin >> N, ans = 0, fill(assign, assign + (N << 1) + 1, -1);
        for (int i = 1; i <= N; i++)
            cin >> S[i];
        for (int i = 1; i <= N; i++)
            cin >> D[i];

        for (int i = 1; i <= N; i++)
            for (int j = i; j <= N; j++)
                cin >> E[i][j];

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (S[i] + D[i] + E[min(i, j)][max(i, j)] <= S[j])
                    adj[i].push_back(N + j), adj[N + j].push_back(i);

        for (int i = 1; i <= N; i++) {
            fill(chk, chk + (N << 1) + 1, false);
            if (dfs(i))
                ans++;
        }

        fill(chk, chk + (N << 1) + 1, false);
        for (int i = 1; i <= N; i++)
            if (assign[i] == -1)
                q.push(i), chk[i] = true;

        while (!q.empty()) {
            X = q.front(), q.pop();
            for (int i : adj[X]) {
                if (chk[i] || (X <= N && assign[X] == i) || (X > N && assign[X] != i))
                    continue;
                q.push(i), chk[i] = true;
            }
        }

        fill(vst, vst + N + 1, false);
        for (int i = 1; i <= N; i++)
            vst[i] |= !chk[i];
        for (int i = N + 1; i <= (N << 1); i++)
            vst[i - N] |= chk[i];

        for (int i = 1; i <= N; i++)
            if (!vst[i])
                arr.push_back(i);

        cout << arr.size() << '\n';
        for (int i : arr)
            cout << i << ' ';
        cout << '\n';

        arr.clear();
        for (int i = 1; i <= (N << 1); i++)
            adj[i].clear();
    }

    return 0;
}