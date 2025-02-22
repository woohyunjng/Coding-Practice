#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 200000;

int parent[MAX], rnk[MAX], V[MAX][2], ans[MAX], val[MAX];
vector<tp> st, arr;
vector<pr> tree[MAX * 4];
vector<int> lst[MAX];

int find(int X) { return X == parent[X] ? X : find(parent[X]); }

void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (rnk[X] < rnk[Y])
        swap(X, Y);
    parent[Y] = X;
    if (rnk[X] == rnk[Y])
        rnk[X]++, st.push_back({X, Y, 1});
    else
        st.push_back({X, Y, 0});
}

void rollback(int cnt) {
    tp K;
    while (cnt--) {
        K = st.back(), st.pop_back();
        parent[K[1]] = K[1], rnk[K[0]] -= K[2];
    }
}

void update(int n, int s, int e, int l, int r, pr v) {
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        tree[n].push_back(v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
    }
}

void dfs(int n, int s, int e) {
    int cnt = 0;
    for (pr i : tree[n]) {
        if (find(i[0]) == find(i[1]))
            continue;
        cnt++, uni(i[0], i[1]);
    }

    if (s == e)
        ans[s] = find(arr[s - 1][1]) == find(arr[s - 1][2]);
    else {
        int m = s + e >> 1;
        dfs(n << 1, s, m), dfs(n << 1 | 1, m + 1, e);
    }

    rollback(cnt);
}

map<pr, int> num;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, S, T, X, Y, K = 0;
    vector<tp> query;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        parent[i] = i, rnk[i] = 1;

    for (int i = 0; i < M; i++) {
        cin >> T >> X >> Y;
        if (X > Y)
            swap(X, Y);
        if (num.find((pr){X, Y}) == num.end())
            num[(pr){X, Y}] = ++K;

        query.push_back({T, X, Y});
        if (T == 3)
            arr.push_back({i, X, Y});
    }
    arr.push_back({M + 1, 0, 0}), S = arr.size() - 1;

    for (int i = 0; i < M; i++) {
        val[i] = lower_bound(arr.begin(), arr.end(), (tp){i + 1, 0, 0}) - arr.begin() + 1;
        X = num[{query[i][1], query[i][2]}];
        if (query[i][0] == 2)
            lst[X].push_back(val[i] - 1);
    }

    for (int i = 1; i <= K; i++)
        reverse(lst[i].begin(), lst[i].end());

    for (int i = 0; i < M; i++) {
        if (query[i][0] != 1 || val[i] > S)
            continue;
        X = num[{query[i][1], query[i][2]}];
        if (lst[X].empty())
            Y = S;
        else
            Y = lst[X].back(), lst[X].pop_back();
        update(1, 1, S, val[i], Y, {query[i][1], query[i][2]});
    }

    dfs(1, 1, S);

    for (int i = 1; i <= S; i++)
        cout << ans[i] << '\n';

    return 0;
}