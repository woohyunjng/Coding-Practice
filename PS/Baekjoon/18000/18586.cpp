#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 300001;

vector<pr> arr[MAX];
vector<int> adj[MAX];
int A[MAX], D[MAX], ans;

set<pr> dfs(int node) {
    set<pr> st, tmp;
    set<pr>::iterator it;

    pr K;
    int V;

    st.insert({D[node], A[node]});

    for (int i : adj[node]) {
        D[i] = D[node] + 1, tmp = dfs(i);
        if (st.size() < tmp.size())
            swap(st, tmp);
        while (!tmp.empty()) {
            K = *tmp.begin(), tmp.erase(tmp.begin());
            it = st.lower_bound({K[0], -1});
            if (it == st.end() || (*it)[0] > K[0])
                st.insert(K);
            else
                K[1] += (*it)[1], st.erase(it), st.insert(K);
        }
    }

    sort(arr[node].begin(), arr[node].end(), [&](pr x, pr y) { return x[0] > y[0]; });
    for (pr i : arr[node]) {
        V = i[1];
        while (V > 0) {
            it = st.lower_bound({D[node] + i[0] + 1, -1});
            if (it == st.begin())
                break;
            it = prev(it), K = *it, st.erase(it);
            ans -= min(K[1], V);
            if (K[1] > V)
                K[1] -= V, st.insert(K), V = 0;
            else
                V -= K[1];
        }
    }

    return st;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, P, K, C;

    cin >> T;
    while (T--) {
        cin >> N >> M, ans = 0;
        for (int i = 2; i <= N; i++)
            cin >> P, adj[P].push_back(i);
        for (int i = 1; i <= N; i++)
            cin >> A[i], ans += A[i];

        while (M--) {
            cin >> P >> K >> C;
            arr[P].push_back({K, C});
        }

        dfs(1), cout << ans << '\n';

        for (int i = 1; i <= N; i++)
            adj[i].clear(), arr[i].clear();
    }

    return 0;
}