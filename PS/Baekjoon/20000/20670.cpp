#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

bool chk(vector<pr> &hull, pr P) {
    int st = 2, en = (int)hull.size() - 1, md;

    if (hull.size() == 2)
        return !CCW(hull[0], P, hull[1]) && min(hull[0][0], hull[1][0]) <= P[0] && P[0] <= max(hull[0][0], hull[1][0]) && min(hull[0][1], hull[1][1]) <= P[1] && P[1] <= max(hull[0][1], hull[1][1]);

    while (st < en) {
        md = st + en >> 1;
        if (CCW(hull[0], hull[md], P) < 0)
            en = md;
        else
            st = md + 1;
    }

    return CCW(hull[0], hull[st - 1], P) >= 0 && CCW(hull[st - 1], hull[st], P) >= 0 && CCW(hull[st], hull[0], P) >= 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, ans = 0;
    vector<pr> A, B;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> X >> Y, A.push_back({X, Y});
    for (int i = 0; i < M; i++)
        cin >> X >> Y, B.push_back({X, Y});

    for (int i = 0; i < K; i++) {
        cin >> X >> Y;
        if (chk(A, {X, Y}) && !chk(B, {X, Y}))
            ans++;
    }

    if (ans == K)
        cout << "YES" << '\n';
    else
        cout << K - ans << '\n';

    return 0;
}