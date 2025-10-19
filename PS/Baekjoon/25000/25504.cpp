#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 50001;
const int BUCKET = 260;
const int INF = 2e9;

vector<pr> adj[MAX];
vector<int> val[MAX];
int D[MAX], F[MAX], ID[MAX],
    S[MAX], T[MAX], ans[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, U, V, W;
    vector<int> arr;

    cin >> N >> M >> Q;
    while (M--) {
        cin >> U >> V >> W;
        if (U > V)
            swap(U, V);
        adj[U].push_back({V, W}), adj[V].push_back({U, W});
    }

    for (int i = 1; i <= N; i++)
        arr.push_back(i), D[i] = INF;
    sort(arr.begin(), arr.end(), [](int x, int y) { return adj[x].size() < adj[y].size(); });
    for (int i = 0; i < N; i++)
        ID[arr[i]] = i + 1;

    for (int i = 1; i <= Q; i++) {
        cin >> S[i] >> T[i], ans[i] = INF;
        val[S[i]].push_back(i), val[T[i]].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
        if (adj[i].size() > BUCKET) {
            D[i] = 0;
            for (int j = 0; j < 3; j++) {
                for (int k = 1; k <= N; k++)
                    F[k] = D[k];
                for (int k = 1; k <= N; k++)
                    for (pr l : adj[k])
                        D[l[0]] = min(D[l[0]], F[k] + l[1]);
            }
            for (int j : val[i])
                ans[j] = min(ans[j], D[S[j] ^ T[j] ^ i]);
            fill(D, D + N + 1, INF);
        }

        D[i] = 0;
        for (pr j : adj[i]) {
            if (ID[j[0]] > ID[i])
                continue;
            D[j[0]] = min(D[j[0]], j[1]);
            for (pr k : adj[j[0]])
                D[k[0]] = min(D[k[0]], j[1] + k[1]);
        }
        for (pr j : adj[i])
            if (adj[j[0]].size() <= BUCKET)
                for (int k : val[j[0]])
                    ans[k] = min(ans[k], D[S[k] ^ T[k] ^ j[0]] + j[1]);
        for (int j : val[i])
            ans[j] = min(ans[j], D[S[j] ^ T[j] ^ i]);
        D[i] = INF;
        for (pr j : adj[i]) {
            if (ID[j[0]] > ID[i])
                continue;
            D[j[0]] = INF;
            for (pr k : adj[j[0]])
                D[k[0]] = INF;
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << (ans[i] == INF ? -1 : ans[i]) << '\n';

    return 0;
}