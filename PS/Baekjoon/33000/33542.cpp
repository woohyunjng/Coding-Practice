#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 600000;
const int INF = 0x3f3f3f3f3f3f3f3f;

typedef array<int, 2> pr;

int L[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, N, X, Y, ansL = -1, ansR = -1, ans = INF;
    vector<pr> L, R;

    cin >> A >> B >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y;
        L.push_back({X, i}), R.push_back({Y, i});
    }

    if (B > A) {
        cout << -1 << ' ' << -1 << '\n';
        return 0;
    }

    sort(L.begin(), L.end()), sort(R.begin(), R.end());

    for (pr i : L) {
        if (B + i[0] > A && B + i[0] - A < ans)
            ans = B + i[0] - A, ansL = i[1], ansR = -1;
    }

    for (pr i : R) {
        if (B + i[0] > A && B + i[0] - A < ans)
            ans = B + i[0] - A, ansL = -1, ansR = i[1];
    }

    for (pr i : L) {
        X = lower_bound(R.begin(), R.end(), (pr){A - B - i[0] + 1, 0}) - R.begin();
        if (X == N)
            continue;
        if (R[X][1] == i[1]) {
            if (X + 1 == N)
                continue;
            X += 1;
        }
        if (B + i[0] + R[X][0] - A < ans)
            ans = B + i[0] + R[X][0] - A, ansL = i[1], ansR = R[X][1];
    }

    if (ans == INF) {
        cout << "No" << '\n';
        return 0;
    }

    cout << ansL << ' ' << ansR << '\n';

    return 0;
}