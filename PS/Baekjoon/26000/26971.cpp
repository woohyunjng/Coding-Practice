#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int vst[MAX], deg[MAX], cnt = 0;
bool del[MAX];

vector<int> adj[MAX];

int dfs(int K) {
    vector<int> arr;
    queue<int> q;

    int X, A = INF, res;

    q.push(K), vst[K] = ++cnt;
    while (!q.empty()) {
        X = q.front(), q.pop();
        arr.push_back(X);

        for (int i : adj[X]) {
            if (vst[i] == cnt || del[i])
                continue;
            vst[i] = cnt, q.push(i);
        }
    }

    for (int i : arr)
        A = min(A, deg[i]);
    res = arr.size() * A;
    cout << K << ' ' << arr.size() << ' ' << A << '\n';

    for (int i : arr) {
        if (deg[i] <= A) {
            del[i] = true;
            q.push(i);
        }
    }

    while (!q.empty()) {
        X = q.front(), q.pop();
        cout << X << "ang\n";
        for (int i : adj[X]) {
            if (del[i] || vst[i] != cnt)
                continue;
            if (--deg[i] <= A)
                q.push(i), del[i] = true;
        }
    }

    for (int i : arr) {
        if (del[i])
            continue;
        res = max(res, dfs(i));
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, res = 0;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        adj[A].push_back(B), adj[B].push_back(A);
        deg[A]++, deg[B]++;
    }

    for (int i = 1; i <= N; i++) {
        if (!del[i])
            res = max(res, dfs(i));
    }

    cout << res << '\n';

    return 0;
}