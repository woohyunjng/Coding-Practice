#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 100001;
const int BUCKET = 450;

vector<int> adj[MAX];
bitset<BUCKET> B[BUCKET];
int D[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, ans = 0;
    vector<int> val;
    vector<pr> arr;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        val.push_back(i);

    while (M--) {
        cin >> U >> V;
        arr.push_back({U, V}), D[U]++, D[V]++;
    }

    sort(val.begin(), val.end(), [](int a, int b) { return D[a] < D[b]; });
    for (int i = 1; i <= N; i++)
        D[val[i - 1]] = i;

    for (pr i : arr) {
        if (D[i[0]] < D[i[1]])
            adj[i[0]].push_back(i[1]);
        else
            adj[i[1]].push_back(i[0]);
    }

    for (int i = 1; i <= N; i++) {
        V = 0;
        for (int j : adj[i])
            C[j] = ++V, B[V].reset();
        for (int j : adj[i])
            for (int k : adj[j])
                if (C[k])
                    B[C[j]][C[k]] = 1;
        for (int j : adj[i])
            for (int k : adj[j])
                if (C[k])
                    ans += (B[C[j]] & B[C[k]]).count();
        for (int j : adj[i])
            C[j] = 0;
    }

    cout << ans << '\n';

    return 0;
}