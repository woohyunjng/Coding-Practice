#include <bits/stdc++.h>
#define int long long

#define endl '\n'
#define INF 0x7f7f7f7f7f7f7f7f
#define MAX 301000

using namespace std;
typedef pair<int, int> pr;
typedef pair<pr, pr> ppr;
typedef array<int, 3> tp;

int parent[MAX], longest[MAX], dia[MAX];
ppr dp[MAX];
vector<int> child[MAX], dfs_order;
vector<pr> tmp;

ppr merge(ppr A, pr B) {
    ppr res;

    tmp.push_back(A.first);
    tmp.push_back(A.second);
    tmp.push_back(B);
    sort(tmp.begin(), tmp.end(), greater<pr>());

    res = {tmp[0], tmp[1]};
    tmp.clear();

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, res, X, Y;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        cin >> parent[i];
        child[parent[i]].push_back(i);
    }

    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        K = st.top(), st.pop();
        dfs_order.push_back(K);

        for (int i : child[K])
            st.push(i);
    }

    for (int x = N - 1; x >= 0; x--) {
        K = dfs_order[x];
        dia[K] = max(dia[K], dp[K].first.first + dp[K].second.first);

        dp[parent[K]] = merge(dp[parent[K]], {dp[K].first.first + 1, K});
        dia[parent[K]] = max(dia[parent[K]], dia[K]);
    }

    for (int x = 0; x < N; x++) {
        K = dfs_order[x];

        if (K != 1 && parent[K] != 1)
            longest[K] = longest[parent[K]] + 1;

        if (dp[parent[K]].first.second != K)
            longest[K] = max(longest[K], dp[parent[K]].first.first);
        else
            longest[K] = max(longest[K], dp[parent[K]].second.first);
    }

    for (int i = 2; i <= N; i++) {
        res = dia[i] + longest[i] + 1;
        res = max(res, dia[1]);
        cout << res << '\n';
    }

    return 0;
}