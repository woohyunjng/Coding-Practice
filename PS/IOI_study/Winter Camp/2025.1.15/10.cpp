#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

vector<int> arr[MAX], rvt_arr[MAX];
stack<int> st;
bool checked[MAX];
int scc_num = 0, A[MAX], val[MAX];

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
    val[scc_num] = min(val[scc_num], A[K]);
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
    cin.tie(0), cout.tie(0);

    int V, E, X, Y, res = 0;
    cin >> V >> E;

    for (int i = 1; i <= V; i++)
        cin >> A[i], val[i - 1] = INF;

    while (E--) {
        cin >> X >> Y;
        arr[X].push_back(Y), rvt_arr[Y].push_back(X);
    }

    kosaraju(V);

    for (int i = 0; i < scc_num; i++)
        res += val[i];
    cout << res << '\n';

    return 0;
}