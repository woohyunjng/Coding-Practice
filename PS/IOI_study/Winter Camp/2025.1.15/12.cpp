#include <bits/stdc++.h>
#define int long long
#define MAX 500100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX], rvt_arr[MAX], scc[MAX], scc_arr[MAX];
stack<int> st;
bool checked[MAX];
int scc_num = 0, scc_id[MAX], money[MAX], scc_money[MAX], in_degree[MAX], dp[MAX];

void kosaraju_first_dfs(int K) {
    checked[K] = true;
    for (int i : arr[K])
        if (!checked[i])
            kosaraju_first_dfs(i);
    st.push(K);
}

void kosaraju_second_dfs(int K) {
    checked[K] = true;
    for (int i : rvt_arr[K])
        if (!checked[i])
            kosaraju_second_dfs(i);
    scc[scc_num].push_back(K);
    scc_money[scc_num] += money[K];
    scc_id[K] = scc_num;
}

void kosaraju(int V) {
    int A;
    for (int i = 1; i <= V; i++)
        if (!checked[i])
            kosaraju_first_dfs(i);

    fill(checked, checked + V + 1, false);
    while (!st.empty()) {
        A = st.top(), st.pop();
        if (!checked[A])
            kosaraju_second_dfs(A), scc_num++;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, S, P, res = 0;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        arr[A].push_back(B), rvt_arr[B].push_back(A);
    }

    for (int i = 1; i <= N; i++)
        cin >> money[i];

    kosaraju(N);
    for (int i = 1; i <= N; i++)
        for (int j : arr[i])
            if (scc_id[i] != scc_id[j])
                scc_arr[scc_id[i]].push_back(scc_id[j]);

    for (int i = 0; i < scc_num; i++) {
        sort(scc_arr[i].begin(), scc_arr[i].end());
        scc_arr[i].erase(unique(scc_arr[i].begin(), scc_arr[i].end()), scc_arr[i].end());
    }

    queue<int> q;
    cin >> S >> P;
    q.push(scc_id[S]);

    while (!q.empty()) {
        A = q.front(), q.pop();
        for (int i : scc_arr[A])
            if (++in_degree[i] == 1)
                q.push(i);
    }

    q.push(scc_id[S]);
    while (!q.empty()) {
        A = q.front(), q.pop();
        dp[A] += scc_money[A];

        for (int i : scc_arr[A]) {
            dp[i] = max(dp[i], dp[A]);
            if (--in_degree[i] == 0)
                q.push(i);
        }
    }

    while (P--) {
        cin >> A;
        res = max(res, dp[scc_id[A]]);
    }
    cout << res;

    return 0;
}