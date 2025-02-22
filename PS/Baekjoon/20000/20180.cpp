#include <bits/stdc++.h>
#define int long long

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1500000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX][2], B[MAX][2], X[MAX], ans = 0;

void dnc(int l, int r, int s, int e) {
    if (l > r)
        return;
    int m = l + r >> 1, opt = s, res = -INF;
    for (int i = s; i <= e; i++) {
        if (A[i][0] >= B[m][0] && A[i][1] >= B[m][1])
            continue;
        if (res <= (B[m][0] - A[i][0]) * (B[m][1] - A[i][1]))
            opt = i, res = (B[m][0] - A[i][0]) * (B[m][1] - A[i][1]);
    }
    ans = max(ans, res);
    dnc(l, m - 1, s, opt), dnc(m + 1, r, opt, e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    vector<pr> arr;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i];

    K = 0;
    for (int i = 1; i <= N; i++) {
        arr.push_back({i, -X[i]});
        if (K && A[K][1] <= -X[i])
            continue;
        A[++K][0] = i, A[K][1] = -X[i];
    }
    M = K, K = 0;

    for (int i = 1; i <= N; i++) {
        while (K && B[K][1] <= X[i])
            --K;
        B[++K][0] = i, B[K][1] = X[i];
    }
    N = K;

    dnc(1, N, 1, M);
    cout << ans << '\n';

    return 0;
}