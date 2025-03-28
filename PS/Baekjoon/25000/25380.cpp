#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, X, Y, Z, ans = 0;
    vector<int> A, B, PX, PY, arr;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
        cin >> X, A.push_back(X);
    for (int i = 0; i < M; i++)
        cin >> X, B.push_back(X);

    A.push_back(-INF), A.push_back(INF), B.push_back(-INF), B.push_back(INF), N += 2, M += 2;
    sort(A.begin(), A.end()), sort(B.begin(), B.end());

    for (int i = 0; i < K; i++) {
        cin >> X >> Y;
        PX.push_back(X), PY.push_back(Y);
    }

    sort(PX.begin(), PX.end()), sort(PY.begin(), PY.end());

    for (int i = 0; i < K - 1; i++) {
        ans += (PX[i + 1] - PX[i]) * (i + 1) * (K - i - 1);
        ans += (PY[i + 1] - PY[i]) * (i + 1) * (K - i - 1);
    }

    X = -1;
    for (int i = 0; i + 1 < N; i++) {
        while (X + 1 < PX.size() && PX[X + 1] < A[i + 1])
            arr.push_back(PX[++X]);
        while (X + 1 < PX.size() && PX[X + 1] == A[i + 1])
            X++;
        Y = 0, Z = arr.size() - 1;
        while (Y <= Z) {
            if (arr[Y] - A[i] < A[i + 1] - arr[Z])
                ans += (arr[Y] - A[i]) * (Z - Y) * 2, Y++;
            else
                ans += (A[i + 1] - arr[Z]) * (Z - Y) * 2, Z--;
        }
        arr.clear();
    }

    X = -1;
    for (int i = 0; i + 1 < M; i++) {
        while (X + 1 < PY.size() && PY[X + 1] < B[i + 1])
            arr.push_back(PY[++X]);
        while (X + 1 < PY.size() && PY[X + 1] == B[i + 1])
            X++;
        Y = 0, Z = arr.size() - 1;
        while (Y <= Z) {
            if (arr[Y] - B[i] < B[i + 1] - arr[Z])
                ans += (arr[Y] - B[i]) * (Z - Y) * 2, Y++;
            else
                ans += (B[i + 1] - arr[Z]) * (Z - Y) * 2, Z--;
        }
        arr.clear();
    }

    cout << ans << '\n';

    return 0;
}