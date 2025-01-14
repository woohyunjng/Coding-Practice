#include <bits/stdc++.h>
#define int long long

#define MAX 100100

using namespace std;
typedef array<int, 2> pr;

vector<pr> adj[MAX];
int dp[MAX][3];
bool vst[MAX];

void pre_dfs(int node) {
    vst[node] = true;
    for (pr i : adj[node]) {
        if (vst[i[0]])
            continue;
        pre_dfs(i[0]);
        dp[node][2] = max(dp[node][2], dp[i[0]][2] + i[1]);
    }
}

void dfs(int node, int len) {
    multiset<int> st;
    vst[node] = true;

    for (pr i : adj[node]) {
        if (vst[i[0]])
            continue;
        st.insert(dp[i[0]][2] + i[1]);
    }

    if (st.empty())
        dp[node][0] = dp[node][1] = len;
    else if (st.size() == 1) {
        dp[node][0] = max(len, *st.begin());
        dp[node][1] = len + *st.begin();
    } else {
        dp[node][0] = max(len, *st.rbegin());
        dp[node][1] = max(len + *st.rbegin(), *next(st.rbegin()) + *st.begin());
    }

    for (pr i : adj[node]) {
        if (vst[i[0]])
            continue;
        st.erase(st.find(dp[i[0]][2] + i[1]));
        if (st.empty())
            dfs(i[0], i[1] + len);
        else
            dfs(i[0], i[1] + max(len, *st.rbegin()));
        dp[node][0] = min(dp[node][0], dp[i[0]][0]), dp[node][1] = max(dp[node][1], dp[i[0]][1]);
        st.insert(dp[i[0]][2] + i[1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, L, A, B, T, res;
    vector<int> arr, dia;

    cin >> N >> M >> L;

    while (M--) {
        cin >> A >> B >> T;
        adj[A].push_back({B, T});
        adj[B].push_back({A, T});
    }

    for (int i = 0; i < N; i++) {
        if (vst[i])
            continue;
        pre_dfs(i);
    }
    fill(vst, vst + N, false);

    for (int i = 0; i < N; i++) {
        if (vst[i])
            continue;
        dfs(i, 0);
        arr.push_back(dp[i][0]), dia.push_back(dp[i][1]);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    sort(dia.begin(), dia.end(), greater<int>());

    if (arr.size() > 2)
        res = max({arr[0] + arr[1] + L, arr[1] + arr[2] + L * 2, dia[0]});
    else if (arr.size() == 2)
        res = max(arr[0] + arr[1] + L, dia[0]);
    else
        res = dia[0];

    cout << res << '\n';

    return 0;
}