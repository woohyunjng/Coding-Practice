#include <bits/stdc++.h>
#define int long long

#define MAX 400000
#define MAX_LOG 19

using namespace std;
typedef array<int, 2> pr;

int L[MAX], R[MAX], sparse[MAX][MAX_LOG], val[MAX];

int get(int s, int e) {
    int res = 0, X = s;
    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (sparse[X][i] != 0 && sparse[X][i] - 1 <= e)
            X = sparse[X][i], res += 1 << i;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, S, X = 0, cnt = 0;
    pr Z;

    set<pr> st;
    set<pr>::iterator iter;
    vector<int> comp;

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        comp.push_back(L[i]), comp.push_back(R[i] - 1);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    fill(val, val + S + 1, S + 1);

    for (int i = 1; i <= N; i++) {
        L[i] = lower_bound(comp.begin(), comp.end(), L[i]) - comp.begin() + 1;
        R[i] = lower_bound(comp.begin(), comp.end(), R[i] - 1) - comp.begin() + 1;
        val[L[i]] = min(val[L[i]], R[i]);
    }

    for (int i = S - 1; i >= 1; i--) {
        val[i] = min(val[i], val[i + 1]);
        sparse[i][0] = val[i] + 1;
        for (int j = 1; sparse[i][j - 1] <= S && j < MAX_LOG; j++)
            sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
    }

    if (get(1, S) < K) {
        cout << -1 << '\n';
        return 0;
    }

    X = get(1, S), st.insert({1, S});
    for (int i = 1; i <= N && cnt < K; i++) {
        if (st.upper_bound({L[i], S + 1}) != st.upper_bound({R[i], S + 1}) || st.upper_bound({L[i], S + 1}) == st.begin())
            continue;
        Z = *prev(st.upper_bound({L[i], S + 1}));
        if (!(Z[0] <= L[i] && R[i] <= Z[1]))
            continue;

        if (X - get(Z[0], Z[1]) + get(Z[0], L[i] - 1) + get(R[i] + 1, Z[1]) + 1 >= K) {
            X = X - get(Z[0], Z[1]) + get(Z[0], L[i] - 1) + get(R[i] + 1, Z[1]) + 1, cnt++;
            cout << i << '\n', st.erase(prev(st.upper_bound({L[i], S + 1})));

            if (Z[0] <= L[i] - 1)
                st.insert({Z[0], L[i] - 1});
            if (R[i] + 1 <= Z[1])
                st.insert({R[i] + 1, Z[1]});
        }
    }

    return 0;
}