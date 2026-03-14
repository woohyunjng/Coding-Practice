#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V;
    queue<int> q;
    vector<int> ans, arr;

    cin >> N >> M;
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++) {
        if (chk[i])
            continue;

        arr.clear(), chk[i] = true, q.push(i);
        while (!q.empty()) {
            U = q.front(), q.pop(), arr.push_back(U);
            for (int i : adj[U]) {
                if (chk[i])
                    continue;
                chk[i] = true, q.push(i);
            }
        }

        reverse(arr.begin(), arr.end()), arr.pop_back();
        for (int i : arr)
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << '\n';

    return 0;
}