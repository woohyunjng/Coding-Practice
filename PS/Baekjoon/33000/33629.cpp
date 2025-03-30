#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MAX_K = 11;

struct Node {
    int point[MAX_K], sm[MAX_K], end[MAX_K], res;

    // point -> i에서 시작했을때 끝나는 친구
    // sm -> 하나의 친구가 i에서 시작했을때 비용
    // end -> i에서 끝나는 친구들의 수
    // res -> 결과값

    Node() {
        for (int i = 1; i < MAX_K; i++)
            point[i] = i;
        fill(sm, sm + MAX_K, 0);
        fill(end, end + MAX_K, 0);
        res = 0;
    }
};

Node merge(Node X, Node Y) {
    Node res;

    for (int i = 1; i < MAX_K; i++)
        res.point[i] = Y.point[X.point[i]];

    for (int i = 1; i < MAX_K; i++)
        res.end[i] = Y.end[i];
    for (int i = 1; i < MAX_K; i++)
        res.end[Y.point[i]] += X.end[i];

    for (int i = 1; i < MAX_K; i++)
        res.sm[i] = X.sm[i] + Y.sm[X.point[i]];

    res.res = X.res + Y.res;
    for (int i = 1; i < MAX_K; i++)
        res.res += Y.sm[i] * X.end[i];

    return res;
}

int A[MAX], B[MAX], C[MAX][MAX_K];
Node tree[MAX * 4];

void init(int n, int s, int e) {
    if (s == e) {
        tree[n] = Node(), tree[n].res = C[s][1];
        for (int i = 1; i < MAX_K; i++)
            tree[n].sm[i] = C[s][i];
        tree[n].point[A[s]] = B[s], tree[n].end[tree[n].point[1]] = 1;
    } else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int a, int b) {
    if (x < s || e < x)
        return;
    else if (s == e) {
        tree[n].end[tree[n].point[a]] -= a == 1;
        tree[n].point[a] = b;
        tree[n].end[tree[n].point[a]] += a == 1;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, a, b), update(n << 1 | 1, m + 1, e, x, a, b);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, Q, X, Y, Z, ans;

    cin >> N >> K;

    for (int i = 1; i < N; i++)
        for (int j = 1; j <= K; j++)
            cin >> C[i][j];

    for (int i = 1; i < N; i++)
        cin >> A[i] >> B[i];

    init(1, 1, N);

    cin >> Q;
    while (Q--) {
        cin >> X >> Y >> Z;

        update(1, 1, N, X, A[X], A[X]);
        A[X] = Y, B[X] = Z;
        update(1, 1, N, X, A[X], B[X]);

        ans = tree[1].res;
        cout << ans << '\n';
    }

    return 0;
}