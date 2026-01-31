#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;
typedef array<tp, 5> cand;

const int MAX_N = 2001;
const int MAX_M = 4001;
const int MAX_L = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int l = 0, r = 0;
    cand val;

    Node() {
        for (int i = 0; i < 5; i++)
            val[i] = {INF, -1, -1};
    }
};

int A[MAX_M], B[MAX_M], C[MAX_M], D[MAX_M][MAX_M],
    CL[MAX_M], CR[MAX_M],
    X[MAX_L];
Node tree[MAX_L * 4];
cand R[MAX_N][MAX_N];
bool chk[MAX_M][MAX_M];

vector<int> adj[MAX_N];
vector<tp> arr;

Node merge(Node X, Node Y) {
    Node res = Node();
    int U = 0;

    res.l = X.l, res.r = Y.r;
    for (int i = 0; i < 5 && X.val[i][0] < INF; i++)
        for (int j = 0; j < 5 && Y.val[j][0] < INF; j++)
            for (int k = 0; k < 5 && R[X.r][Y.l][k][0] < INF; k++) {
                if ((R[X.r][Y.l][k][1] ^ 1) == X.val[i][2] || (R[X.r][Y.l][k][2] ^ 1) == Y.val[j][1])
                    continue;
                arr.push_back({X.val[i][0] + Y.val[j][0] + R[X.r][Y.l][k][0],
                               X.val[i][1] != -1 ? X.val[i][1] : R[X.r][Y.l][k][1],
                               Y.val[j][2] != -1 ? Y.val[j][2] : R[X.r][Y.l][k][2]});
            }

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        if (CL[i[1]] > 1 || CR[i[2]] > 1 || chk[i[1]][i[2]] || U >= 5)
            continue;
        CL[i[1]]++, CR[i[2]]++, res.val[U++] = i, chk[i[1]][i[2]] = true;
    }
    for (tp i : arr)
        CL[i[1]] = CR[i[2]] = 0, chk[i[1]][i[2]] = false;
    arr.clear();

    return res;
}

void init(int n, int s, int e) {
    if (s == e) {
        tree[n] = Node(), tree[n].val[0][0] = 0;
        tree[n].l = tree[n].r = X[s];
    } else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n].l = tree[n].r = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, L, U, V, W, ans;

    cin >> N >> M >> Q >> L, arr.reserve((M << 1) * (M << 1));
    for (int i = 0; i < M; i++) {
        cin >> U >> V >> W;
        A[i << 1] = U, B[i << 1] = V, C[i << 1] = W, adj[U].push_back(i << 1);
        A[i << 1 | 1] = V, B[i << 1 | 1] = U, C[i << 1 | 1] = W, adj[V].push_back(i << 1 | 1);
    }

    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr K;

    for (int i = 0; i < (M << 1); i++) {
        for (int j = 0; j < (M << 1); j++)
            D[i][j] = INF;

        D[i][i ^ 1] = C[i], pq.push({C[i], i ^ 1});
        while (!pq.empty()) {
            K = pq.top(), pq.pop();
            if (D[i][K[1]] != K[0])
                continue;
            for (int j : adj[A[K[1]]]) {
                W = K[0] + C[j];
                if (W < D[i][j ^ 1] && j != K[1])
                    D[i][j ^ 1] = W, pq.push({W, j ^ 1});
            }
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            for (int x : adj[i])
                for (int y : adj[j])
                    arr.push_back({D[x][y], x, (y ^ 1)});
            sort(arr.begin(), arr.end()), U = 0;
            for (int x = 0; x < 5; x++)
                R[i][j][x] = {INF, -1, -1};
            for (tp x : arr) {
                if (CL[x[1]] > 1 || CR[x[2]] > 1 || chk[x[1]][x[2]] || U >= 5)
                    continue;
                CL[x[1]]++, CR[x[2]]++, R[i][j][U++] = x, chk[x[1]][x[2]] = true;
            }
            for (tp x : arr)
                CL[x[1]] = CR[x[2]] = 0, chk[x[1]][x[2]] = false;
            arr.clear();
        }

    for (int i = 1; i <= L; i++)
        cin >> X[i];
    init(1, 1, L);

    while (Q--) {
        cin >> U >> V, update(1, 1, L, U, V);
        ans = tree[1].val[0][0];
        cout << (ans == INF ? -1 : ans) << '\n';
    }
}