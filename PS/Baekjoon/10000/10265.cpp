#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX], rvt_arr[MAX], scc[MAX];
stack<int> st;
bool checked[MAX], dp[MAX][MAX];
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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, res = 0, A, B;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> X;
        if (i != X) {
            arr[X].push_back(i);
            rvt_arr[i].push_back(X);
        }
    }

    kosaraju(N);

    vector<pr> sz;
    queue<int> q;

    fill(checked, checked + N + 1, false);

    for (int i = 1; i <= scc_num; i++) {
        if (scc[i - 1].size() > 1 || rvt_arr[scc[i - 1][0]].size() == 0) {
            X = scc[i - 1][0];
            A = scc[i - 1].size(), B = scc[i - 1].size();

            q.push(X);
            checked[X] = true;

            while (!q.empty()) {
                X = q.front(), q.pop();
                for (int j : arr[X]) {
                    if (checked[j])
                        continue;
                    checked[j] = true;
                    q.push(j);

                    if (scc_id[j] != i - 1)
                        B++;
                }
            }

            sz.push_back({A, B});
        }
    }

    dp[0][0] = true;
    for (int i = 1; i <= sz.size(); i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            for (int k = sz[i - 1].first; k <= sz[i - 1].second; k++) {
                if (j >= k) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - k];
                }
            }
        }
    }

    for (int i = 1; i <= K; i++)
        if (dp[sz.size()][i])
            res = i;

    cout << res;

    return 0;
}