#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> adj[MAX];
int in[MAX], cnt = 0;
bool chk[MAX];

void dfs(int node, int par) {
    int X = ++cnt;

    if (par != 0)
        cout << X << ' ' << par << '\n';
    chk[node] = false;

    for (int i : adj[node]) {
        if (!chk[i])
            continue;
        dfs(i, X);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, S;
    vector<int> arr, nxt;

    cin >> N, S = N;
    for (int i = 1; i < N; i++) {
        cin >> U >> V, in[U]++, in[V]++;
        adj[U].push_back(V), adj[V].push_back(U);
    }

    for (int i = 1; i <= N; i++)
        if (in[i] == 1)
            arr.push_back(i);

    while (true) {
        if (arr.size() == 2 && (S == 2 || (S & 1))) {
            cout << S << '\n'
                 << N / S << '\n';
            dfs(arr[0], 0);
            return 0;
        }

        for (int i : arr) {
            chk[i] = true, S--;
            for (int j : adj[i]) {
                if (chk[j])
                    continue;
                if (--in[j] == 1)
                    nxt.push_back(j);
            }
        }
        arr = nxt, nxt.clear();
    }

    return 0;
}