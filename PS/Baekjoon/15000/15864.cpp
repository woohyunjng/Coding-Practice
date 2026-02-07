#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int N, M, A[MAX], B[MAX], P[MAX], C[MAX], L[MAX], R[MAX],
    CL[MAX], CR[MAX],
    S[MAX][2], tree[MAX * 4];
bool av[MAX];

bool chk() {
    bool res = true;
    for (int i = 0; i <= N; i++)
        S[i][0] = S[i][1] = 0;
    for (int i = 1; i <= M; i++) {
        if (B[i] <= N)
            S[A[i]][C[i]]++, S[B[i] + 1][C[i]]--;
        else
            S[A[i]][C[i]]++, S[1][C[i]]++, S[B[i] + 1 - N][C[i]]--;
    }
    for (int i = 1; i <= N; i++) {
        S[i][0] += S[i - 1][0], S[i][1] += S[i - 1][1];
        res &= S[i][0] > 0 && S[i][1] > 0;
    }
    return res;
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = max(tree[n], v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return max(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int X = 0, Y, TA[4], TB[4];
    string ans = "impossible";
    bool flag;

    vector<int> arr, st, val;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i], arr.push_back(i);
        if (B[i] < A[i])
            B[i] += N;
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return A[x] == A[y] ? B[x] > B[y] : A[x] < A[y]; });
    for (int i : arr) {
        if (!st.empty() && B[st.back()] >= B[i]) {
            P[i] = st.back();
            continue;
        }
        st.push_back(i);
    }

    for (int i : st)
        if (B[i] > N)
            X = i;
    arr = st, st.clear();
    for (int i : arr) {
        if (B[i] <= N && B[i] < B[X] - N)
            P[i] = X;
        else
            st.push_back(i);
    }

    if (st.size() % 2 == 0) {
        for (int i = 0; i < st.size(); i++)
            C[st[i]] = i & 1;
        for (int i = 1; i <= M; i++)
            if (P[i] != 0)
                C[i] = C[P[i]] ^ 1;
        if (chk()) {
            ans = "";
            for (int i = 1; i <= M; i++)
                ans += (char)('0' + C[i]);
        }
    } else {
        arr.clear();
        for (int i = 1; i <= M; i++)
            if (P[i] != 0) {
                L[i] = A[i], R[i] = B[i];
                arr.push_back(i);
            }

        sort(arr.begin(), arr.end(), [&](int x, int y) { return L[x] == L[y] ? R[x] < R[y] : L[x] < L[y]; });
        for (int i : arr) {
            if (!val.empty() && R[val.back()] + 1 >= L[i])
                R[val.back()] = max(R[val.back()], R[i]);
            else
                val.push_back(i);
        }

        arr = val, val.clear(), X = 0;
        for (int i : arr)
            if (R[i] > N)
                X = i;
        for (int i : arr) {
            if (X != 0 && R[i] <= N && R[X] - N + 1 >= L[i])
                R[X] = max(R[X], R[i] + N);
            else
                val.push_back(i);
        }

        sort(val.begin(), val.end(), [&](int x, int y) { return L[x] < L[y]; });
        for (int i : val) {
            if (L[i] > N && R[i] > N)
                L[i] -= N, R[i] -= N;
            update(1, 1, N * 2, L[i], R[i]);
        }

        sort(st.begin(), st.end(), [&](int x, int y) { return A[x] < A[y]; });
        if (st.size() == 1)
            av[0] = true;
        else {
            for (int i = 0; i < st.size(); i++) {
                av[i] = true, X = st[i], Y = st[(i + 1) % st.size()];
                TB[0] = B[st[(i + (int)st.size() - 1) % st.size()]];
                TA[1] = A[X], TB[1] = B[X], TA[2] = A[Y], TB[2] = B[Y];
                TA[3] = A[st[(i + 2) % st.size()]];

                if (i + 1 >= st.size())
                    TA[2] += N, TB[2] += N;
                if (i + 2 >= st.size())
                    TA[3] += N;
                if (i == 0)
                    TB[0] -= N;

                if (TA[2] > TB[1]) {
                    av[i] = true;
                    continue;
                }

                CL[i] = TA[2], CR[i] = TB[1];
                CL[i] = max(CL[i], TB[0] + 1), CR[i] = min(CR[i], TA[3] - 1);
                if (CL[i] > CR[i]) {
                    av[i] = true;
                    continue;
                }

                if (CL[i] > N && CR[i] > N)
                    CL[i] -= N, CR[i] -= N;
                av[i] = query(1, 1, N * 2, 1, CL[i]) >= CR[i];
            }
        }

        X = -1;
        for (int i = 0; i < st.size(); i++)
            if (av[i])
                X = i;

        C[st[X]] = 0;
        for (int i = X + 1; i < X + st.size(); i++)
            C[st[i % st.size()]] = (i - X - 1) & 1;
        for (int i = 1; i <= M; i++)
            if (P[i] != 0)
                C[i] = C[P[i]] ^ 1;
        if (chk()) {
            ans = "";
            for (int i = 1; i <= M; i++)
                ans += (char)('0' + C[i]);
        }
    }

    cout << ans << '\n';

    return 0;
}