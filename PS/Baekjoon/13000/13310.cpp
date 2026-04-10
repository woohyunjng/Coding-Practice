#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 30001;

int N, X[MAX], Y[MAX], DX[MAX], DY[MAX];
map<int, int> dp;

int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

int CCCW(pr A, pr B, pr C, pr D) {
    pr tmp = D;
    D[0] -= (C[0] - B[0]), D[1] -= (C[1] - B[1]);
    return CCW(A, B, D);
}

int dis(pr A, pr B) { return (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1]); }

int calc(int K) {
    if (dp.find(K) != dp.end())
        return dp[K];

    vector<pr> arr, upper, lower, hull;

    for (int i = 1; i <= N; i++)
        arr.push_back({X[i] + DX[i] * K, Y[i] + DY[i] * K});
    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        while (upper.size() >= 2 && CCW(upper[(int)upper.size() - 2], upper[(int)upper.size() - 1], i) >= 0)
            upper.pop_back();
        upper.push_back(i);
    }

    reverse(arr.begin(), arr.end());
    for (pr i : arr) {
        while (lower.size() >= 2 && CCW(lower[(int)lower.size() - 2], lower[(int)lower.size() - 1], i) >= 0)
            lower.pop_back();
        lower.push_back(i);
    }

    hull = upper;
    for (int i = 1; i + 1 < lower.size(); i++)
        hull.push_back(lower[i]);

    int V = hull.size(), P = 1, res = 0;
    for (int i = 0; i < V; i++) {
        while (P + 1 != i && CCCW(hull[i], hull[(i + 1) % V], hull[P % V], hull[(P + 1) % V]) < 0)
            res = max(res, dis(hull[i], hull[P % V])), P++;
        res = max(res, dis(hull[i], hull[P % V]));
    }

    return dp[K] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, ans = -1, st, en, fl, sl;

    cin >> N >> T, dp[-1] = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i] >> DX[i] >> DY[i];

    for (st = 0, en = T; en - st > 2;) {
        fl = st + (en - st) / 3, sl = en - (en - st) / 3;
        if (calc(fl) <= calc(sl))
            en = sl;
        else
            st = fl;
    }
    for (int i = st; i <= en; i++)
        if (calc(ans) > calc(i))
            ans = i;

    cout << ans << '\n'
         << calc(ans) << '\n';

    return 0;
}