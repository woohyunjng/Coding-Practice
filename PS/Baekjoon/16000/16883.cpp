#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;

int A[2][MAX][MAX], _dp[2][MAX][MAX][MAX][MAX], S[2][MAX][MAX];

int empt(int p, int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2)
        return 1;
    int res = S[p][x2][y2];
    if (x1 > 0)
        res -= S[p][x1 - 1][y2];
    if (y1 > 0)
        res -= S[p][x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        res += S[p][x1 - 1][y1 - 1];
    return res == 0;
}

int dp(int p, int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2 || x2 < 0 || y2 < 0)
        return 0;
    if (_dp[p][x1][y1][x2][y2] != -1)
        return _dp[p][x1][y1][x2][y2];

    if (empt(p, x1, y1, x1, y2))
        return _dp[p][x1][y1][x2][y2] = dp(p, x1 + 1, y1, x2, y2);
    if (empt(p, x2, y1, x2, y2))
        return _dp[p][x1][y1][x2][y2] = dp(p, x1, y1, x2 - 1, y2);
    if (empt(p, x1, y1, x2, y1))
        return _dp[p][x1][y1][x2][y2] = dp(p, x1, y1 + 1, x2, y2);
    if (empt(p, x1, y2, x2, y2))
        return _dp[p][x1][y1][x2][y2] = dp(p, x1, y1, x2, y2 - 1);

    int res;
    vector<int> arr;

    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++) {
            if (A[p][i][j] == 1)
                arr.push_back(dp(p, x1, y1, i - 1, j - 1) ^ dp(p, i + 1, j + 1, x2, y2) ^ dp(p, x1, j + 1, i - 1, y2) ^ dp(p, i + 1, y1, x2, j - 1));
            else if (A[p][i][j] == 2)
                arr.push_back(dp(p, x1, y1, i - 1, y2) ^ dp(p, i + 1, y1, x2, y2));
            else if (A[p][i][j] == 3)
                arr.push_back(dp(p, x1, y1, x2, j - 1) ^ dp(p, x1, j + 1, x2, y2));
        }

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());
    res = arr.size();

    for (int i = 0; i < arr.size(); i++)
        if (arr[i] != i)
            res = min(res, i);

    return _dp[p][x1][y1][x2][y2] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans = 0;
    string _S;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> _S;
        for (int j = 0; j < M; j++) {
            if (_S[j] == 'X')
                A[(i + j) & 1][(i + j) / 2][(i - j + M) / 2] = 1;
            else if (_S[j] == 'L')
                A[(i + j) & 1][(i + j) / 2][(i - j + M) / 2] = 2;
            else
                A[(i + j) & 1][(i + j) / 2][(i - j + M) / 2] = 3;
            S[(i + j) & 1][(i + j) / 2][(i - j + M) / 2] = 1;
        }
    }
    N = (N + M) / 2 + 2;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                if (j > 0)
                    S[i][j][k] += S[i][j - 1][k];
                if (k > 0)
                    S[i][j][k] += S[i][j][k - 1];
                if (j > 0 && k > 0)
                    S[i][j][k] -= S[i][j - 1][k - 1];

                for (int l = j; l < N; l++)
                    for (int m = k; m < N; m++)
                        _dp[i][j][k][l][m] = -1;
            }

    ans = dp(0, 0, 0, N - 1, N - 1) ^ dp(1, 0, 0, N - 1, N - 1);
    cout << (ans ? "koosaga" : "cubelover") << '\n';

    return 0;
}