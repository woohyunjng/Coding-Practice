#include <bits/stdc++.h>
#define int long long

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef array<int, 2> pr;
typedef array<int, 3> tp;
typedef array<int, 5> ftp; // i, l, r, -3 -> 쿼리 i, l, r, v -> 전체 블럭 쿼리 i, l, r, -1 -> i 추가, i, l, r, -2 -> i 제거

const int MAX = 300010;

int N, S[MAX], ans[MAX], tree[3][MAX];
vector<tp> val[MAX];

int query(int t, int n) {
    int res = 0;
    for (; n; n -= n & -n)
        res += tree[t][n];
    return res;
}

void update(int t, int x, int v) {
    for (; x <= N; x += x & -x)
        tree[t][x] += v;
}

int query(int t, int l, int r) { return query(t, r) - query(t, l - 1); }

void dnc(vector<ftp> arr) {
    if (arr.size() <= 1)
        return;

    vector<ftp> left, right, val;
    int S = arr.size();

    for (int i = 0; i < S / 2; i++)
        left.push_back(arr[i]);
    for (int i = S / 2; i < S; i++)
        right.push_back(arr[i]);

    for (ftp i : left) {
        if (i[3] != -3)
            val.push_back(i);
    }
    for (ftp i : right) {
        if (i[3] == -3)
            val.push_back(i);
    }
    sort(val.begin(), val.end(), [&](ftp x, ftp y) { return x[1] == y[1] ? x[3] > y[3] : x[1] < y[1]; });

    for (ftp i : val) {
        if (i[3] == -3)
            ans[i[0]] += query(0, i[2], N) + query(1, i[2], N) * i[0] - query(2, i[2], N);
        else if (i[3] == -2)
            update(1, i[2], -1), update(2, i[2], -i[4]);
        else if (i[3] == -1)
            update(1, i[2], 1), update(2, i[2], i[0]);
        else
            update(0, i[2], i[3]);
    }

    for (ftp i : val) {
        if (i[3] == -3)
            continue;
        else if (i[3] == -2)
            update(1, i[2], 1), update(2, i[2], i[4]);
        else if (i[3] == -1)
            update(1, i[2], -1), update(2, i[2], -i[0]);
        else
            update(0, i[2], -i[3]);
    }

    dnc(left), dnc(right);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y;
    tp K, V;
    string T;

    set<tp> st;
    set<tp>::iterator iter;

    vector<ftp> arr;

    cin >> N >> Q >> T;

    for (int i = 1; i <= N; i++)
        S[i] = T[i - 1] - '0';

    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == 0 && S[i] == 1)
            X = i;
        if (S[i] == 1 && S[i + 1] == 0)
            st.insert({X, i, 0});
    }

    function add = [&](ftp X) {
        arr.push_back({X[3], X[1], X[2], -1, 0}), arr.push_back({X[0], X[1], X[2], -2, X[3]}), arr.push_back({X[0], X[1], X[2], X[0] - X[3], 0});
    };

    for (int i = 1; i <= Q; i++) {
        cin >> T;
        if (T == "query") {
            cin >> X >> Y, Y--;
            arr.push_back({i, X, Y, -3, 0});
        } else {
            ans[i] = -1;
            cin >> X;

            if (S[X] == 1) {
                iter = prev(st.lower_bound({X, N + 1, 0})), K = *iter, st.erase(iter);
                add({i, K[0], K[1], K[2]});
                if (K[0] < X)
                    st.insert({K[0], X - 1, i});
                if (X < K[1])
                    st.insert({X + 1, K[1], i});
            } else {
                iter = st.lower_bound({X, N + 1, 0}), V = {X, X, i};
                if (iter != st.end() && (*iter)[0] == X + 1) {
                    K = *iter, st.erase(iter);
                    add({i, K[0], K[1], K[2]}), V[1] = K[1];
                }
                iter = st.lower_bound({X, N + 1, 0});
                if (iter != st.begin() && (*prev(iter))[1] + 1 == X) {
                    K = *prev(iter), st.erase(prev(iter));
                    add({i, K[0], K[1], K[2]}), V[0] = K[0];
                }
                st.insert(V);
            }

            S[X] ^= 1;
        }
    }

    for (tp i : st)
        add({Q + 1, i[0], i[1], i[2]});
    st.clear();

    sort(arr.begin(), arr.end(), [&](ftp x, ftp y) { return x[0] < y[0]; });

    dnc(arr);

    for (int i = 1; i <= Q; i++)
        if (ans[i] != -1)
            cout << ans[i] << '\n';
}
