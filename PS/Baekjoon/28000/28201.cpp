#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int A[MAX], C[MAX];
vector<pr> dp[MAX * 2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, M, X, Y, Z, L, R, ans = 0;
    vector<pr> tmp[2];

    cin >> N >> S, M = max(N, S);
    for (int i = 1; i <= N; i++)
        cin >> A[i], C[A[i]]++;

    for (int i = 0; i <= C[0]; i++)
        dp[-i + M].push_back({0, C[1]});

    for (int i = 2; i <= S; i++) {
        while (C[i]) {
            X = C[i] - (C[i] >> 1);
            Y = X * (i - 1), Z = X * i;
            for (int j = M - Y; j >= -M; j--) {
                if (dp[j + M].empty())
                    continue;
                tmp[0].clear(), tmp[1].clear();
                tmp[0].resize(dp[j + M].size()), copy(dp[j + M].begin(), dp[j + M].end(), tmp[0].begin());
                for (pr &k : tmp[0])
                    k[0] += Z, k[1] += Z;
                tmp[1].resize(dp[j + Y + M].size() + tmp[0].size());
                merge(tmp[0].begin(), tmp[0].end(), dp[j + Y + M].begin(), dp[j + Y + M].end(), tmp[1].begin());
                dp[j + Y + M].clear();

                L = R = -1;
                for (pr k : tmp[1]) {
                    if (L == -1)
                        L = k[0], R = k[1];
                    else if (k[0] > R + 1) {
                        dp[j + Y + M].push_back({L, R});
                        L = k[0], R = k[1];
                    } else
                        R = max(R, k[1]);
                }
                if (L != -1)
                    dp[j + Y + M].push_back({L, R});
            }
            C[i] >>= 1;
        }
    }

    for (int i = -M; i <= M; i++)
        for (pr j : dp[i + M])
            ans += j[1] - j[0] + 1;
    cout << ans << '\n';

    return 0;
}