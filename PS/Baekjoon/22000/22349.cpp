#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

const int MAX = 2000003;

int A[MAX], sa[MAX], lcp[MAX],
    cnt[MAX], tmp_sa[MAX],
    group[MAX], nxt[MAX], rnk[MAX],
    S[MAX];
vector<int> arr[MAX * 2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, K, X, Y, V, L, ans, C[2];
    string _A, _B;

    cin >> T;
    while (T--) {
        cin >> _A >> _B, ans = 0;
        N = _A.size(), M = _B.size(), K = N + M + 1;

        for (int i = 1; i <= N; i++)
            A[i] = _A[i - 1] == '(' ? 0 : 1;
        A[N + 1] = 2;
        for (int i = 1; i <= M; i++)
            A[N + 1 + i] = _B[i - 1] == '(' ? 0 : 1;

        fill(group, group + K + 2, 0), fill(nxt, nxt + K + 2, 0), fill(rnk, rnk + K + 2, 0);

        for (int i = -K - 1; i <= K; i++)
            arr[i + K + 1].clear();

        X = 1;
        for (int i = 1; i <= K; i++)
            sa[i] = i, group[i] = A[i];

        while (X <= K) {
            fill(cnt, cnt + K + 2, 0);
            for (int i = 1; i <= K; i++)
                cnt[(sa[i] + X > K ? -1 : group[sa[i] + X]) + 1]++;
            for (int i = 1; i <= K + 1; i++)
                cnt[i] += cnt[i - 1];
            for (int i = K; i >= 1; i--)
                tmp_sa[cnt[(sa[i] + X > K ? -1 : group[sa[i] + X]) + 1]--] = sa[i];

            fill(cnt, cnt + K + 2, 0);
            for (int i = 1; i <= K; i++)
                cnt[group[tmp_sa[i]] + 1]++;
            for (int i = 1; i <= K + 1; i++)
                cnt[i] += cnt[i - 1];
            for (int i = K; i >= 1; i--)
                sa[cnt[group[tmp_sa[i]] + 1]--] = tmp_sa[i];

            for (int i = 2; i <= K; i++)
                nxt[sa[i]] = nxt[sa[i - 1]] + (group[sa[i - 1]] == group[sa[i]] ? (sa[i - 1] + X > K ? -1 : group[sa[i - 1] + X]) < (sa[i] + X > K ? -1 : group[sa[i] + X]) : group[sa[i - 1]] < group[sa[i]]);
            for (int i = 1; i <= K; i++)
                group[i] = nxt[i];
            X <<= 1;
        }

        arr[0 + K + 1].push_back(0);
        for (int i = 1; i <= K; i++) {
            rnk[sa[i]] = i, S[i] = S[i - 1] + (A[i] == 2 ? 0 : (A[i] == 0 ? 1 : -1));
            arr[S[i] + K + 1].push_back(i);
        }
        for (int i = -K - 1; i <= K; i++)
            arr[i + K + 1].push_back(K + 1);

        X = 0;
        for (int i = 1; i <= K; i++) {
            Y = rnk[i];
            if (Y == 1)
                continue;
            while (max(i, sa[Y - 1]) + X <= K && A[i + X] == A[sa[Y - 1] + X])
                X++;
            lcp[Y] = X, X = max(0ll, X - 1);
        }

        C[0] = C[1] = 0;
        X = Y = 0;
        C[sa[1] > N] = K - sa[1] + 1;
        if (sa[1] <= N)
            X = sa[1];
        else
            Y = sa[1];

        for (int i = 2; i <= K; i++) {
            if (sa[i] <= N)
                C[0] = K - sa[i] + 1, C[1] = min(C[1], lcp[i]), X = sa[i];
            else
                C[1] = K - sa[i] + 1, C[0] = min(C[0], lcp[i]), Y = sa[i];

            if (X == 0 || Y == 0)
                continue;

            V = min({N, (*lower_bound(arr[S[X - 1] - 1 + K + 1].begin(), arr[S[X - 1] - 1 + K + 1].end(), X)) - 1, X + min(C[0], C[1]) - 1});
            if (V < X)
                continue;
            L = *prev(upper_bound(arr[S[X - 1] + K + 1].begin(), arr[S[X - 1] + K + 1].end(), V));
            ans = max(ans, L - X + 1);
        }

        cout << ans << '\n';
    }

    return 0;
}