#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int X[MAX], Y[MAX], A[MAX], B[MAX], ans[MAX], tree[MAX * 4];
bool chk[MAX];
vector<int> val[MAX];

void init(int n, int s, int e) {
    tree[n] = -INF;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return -INF;
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
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    vector<int> arr;
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pr V;
    bool ans_b = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i] >> A[i] >> B[i], arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] < X[y]; }), init(1, 1, N);
    for (int i : arr) {
        A[i] = max(A[i], query(1, 1, N, 1, Y[i] - 1) + 1);
        update(1, 1, N, Y[i], A[i]);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return X[x] > X[y]; }), init(1, 1, N);
    for (int i : arr) {
        B[i] = min(B[i], -query(1, 1, N, Y[i] + 1, N) - 1);
        update(1, 1, N, Y[i], -B[i]);
    }

    for (int i = 1; i <= N; i++)
        val[A[i]].push_back(i);

    for (int i = 1; i <= N; i++) {
        for (int j : val[i])
            pq.push({B[j], j});
        ans_b &= !pq.empty();
        if (!pq.empty()) {
            V = pq.top(), pq.pop();
            ans_b &= i <= V[0], ans[V[1]] = i;
        }
    }

    cout << (ans_b ? "YES" : "NO") << '\n';
    if (ans_b) {
        for (int i = 1; i <= N; i++)
            cout << ans[i] << ' ';
        cout << '\n';
    }
}
