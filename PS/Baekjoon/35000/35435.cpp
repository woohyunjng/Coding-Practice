#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 280001;
const int INF = 0x3f3f3f3f3f3f3f3f;

typedef array<int, 2> pr;

struct Node {
    int sqsm = 0, S[2] = {0, 0};
    pr M[2] = {{INF, INF}, {INF, INF}};

    Node() {}
    Node(int v) : sqsm(v * v) {
        S[v >= 0] = abs(v), M[v >= 0][0] = abs(v);
    }
};

int A[MAX];
Node tree[MAX * 4];

pr merge(pr X, pr Y) {
    if (X[0] >= Y[0])
        swap(X, Y);
    return {X[0], min(X[1], Y[0])};
}

Node merge(Node X, Node Y) {
    if (X.M[0][0] == INF && X.M[1][0] == INF)
        return Y;
    if (Y.M[0][0] == INF && Y.M[1][0] == INF)
        return X;

    Node res;
    res.sqsm = X.sqsm + Y.sqsm;
    for (int i = 0; i < 2; i++) {
        res.S[i] = X.S[i] + Y.S[i];
        res.M[i] = merge(X.M[i], Y.M[i]);
    }
    return res;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = Node(A[s]);
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = Node(v);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return Node();
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, I, V, L, R, K, ans;
    Node val;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> I >> V, update(1, 1, N, I, V);
        } else {
            cin >> L >> R >> K, ans = 0;
            val = query(1, 1, N, L, R);

            if (K == 1)
                ans = -val.S[0] + val.S[1], ans = ans * ans;
            else {
                if (val.M[0][0] == INF)
                    swap(val.M[0], val.M[1]), swap(val.S[0], val.S[1]);

                if (K == 2) {
                    if (val.M[1][0] == INF)
                        ans = (val.S[0] - val.M[0][0]) * (val.S[0] - val.M[0][0]) + val.M[0][0] * val.M[0][0];
                    else
                        ans = val.S[0] * val.S[0] + val.S[1] * val.S[1];
                } else {
                    if (val.M[1][0] == INF) {
                        for (int i = 0; i < 2; i++)
                            val.S[0] -= val.M[0][i], ans += val.M[0][i] * val.M[0][i];
                        ans += val.S[0] * val.S[0];
                    } else {
                        ans = max(
                            val.M[0][1] == INF ? -INF : ((val.S[0] - val.M[0][0]) * (val.S[0] - val.M[0][0]) + val.M[0][0] * val.M[0][0] + val.S[1] * val.S[1]),
                            val.M[1][1] == INF ? -INF : ((val.S[1] - val.M[1][0]) * (val.S[1] - val.M[1][0]) + val.M[1][0] * val.M[1][0] + val.S[0] * val.S[0]));
                    }
                }
            }

            ans -= val.sqsm;
            cout << ans / 2 << '\n';
        }
    }

    return 0;
}
