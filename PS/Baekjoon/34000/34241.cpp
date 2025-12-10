#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int INF = 1'000'000'000'000'000;
const int VAL = 60;

int dp[MAX][VAL], P[MAX], T[MAX], S[MAX];

vector<signed> max_coupons(signed _A, vector<signed> _P, vector<signed> _T) {
    vector<signed> arr, ans, val, one;
    int N = _P.size(), X = 0, Y, Z, PS = 0, A = _A;

    for (int i = 0; i < N; i++) {
        P[i] = _P[i], T[i] = _T[i];
        if (T[i] == 1)
            one.push_back(i);
        else
            arr.push_back(i);
    }
    N = arr.size();

    sort(arr.begin(), arr.end(), [&](int x, int y) { return (-P[x] * T[x] * T[y] - P[y] * T[y]) > (-P[y] * T[y] * T[x] - P[x] * T[x]); });
    sort(one.begin(), one.end(), [&](int x, int y) { return P[x] < P[y]; });

    for (int i = 1; i <= one.size(); i++)
        S[i] = S[i - 1] + P[one[i - 1]];

    for (int i : arr) {
        if ((A - P[i]) * T[i] >= A)
            A = (A - P[i]) * T[i], X++;
        else
            break;

        if (A >= INF) {
            for (int j : arr)
                ans.push_back(j);
            for (int j : one)
                ans.push_back(j);
            return ans;
        }
    }
    for (int i = 0; i <= N; i++)
        fill(dp[i], dp[i] + VAL, -1);

    dp[X][0] = A;
    for (int i = X; i < N; i++) {
        dp[i + 1][0] = dp[i][0];
        for (int j = 1; j < VAL; j++)
            dp[i + 1][j] = max(dp[i][j], (dp[i][j - 1] - P[arr[i]]) * T[arr[i]]);
    }

    Y = -1, Z = -1;
    for (int i = VAL - 1; i >= 0; i--) {
        if (dp[N][i] < 0)
            continue;

        while (PS + 1 <= one.size() && S[PS + 1] <= dp[N][i])
            PS++;
        if (i + PS > Z)
            Z = i + PS, Y = i;
    }

    Z -= Y;
    for (int j = N - 1; j >= X; j--) {
        if (!(Y > 0 && dp[j + 1][Y] == (dp[j][Y - 1] - P[arr[j]]) * T[arr[j]]))
            continue;
        val.push_back(j), Y--;
    }

    for (int j = 0; j < Z; j++)
        ans.push_back(one[j]);
    for (int j : val)
        ans.push_back(arr[j]);
    for (int i = X - 1; i >= 0; i--)
        ans.push_back(arr[i]);
    reverse(ans.begin(), ans.end());

    return ans;
}

signed main() {
    signed N, A;
    assert(2 == scanf("%d %d", &N, &A));
    std::vector<signed> P(N), T(N);
    for (signed i = 0; i < N; i++)
        assert(2 == scanf("%d %d", &P[i], &T[i]));
    fclose(stdin);

    std::vector<signed> R = max_coupons(A, P, T);

    signed S = R.size();
    printf("%d\n", S);
    for (signed i = 0; i < S; i++)
        printf("%s%d", (i == 0 ? "" : " "), R[i]);
    printf("\n");
    fclose(stdout);

    return 0;
}
