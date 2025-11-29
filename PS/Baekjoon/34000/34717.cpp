#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 500001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], S[MAX];
vector<tp> hull[MAX << 2];

int ceil_div(int A, int B) {
    if (B < 0)
        A = -A, B = -B;
    return (A + B - 1) / B;
}

void init(int n, int s, int e) {
    tp K;

    for (int i = e; i >= s; i--) {
        K = {0, i, -S[i - 1]};
        while (!hull[n].empty()) {
            K[0] = ceil_div(hull[n].back()[2] - K[2], K[1] - hull[n].back()[1]);
            if (hull[n].back()[0] <= K[0])
                break;
            hull[n].pop_back();
        }
        hull[n].push_back(K);
    }

    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
    }
}

int query(int n, int s, int e, int l, int r, int x) {
    tp K;

    if (r < s || e < l)
        return INF;
    else if (l <= s && e <= r) {
        K = *prev(lower_bound(hull[n].begin(), hull[n].end(), tp{x + 1, -INF, -INF}));
        return K[1] * x + K[2];
    } else {
        int m = s + e >> 1;
        return min(query(n << 1, s, m, l, r, x), query(n << 1 | 1, m + 1, e, l, r, x));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, X;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[i] = S[i - 1] + A[i];

    init(1, 1, N);

    while (Q--) {
        cin >> L >> R >> X;
        cout << max(0ll, A[X] * (X + 1) - S[X] - query(1, 1, N, L, R, A[X])) << '\n';
    }

    return 0;
}