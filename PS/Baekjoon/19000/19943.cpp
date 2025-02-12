#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef __int128_t ll;
typedef array<ll, 2> pr;
typedef array<ll, 3> tp;

const int MAX = 200000;
const int INF = 0x3f3f3f3f3f3f3f3f;

ll P[MAX], H[MAX], dp[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y;
    tp K;

    vector<pr> arr, st;
    vector<tp> F;

    cin >> T;
    while (T--) {
        cin >> N, st.clear(), arr.clear();
        while (N--)
            cin >> X >> Y, st.push_back({X, Y});

        for (pr i : st) {
            while (!arr.empty() && arr.back()[1] - arr.back()[0] <= i[1] - i[0])
                arr.pop_back();
            if (arr.empty() || arr.back()[0] + arr.back()[1] < i[0] + i[1])
                arr.push_back(i);
        }

        N = arr.size();
        for (int i = 1; i <= N; i++)
            P[i] = arr[i - 1][0], H[i] = arr[i - 1][1];

        dp[0] = 0, F.clear(), X = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = (P[i] + H[i]) * (P[i] + H[i]);
            K = {2 * (H[i] - P[i]), (H[i] - P[i]) * (H[i] - P[i]) + dp[i - 1], 0};

            while (!F.empty()) {
                K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
                if (K[2] > F.back()[2])
                    break;
                F.pop_back();
                if (F.size() == X)
                    X--;
            }
            F.push_back(K);

            Y = (ll)P[i] + H[i];
            while (X + 1 < F.size() && F[X + 1][2] < Y)
                X++;
            dp[i] += F[X][0] * (ll)Y + F[X][1];
        }

        cout << fixed << setprecision(2) << ((long double)dp[N] / 4) << '\n';
    }

    return 0;
}