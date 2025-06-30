#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

typedef array<int, 2> pr;

int N, A[MAX], V[MAX], tree[MAX * 4][2], ans[MAX], st[MAX], en[MAX], L[MAX], R[MAX], K[MAX];
vector<int> num, arr[MAX];

int merge(int X, int Y) { return A[Y] < A[X] ? Y : X; }

void minit(int n, int s, int e) {
    if (s == e)
        tree[n][0] = s;
    else {
        int m = s + e >> 1;
        minit(n << 1, s, m), minit(n << 1 | 1, m + 1, e);
        tree[n][0] = merge(tree[n << 1][0], tree[n << 1 | 1][0]);
    }
}

int mquery(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n][0];
    else {
        int m = s + e >> 1;
        return merge(mquery(n << 1, s, m, l, r), mquery(n << 1 | 1, m + 1, e, l, r));
    }
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n][1] = 0;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n][1] = tree[n << 1][1] + tree[n << 1 | 1][1];
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n][1];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n][1] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n][1] = tree[n << 1][1] + tree[n << 1 | 1][1];
    }
}

void dnc(int l, int r, int par) {
    if (l > r)
        return;
    int X = mquery(1, 1, N, l, r);
    if (par != 0) {
        V[X] = A[par] + A[X];
        num.push_back(A[par] + A[X]);
    } else
        V[X] = A[X] * 2;
    num.push_back(A[X] * 2);
    dnc(l, X - 1, X), dnc(X + 1, r, X);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, C[2], Y, Z, SL, SR, val;
    bool flag;

    vector<int> X[2];
    set<int> S;
    set<int>::iterator iter;

    cin >> N >> Q, A[0] = INF;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    minit(1, 1, N), dnc(1, N, 0);

    for (int i = 1; i <= N; i++)
        X[0].push_back(i), X[1].push_back(i);

    sort(num.begin(), num.end()), num.erase(unique(num.begin(), num.end()), num.end());
    sort(X[0].begin(), X[0].end(), [](int x, int y) { return A[x] < A[y]; });
    sort(X[1].begin(), X[1].end(), [](int x, int y) { return V[x] < V[y]; });

    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i] >> K[i];
        st[i] = 0, en[i] = num.size() - 1, ans[i] = INF;
    }

    int cnt = 0;
    while (true) {
        flag = false, S.clear(), C[0] = C[1] = 0;
        init(1, 1, N), cnt++;

        for (int i = 0; i < num.size(); i++)
            arr[i].clear();
        for (int i = 1; i <= Q; i++) {
            if (st[i] <= en[i])
                flag = true, arr[st[i] + en[i] >> 1].push_back(i);
        }
        if (!flag)
            break;

        for (int i = 0; i < num.size(); i++) {
            Y = num[i];
            while (C[0] < X[0].size() && A[X[0][C[0]]] * 2 <= Y)
                S.insert(X[0][C[0]++]);
            while (C[1] < X[1].size() && V[X[1][C[1]]] <= Y)
                update(1, 1, N, X[1][C[1]++], 1);

            for (int j : arr[i]) {
                flag = false, SL = N + 1, SR = 0;
                iter = S.lower_bound(L[j]);

                if (iter == S.end() || *iter > R[j])
                    flag = true;
                else
                    SL = *iter;

                iter = S.lower_bound(R[j] + 1);
                if (iter == S.begin() || *(--iter) < L[j])
                    flag = true;
                else
                    SR = *iter;

                val = query(1, 1, N, SL, SR);
                Z = max(A[SL], A[SR]) + min(A[mquery(1, 1, N, L[j], SL - 1)], A[mquery(1, 1, N, SR + 1, R[j])]);

                if (Z <= Y)
                    val++;
                else if (val == K[j] - 1)
                    ans[j] = min(ans[j], Z);

                flag |= val < K[j];
                if (flag)
                    st[j] = i + 1;
                else
                    en[j] = i - 1, ans[j] = min(ans[j], Y);
            }
        }
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}