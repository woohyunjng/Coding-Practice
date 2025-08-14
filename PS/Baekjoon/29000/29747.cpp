#include "soccer.h"

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;
typedef array<int, 4> tp;

const int MAX = 2002;
const int STATE = MAX * MAX;

int F[MAX][MAX], S[MAX][MAX], V[MAX], dp[STATE];
unordered_map<int, int> mp;

int val(int A, int B, int C, int D) { return A + B * MAX + C * MAX * MAX + D * MAX * MAX * MAX; }

int biggest_stadium(int N, vector<vector<int>> _F) {
    vector<pr> st;
    vector<tp> arr;

    arr.reserve(N + 1);

    int X, Y, Z, L, R, SZ, K = 0, ans = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            F[i][j] = _F[i - 1][j - 1], S[i][j] = F[i][j] + S[i][j - 1] + S[i - 1][j] - S[i - 1][j - 1];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            if (F[i][j])
                V[j] = i;
        V[0] = V[N + 1] = i, arr.clear();

        for (int j = 1; j <= N + 1; j++) {
            X = i - V[j], Y = j;
            while (!st.empty() && st.back()[0] > X) {
                Y = st.back()[1], arr.push_back({st.back()[1], j - 1, i - st.back()[0] + 1, i});
                st.pop_back();
            }
            if (X > 0)
                st.push_back({X, Y});
        }

        sort(arr.begin(), arr.end(), [&](tp x, tp y) { return x[1] - x[0] > y[1] - y[0]; });

        for (tp j : arr) {
            mp[val(j[0], j[1], j[2], j[3])] = K, dp[K] = SZ = (j[1] - j[0] + 1) * (j[3] - j[2] + 1);

            if (j[2] < j[3]) {
                X = j[2], L = j[0], R = j[1];
                for (int l = R, r = N, m; l <= r;) {
                    m = l + r >> 1;
                    if ((S[j[3] - 1][m] - S[j[3] - 1][L - 1] - S[X - 1][m] + S[X - 1][L - 1]) > 0)
                        r = m - 1;
                    else
                        l = m + 1, R = m;
                }

                for (int l = 1, r = L, m; l <= r;) {
                    m = l + r >> 1;
                    if ((S[j[3] - 1][L] - S[j[3] - 1][m - 1] - S[X - 1][L] + S[X - 1][m - 1]) > 0)
                        l = m + 1;
                    else
                        r = m - 1, L = m;
                }

                Y = mp[val(L, R, X, j[3] - 1)];
                dp[K] = max(dp[K], dp[Y] + SZ - (j[1] - j[0] + 1) * (j[3] - 1 - X + 1));
            }

            L = j[0], R = j[1], X = min(V[L - 1] + 1, V[R + 1] + 1);
            if (X <= j[3]) {
                for (int l = R, r = N, m; l <= r;) {
                    m = l + r >> 1;
                    if ((S[j[3]][m] - S[j[3]][L - 1] - S[X - 1][m] + S[X - 1][L - 1]) > 0)
                        r = m - 1;
                    else
                        l = m + 1, R = m;
                }

                for (int l = 1, r = L, m; l <= r;) {
                    m = l + r >> 1;
                    if ((S[j[3]][L] - S[j[3]][m - 1] - S[X - 1][L] + S[X - 1][m - 1]) > 0)
                        l = m + 1;
                    else
                        r = m - 1, L = m;
                }

                Y = mp[val(L, R, X, j[3])];
                dp[K] = max(dp[K], dp[Y] + SZ - (j[1] - j[0] + 1) * (j[3] - X + 1));
            }

            ans = max(ans, dp[K++]);
        }
    }

    return ans;
}
