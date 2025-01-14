#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 2> pr;

int A[MAX][2], B[MAX][2], ans = 0;

void dnc_opt(int l, int r, int s, int e) {
    if (l > r)
        return;
    int mid = l + r >> 1, opt = -1, res = -INF, val;

    for (int i = s; i <= e; i++) {
        if (A[i][0] >= B[mid][0] && A[i][1] >= B[mid][1])
            continue;
        val = (B[mid][0] - A[i][0]) * (B[mid][1] - A[i][1]);
        if (res <= val)
            res = val, opt = i;
    }
    ans = max(ans, res);

    dnc_opt(l, mid - 1, s, opt), dnc_opt(mid + 1, r, opt, e);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N, X, Y;
    vector<pr> temp;

    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        temp.push_back({X, Y});
    }

    sort(temp.begin(), temp.end()), X = 0;
    for (pr i : temp) {
        if (X && A[X][1] <= i[1])
            continue;
        A[++X][0] = i[0], A[X][1] = i[1];
    }
    temp.clear(), M = X;

    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        temp.push_back({X, Y});
    }

    sort(temp.begin(), temp.end()), X = 0;
    for (pr i : temp) {
        while (X && B[X][1] <= i[1])
            --X;
        B[++X][0] = i[0], B[X][1] = i[1];
    }
    temp.clear(), N = X;

    dnc_opt(1, N, 1, M);
    cout << ans << '\n';

    return 0;
}