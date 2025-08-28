#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef priority_queue<int> pq_t;

const int MAX = 250001;
const int MAX_D = 1000001;

int S[MAX], E[MAX], V[MAX];
vector<int> in[MAX_D], out[MAX_D], adj[MAX];

void merge(pq_t &X, pq_t &Y) {
    pq_t tmp;
    int A, B;

    while (!Y.empty()) {
        A = X.top(), X.pop(), B = Y.top(), Y.pop();
        tmp.push(A + B);
    }
    while (!tmp.empty())
        X.push(tmp.top()), tmp.pop();
}

pq_t dfs(int node) {
    pq_t res, val, tmp;
    int A, B;

    for (int i : adj[node]) {
        val = dfs(i);
        if (val.size() > res.size())
            swap(val, res);

        while (!val.empty()) {
            A = res.top(), res.pop(), B = val.top(), val.pop();
            tmp.push(A + B);
        }
        while (!tmp.empty())
            res.push(tmp.top()), tmp.pop();
    }

    res.push(V[node]);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    vector<int> st;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> E[i] >> V[i];
        in[S[i]].push_back(i), out[E[i]].push_back(i);
    }

    for (int i = 1; i < MAX_D; i++) {
        sort(in[i].begin(), in[i].end(), [&](int x, int y) { return E[x] > E[y]; });
        sort(out[i].begin(), out[i].end(), [&](int x, int y) { return S[x] > S[y]; });

        for (int j : out[i])
            while (!st.empty() && st.back() != j)
                adj[j].push_back(st.back()), st.pop_back();
        for (int j : in[i])
            st.push_back(j);
    }

    for (int i : st)
        adj[0].push_back(i);

    pq_t res = dfs(0);
    for (int i = 1; i <= N; i++) {
        if (!res.empty())
            ans += res.top(), res.pop();
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}