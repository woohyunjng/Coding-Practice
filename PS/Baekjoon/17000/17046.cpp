#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;
typedef array<double, 4> ftp;

const int MAX = 300000;
const double CONST = 100000;

double dp[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    double ans, Y, st, en, md;

    ftp V;
    vector<ftp> F;

    cin >> N >> K;

    st = 0, en = ans = N * CONST;
    while (en - st > 0.00001) {
        md = (st + en) / 2, F.clear(), F.push_back({0, 0, MAX, 0}), X = 0;

        for (int i = 1; i <= N; i++) {
            Y = CONST / i;
            while (X + 1 < F.size() && F[X + 1][2] >= Y)
                X++;
            dp[i][0] = F[X][0] * Y + F[X][1] + CONST - md, dp[i][1] = F[X][3] + 1;
            V = {-(double)i, dp[i][0], 0, dp[i][1]};
            while (!F.empty()) {
                V[2] = (F.back()[1] - V[1]) / (V[0] - F.back()[0]);
                if (F.back()[2] > V[2])
                    break;
                F.pop_back();
                if (F.size() == X)
                    --X;
            }
            F.push_back(V);
        }

        ans = min(ans, dp[N][0] + md * K);
        if (dp[N][1] <= K)
            en = md;
        else
            st = md;
    }

    cout << fixed << setprecision(10) << (double)ans / CONST << '\n';

    return 0;
}