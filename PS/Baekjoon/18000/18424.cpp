#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 100000;

int uf[MAX], X[MAX], Y[MAX], XV[MAX], YV[MAX], S[MAX], TP[MAX], ET[MAX], G[MAX],
    tree[MAX * 4];

bool cycle[MAX], ans_chk = true;
vector<pr> match[MAX][2], arr; // 0 -> 세로선, 1 -> 가로선
vector<int> in[MAX], out[MAX];

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] += v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int find(int X) { return X == uf[X] ? X : (uf[X] = find(uf[X])); }

void uni(int A, int B, pr V, int T) {
    if (T == 0 && Y[V[0]] > Y[V[1]])
        swap(V[0], V[1]);
    else if (T == 1 && X[V[0]] > X[V[1]])
        swap(V[0], V[1]);
    ET[arr.size()] = T, arr.push_back(V);

    A = find(A), B = find(B);
    match[A][T].push_back(V);

    if (A == B) {
        cycle[A] = true;
        return;
    } else if (A > B)
        swap(A, B);

    for (int i = 0; i < 2; i++) {
        if (match[A][i] < match[B][i])
            swap(match[A][i], match[B][i]);
        while (!match[B][i].empty())
            match[A][i].push_back(match[B][i].back()), match[B][i].pop_back();
    }
    uf[B] = A, S[A] += S[B];
}

void merge(int A, int B) {
    A = find(A), B = find(B);
    if (A == B)
        return;
    else if (A > B)
        swap(A, B);

    for (int i = 0; i < 2; i++) {
        if (match[A][i] < match[B][i])
            swap(match[A][i], match[B][i]);
        while (!match[B][i].empty())
            match[A][i].push_back(match[B][i].back()), match[B][i].pop_back();
    }
    uf[B] = A, S[A] += S[B];

    if (TP[A] == 2 && TP[B] == 2)
        TP[A] = 2;
    else if (TP[A] != 2 && TP[B] != 2)
        ans_chk &= TP[A] == TP[B];
    else
        TP[A] = TP[A] + TP[B] - 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    pr P, Q;

    fill(XV, XV + MAX, -1), fill(YV, YV + MAX, -1);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i], X[i]--, Y[i]--;
        uf[i] = i, S[i] = 1;
        if (XV[X[i]] != -1)
            uni(i, XV[X[i]], (pr){i, XV[X[i]]}, 0);
        if (YV[Y[i]] != -1)
            uni(i, YV[Y[i]], (pr){i, YV[Y[i]]}, 1);
        XV[X[i]] = i, YV[Y[i]] = i;
    }

    K = arr.size();

    set<tp> st;
    set<tp>::iterator iter;

    for (int i = 0; i < K; i++) {
        if (ET[i] == 0)
            G[X[arr[i][0]]] = i + 1;
        else
            in[X[arr[i][0]]].push_back(i), out[X[arr[i][1]]].push_back(i);
    }

    for (int i = 0; i < N; i++) {
        if (find(i) != i)
            continue;
        if (S[i] % 2 == 1)
            ans_chk = false;

        if (!cycle[i])
            TP[i] = (int)match[i][0].size() > (int)match[i][1].size() ? 0 : 1;
        else
            TP[i] = 2;
    }

    int L, R, E;
    tp Z;

    for (int i = 0; i < MAX; i++) {
        for (int j : in[i]) {
            update(1, 0, MAX - 1, Y[arr[j][0]], 1), L = Y[arr[j][0]];
            iter = st.lower_bound({L + 1, 0, 0});
            if (iter != st.begin() && (*prev(iter))[1] >= L) {
                iter = prev(iter), Z = *iter, st.erase(iter);
                if (Z[0] < L)
                    st.insert({Z[0], L - 1, Z[2]});
                if (Z[1] > L)
                    st.insert({L + 1, Z[1], Z[2]});
            }
            st.insert({L, L, find(arr[j][0])});
        }

        if (G[i] > 0) {
            G[i]--, L = Y[arr[G[i]][0]], R = Y[arr[G[i]][1]], E = arr[G[i]][0];

            iter = st.lower_bound((tp){L, 0, 0});
            if (iter != st.begin() && (*prev(iter))[1] >= L) {
                iter = prev(iter), Z = *iter, st.erase(iter);
                st.insert({Z[0], L - 1, Z[2]});
                if (Z[1] > R)
                    st.insert({R + 1, Z[1], Z[2]});
                if (query(1, 0, MAX - 1, L, min(Z[1], R)) > 0)
                    merge(Z[2], E);
            }

            iter = st.lower_bound({L, 0, 0});
            while (iter != st.end()) {
                if ((*iter)[0] > R)
                    break;
                Z = *iter, st.erase(iter);
                if (query(1, 0, MAX - 1, Z[0], min(Z[1], R)) > 0)
                    merge(Z[2], E);
                if (Z[1] > R)
                    st.insert({R + 1, Z[1], Z[2]});
                iter = st.lower_bound((tp){L, 0, 0});
            }

            st.insert({L, R, find(E)});
        }

        for (int j : out[i])
            update(1, 0, MAX - 1, Y[arr[j][0]], -1);
    }

    if (!ans_chk) {
        cout << "NE\n";
        return 0;
    }

    vector<vector<int>> ans;

    cout << "DA\n";
    for (int i = 0; i < N; i++) {
        if (find(i) != i)
            continue;
        if (TP[i] == 2)
            TP[i] = 0;
        for (pr j : match[i][TP[i]])
            cout << j[0] + 1 << ' ' << j[1] + 1 << '\n';
    }

    return 0;
}