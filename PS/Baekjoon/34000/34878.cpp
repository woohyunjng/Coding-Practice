#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;

int in[MAX], R[MAX];
bool chk[MAX];
vector<int> adj[MAX], rev[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, U, V, C, D;
    queue<int> q;

    cin >> T;
    while (T--) {
        cin >> N >> M, C = D = 0;
        while (M--) {
            cin >> U >> V, in[V]++;
            adj[U].push_back(V), rev[V].push_back(U);
        }

        for (int i = 1; i <= N; i++)
            if (!in[i])
                q.push(i);

        while (!q.empty()) {
            U = q.front(), q.pop();
            D++, chk[U] = true;

            for (int i : rev[U])
                if (chk[i])
                    C -= R[i], D--, chk[i] = false;

            for (int i : adj[U])
                if (!--in[i]) {
                    q.push(i);
                    for (int j : rev[i])
                        if (chk[j])
                            R[j]++, C++;
                }

            cout << (D * q.size() == C);
        }
        cout << '\n';

        for (int i = 1; i <= N; i++) {
            adj[i].clear(), rev[i].clear();
            in[i] = R[i] = 0, chk[i] = false;
        }
    }

    return 0;
}