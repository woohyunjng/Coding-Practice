#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 10001;

int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

pr P[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, PX, PY, ans;
    pr X, Y, A, B;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> P[i][0] >> P[i][1];

    for (int i = 0; i < 3; i++) {
        cin >> PX >> PY, ans = 0;

        for (int j = 0; j < N; j++) {
            X = P[j], Y = P[(j + 1) % N];
            if (X[1] < Y[1])
                swap(X, Y);
            A = {PX - X[0], PY - X[1]}, B = {Y[0] - PX, Y[1] - PY};

            if (CCW(X, {PX, PY}, Y) == 0) {
                if (min(X[0], Y[0]) <= PX && PX <= max(X[0], Y[0]) && min(X[1], Y[1]) <= PY && PY <= max(X[1], Y[1])) {
                    ans = 1;
                    break;
                }
            }

            if (max(X[0], Y[0]) < PX || X[1] <= PY || Y[1] > PY)
                continue;
            if (min(X[0], Y[0]) > PX || CCW(X, {PX, PY}, Y) > 0)
                ans++;
        }

        cout << ans % 2 << '\n';
    }

    return 0;
}