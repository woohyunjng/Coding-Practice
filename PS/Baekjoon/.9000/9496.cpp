#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 51;

bool chk[MAX];
int G[MAX], assign[MAX], T, GO[4];
vector<int> adj[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (G[i] != T || chk[i])
            continue;
        chk[i] = true;
        if (assign[i] == -1 || dfs(assign[i])) {
            assign[i] = node;
            return true;
        }
    }
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, val, X;
    string S;

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        G[i] = S[i] - '0';

    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++) {
            if (S[j] == 'Y')
                adj[i].push_back(j);
        }
    }

    GO[1] = 2, GO[2] = 3, GO[3] = 1;

    for (int i = 1; i <= 3; i++) {
        fill(assign, assign + N, -1);
        T = i, val = 0;
        for (int j = 0; j < N; j++) {
            if (G[j] != GO[i])
                continue;
            fill(chk, chk + N, false);
            chk[j] = true, val += dfs(j);
        }
        ans = max(ans, N - val);
    }

    cout << ans << '\n';

    return 0;
}