#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> tp;

const int MAX = 1001;

tp queries[MAX];

tp query(int l, int r) {
    if (l == 1 && queries[r][0] != 0)
        return queries[r];
    cout << "count " << l << ' ' << r << '\n', cout.flush();
    tp res;
    cin >> res[3] >> res[2] >> res[1] >> res[0];
    if (l == 1)
        queries[r] = res;
    return res;
}

void answer(tp &K) {
    cout << "answer " << K[0] << ' ' << K[1] << ' ' << K[2] << ' ' << K[3] << '\n', cout.flush();
}

int diff(tp &X, tp &Y) {
    for (int i = 0; i < 4; i++)
        if (X[i] != Y[i])
            return i;
}

pr get(tp &X, int A, int B) {
    pr res = {};
    int Y, Z, K = 0;
    for (int i = 0; i < 4; i++)
        if (X[i] == A)
            Y = i;
    for (int i = 0; i < 4; i++)
        if (i != Y && X[i] == B)
            Z = i;
    for (int i = 0; i < 4; i++)
        if (i != Y && i != Z)
            res[K++] = X[i];
    return res;
}

signed main() {
    int T, N, st, en, md, V, A, B, Y, Z;
    tp K, X[5], C;
    pr P, Q;

    cin >> T;
    while (T--) {
        cin >> N, st = 1, en = N;

        for (int i = 1; i <= N; i++)
            queries[i] = {0, 0, 0, 0};

        X[0] = query(1, N);
        if (X[0][1] == 0) {
            answer(X[0]);
            continue;
        } else if (X[0][2] == 0) {
            X[1] = query(1, N - 1);
            if (X[0][0] != X[1][0])
                swap(X[0][0], X[0][1]);
            answer(X[0]);
            continue;
        } else if (X[0][3] == 0) {
            X[1] = query(1, N - 1), X[2] = query(2, N), C[3] = 0;
            C[2] = X[0][diff(X[0], X[1])], C[0] = X[0][diff(X[0], X[2])];
            C[1] = N - C[0] - C[2], answer(C);
            continue;
        }

        while (st <= en) {
            md = st + en >> 1;
            K = query(1, md);

            if (K[2] == 0)
                V = md, st = md + 1;
            else
                en = md - 1;
        }

        X[1] = query(2, N), X[2] = query(V + 1, N), X[3] = query(V + 2, N), X[4] = query(1, V), X[5] = query(1, V - 1);
        Y = diff(X[0], X[1]), C[0] = X[0][Y], C[2] = X[2][diff(X[2], X[3])];
        A = C[0] - X[4][1 - diff(X[4], X[5])];

        P = get(X[0], C[0], C[2]), Q = get(X[2], A, C[2]);
        if (P[0] == Q[0] || P[0] == Q[1])
            C[3] = P[0];
        else
            C[3] = P[1];

        C[1] = N - C[0] - C[2] - C[3];
        answer(C);
    }

    return 0;
}