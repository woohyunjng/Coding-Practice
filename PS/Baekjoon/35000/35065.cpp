#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400001;
const int MOD = 998'244'353;

vector<int> adj[MAX], arr;
set<int> stadj[MAX];
int ans[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, U, V, D = 0, S;
    set<int> cur, asdf;
    vector<int> st, arr, backup;

    cin >> N >> M, arr.push_back(1);
    while (M--) {
        cin >> U >> V;
        adj[U].push_back(V), adj[V].push_back(U);
        stadj[U].insert(V), stadj[V].insert(U);
    }

    for (int i = 2; i <= N; i++)
        st.push_back(i);

    cnt[1] = 1;
    while (!arr.empty()) {
        sort(arr.begin(), arr.end(), [&](int x, int y) { return adj[x].size() < adj[y].size(); });
        D++, S = 0;
        for (int i : adj[arr[0]])
            cur.insert(i);

        for (int i : arr) {
            backup.clear(), S = (S + cnt[i]) % MOD, asdf.insert(i);
            for (int j : cur)
                if (stadj[i].find(j) != stadj[i].end())
                    backup.push_back(j);
            cur.clear();
            for (int j : backup)
                cur.insert(j);
        }
        arr.clear();

        for (int i : st) {
            if (cur.find(i) != cur.end())
                continue;
            arr.push_back(i);
        }

        st.clear();
        for (int i : cur)
            st.push_back(i);
        cur.clear();

        for (int i : arr) {
            ans[i] = D, cnt[i] = S;
            for (int j : adj[i])
                if (asdf.find(j) != asdf.end())
                    cnt[i] = (cnt[i] - cnt[j] + MOD * 3) % MOD;
        }
        asdf.clear();
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ' << cnt[i] << '\n';

    return 0;
}