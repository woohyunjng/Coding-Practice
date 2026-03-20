#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;

vector<int> adj[MAX];
int D[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, N, M, U, V, ans = 0, X;
    queue<int> q;
    vector<int> arr;

    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> N >> M, X = N + 1;
        while (M--) {
            cin >> U >> V;
            adj[U].push_back(V), adj[V].push_back(U);
        }

        for (int j = 1; j <= N; j++) {
            fill(D + 1, D + N + 1, N + 1);
            D[j] = 0, q.push(j);

            while (!q.empty()) {
                U = q.front(), q.pop();
                for (int k : adj[U]) {
                    if (D[k] != (N + 1))
                        continue;
                    D[k] = D[U] + 1, q.push(k);
                }
            }
            X = min(X, *max_element(D + 1, D + N + 1));
        }
        arr.push_back(X);
        for (int j = 1; j <= N; j++)
            adj[j].clear();
    }

    sort(arr.rbegin(), arr.rend()), ans = arr[0], arr.erase(arr.begin()), U = 0;
    for (int i = 0; i < arr.size(); i += 2) {
        U++;
        if (i < arr.size())
            ans = max(ans, U + arr[i]);
        if (i + 1 < arr.size())
            ans = max(ans, U + arr[i + 1]);
    }

    cout << ans << '\n';

    return 0;
}