#include <bits/stdc++.h>
#define int long long

#define MAX 41
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX][2], dp[MAX][MAX][MAX][MAX];

int area(int A, int B, int C) { return abs(P[A][0] * P[B][1] + P[B][0] * P[C][1] + P[C][0] * P[A][1] - P[A][1] * P[B][0] - P[B][1] * P[C][0] - P[C][1] * P[A][0]); }

int CCW(int A, int B, int C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (P[B][0] - P[A][0]) * (P[C][1] - P[A][1]) - (P[C][0] - P[A][0]) * (P[B][1] - P[A][1]);
    return val > 0 ? 1 : val < 0 ? -1
                                 : 0;
}

tp trorder(int A, int B, int C) { return {min({A, B, C}), A + B + C - max({A, B, C}) - min({A, B, C}), max({A, B, C})}; }

bool inside(int A, int B, int C, int K) { return CCW(A, B, K) == CCW(B, C, K) && CCW(B, C, K) == CCW(C, A, K); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, X;
    bool flag;
    tp K;
    vector<tp> arr;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i][0] >> P[i][1];

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            for (int k = j + 1; k <= N; k++)
                arr.push_back({i, j, k});

    sort(arr.begin(), arr.end(), [&](tp a, tp b) { return area(a[0], a[1], a[2]) < area(b[0], b[1], b[2]); });

    for (tp i : arr) {
        for (int j = 0; j <= N - 3; j++) {
            if (j == 0)
                dp[i[0]][i[1]][i[2]][j] = 6;
            X = 0;
            for (int k = 1; k <= N; k++) {
                if (k == i[0] || k == i[1] || k == i[2])
                    continue;
                if (inside(i[0], i[1], i[2], k))
                    X++;
                if (inside(k, i[0], i[1], i[2])) {
                    K = trorder(k, i[0], i[1]);
                    dp[K[0]][K[1]][K[2]][j + 1] = (dp[K[0]][K[1]][K[2]][j + 1] + dp[i[0]][i[1]][i[2]][j]) % MOD;
                }
                if (inside(k, i[1], i[2], i[0])) {
                    K = trorder(k, i[1], i[2]);
                    dp[K[0]][K[1]][K[2]][j + 1] = (dp[K[0]][K[1]][K[2]][j + 1] + dp[i[0]][i[1]][i[2]][j]) % MOD;
                }
                if (inside(k, i[2], i[0], i[1])) {
                    K = trorder(k, i[2], i[0]);
                    dp[K[0]][K[1]][K[2]][j + 1] = (dp[K[0]][K[1]][K[2]][j + 1] + dp[i[0]][i[1]][i[2]][j]) % MOD;
                }
            }

            dp[i[0]][i[1]][i[2]][j + 1] = (dp[i[0]][i[1]][i[2]][j + 1] + (X - j) * dp[i[0]][i[1]][i[2]][j]) % MOD;
        }
    }

    for (tp i : arr) {
        flag = true;
        for (int j = 1; j <= N; j++) {
            if (j == i[0] || j == i[1] || j == i[2])
                continue;
            flag = flag && inside(i[0], i[1], i[2], j);
        }
        if (flag)
            res = dp[i[0]][i[1]][i[2]][N - 3];
    }

    cout << res << '\n';

    return 0;
}