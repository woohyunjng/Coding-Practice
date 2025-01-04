#include <bits/stdc++.h>
#define int long long

#define MAX 3000
#define MOD 998244353

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], in[MAX], out[MAX], num[MAX], dp[MAX][MAX], sm[MAX][MAX];
bool vst[MAX];

vector<int> arr[MAX], rvt_arr[MAX], scc[MAX], adj[MAX];
stack<int> st;
bool checked[MAX];
int scc_num = 0, scc_id[MAX];

void kosaraju_first_dfs(int K) {
    checked[K] = true;
    for (int i : arr[K]) {
        if (!checked[i])
            kosaraju_first_dfs(i);
    }
    st.push(K);
}

void kosaraju_second_dfs(int K) {
    checked[K] = true;
    for (int i : rvt_arr[K]) {
        if (!checked[i])
            kosaraju_second_dfs(i);
    }
    scc[scc_num].push_back(K);
    scc_id[K] = scc_num;
}

void kosaraju(int V) {
    int A;
    for (int i = 1; i <= V; i++) {
        if (!checked[i])
            kosaraju_first_dfs(i);
    }
    fill(checked, checked + V + 1, false);
    while (!st.empty()) {
        A = st.top();
        st.pop();
        if (!checked[A]) {
            kosaraju_second_dfs(A);
            scc_num++;
        }
    }
}

int dfs(int K, int X) {
    if (dp[K][X] != -1)
        return dp[K][X];
    if (X == 0)
        return 0;
    int res = dfs(K, X - 1), val = 1;
    for (int i : adj[K])
        val = val * dfs(i, X) % MOD;
    res = (res + val) % MOD;
    return dp[K][X] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, res = 1, X;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        arr[i].push_back(A[i]), rvt_arr[A[i]].push_back(i);
    }
    kosaraju(N);

    for (int i = 0; i < scc_num; i++) {
        for (int j : scc[i]) {
            for (int k : arr[j]) {
                if (i != scc_id[k])
                    adj[scc_id[k]].push_back(i), in[i]++;
            }
        }
    }

    for (int i = 0; i < scc_num; i++) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }

    fill(&dp[0][0], &dp[scc_num][0], -1);
    for (int i = 0; i < scc_num; i++) {
        if (in[i])
            continue;
        res = (res * dfs(i, M)) % MOD;
    }

    cout << res << '\n';

    return 0;
}