#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 200001;

vector<int> adj[MAX];
vector<tp> st;

int M, U[MAX], V[MAX], R[MAX],
    uf[MAX << 1 | 1], urank[MAX << 1 | 1];

int find(int X) { return uf[X] == X ? X : find(uf[X]); }
bool uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return false;
    if (urank[X] < urank[Y])
        swap(X, Y);
    st.push_back({X, Y, urank[X] == urank[Y]});
    uf[Y] = X, urank[X] += urank[X] == urank[Y];
    return true;
}
void rollback() {
    tp K = st.back();
    st.pop_back();
    uf[K[1]] = K[1], urank[K[0]] -= K[2];
}

bool enable(int X) {
    if (find(U[X] << 1) == find(V[X] << 1))
        return true;
    uni(U[X] << 1, V[X] << 1 | 1), uni(U[X] << 1 | 1, V[X] << 1);
    return false;
}

void dnc(int l, int r, int s, int e) {
    if (l > r)
        return;
    int m = l + r >> 1, P = st.size(), X;

    for (int i = l; i < m; i++) {
        if (enable(i)) {
            while (st.size() > P)
                rollback();
            fill(R + m, R + r + 1, M + 1), dnc(l, m - 1, s, e);
            return;
        }
    }

    X = st.size();
    for (int i = e; i >= s; i--) {
        if (i == 0 || enable(i)) {
            while (st.size() > X)
                rollback();
            R[m] = i;
            if (enable(m))
                fill(R + m + 1, R + r + 1, M + 1);
            else
                dnc(m + 1, r, i, e);
            while (st.size() > P)
                rollback();
            for (int j = e; j > i; j--)
                enable(j);
            dnc(l, m - 1, s, i);
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y;

    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
        uf[i << 1] = i << 1, uf[i << 1 | 1] = i << 1 | 1;

    for (int i = 1; i <= M; i++)
        cin >> U[i] >> V[i], R[i] = M + 1;
    dnc(1, M, 0, M);

    while (Q--) {
        cin >> X >> Y;
        cout << (R[X] <= Y ? "NO" : "YES") << '\n';
    }

    return 0;
}