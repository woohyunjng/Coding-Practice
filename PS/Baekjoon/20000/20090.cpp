#include <bits/stdc++.h>
#define int long long

const int MAX = 500001;

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> ftp;

int dp[MAX][2], X[MAX], Y[MAX];

int sq(int V) { return V * V; }

int take_photos(signed N, signed M, signed K, vector<signed> R, vector<signed> C) {
    vector<pr> arr, stck;

    for (int i = 0; i < N; i++) {
        if (R[i] > C[i])
            swap(R[i], C[i]);
        arr.push_back({R[i], C[i]});
    }

    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        while (!stck.empty() && stck.back()[0] == i[0])
            stck.pop_back();
        if (stck.empty() || stck.back()[1] < i[1])
            stck.push_back(i);
    }
    arr = stck, stck.clear(), N = arr.size();

    for (int i = 0; i < N; i++)
        X[i + 1] = arr[i][0], Y[i + 1] = arr[i][1];

    int st = 0, en = 4e12, md, ans = 0, P;
    vector<ftp> F;
    ftp fnc;

    while (st <= en) {
        md = st + en >> 1, F.clear(), P = 0;
        F.push_back({-2 * X[1] + 2, sq(X[1] - 1), 0, 0});

        for (int i = 1; i <= N; i++) {
            while (P + 1 < F.size() && F[P + 1][2] < Y[i])
                P++;
            dp[i][0] = F[P][0] * Y[i] + F[P][1] + sq(Y[i]) + md, dp[i][1] = F[P][3] + 1;

            if (i == N)
                break;

            fnc = {-2 * X[i + 1] + 2, sq(X[i + 1] - 1) - sq(max(0ll, Y[i] - X[i + 1] + 1)) + dp[i][0], 0, dp[i][1]};
            while (!F.empty()) {
                fnc[2] = (F.back()[1] - fnc[1]) / (fnc[0] - F.back()[0]);
                if (F.back()[2] < fnc[2])
                    break;
                F.pop_back();
                if (F.size() == P)
                    --P;
            }
            F.push_back(fnc);
        }

        ans = max(ans, dp[N][0] - md * K);
        if (dp[N][1] <= K)
            en = md - 1;
        else
            st = md + 1;
    }

    return ans;
}
