#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<int>> ans;

int compose(int N, int M, int K, int X, int Y, int C) {
    if (N <= 0 || M <= 0)
        return C;

    int A, B;

    if (K == N * M / 4) {
        for (int i = X; i < X + N; i += 2)
            for (int j = Y; j < Y + M; j += 2)
                ans[i][j] = ans[i + 1][j] = ans[i][j + 1] = ans[i + 1][j + 1] = C++;
    } else if (N * M / 4 - (N + M) / 2 + 1 < K) {
        for (A = 2; A + 2 <= N; A += 2) {
            B = (N * M / 4 - K) * 2 - A;
            if (B >= 2 && B + 2 <= M)
                break;
        }
        for (int i = X; i < X + A + 2; i++)
            ans[i][Y] = ans[i][Y + B + 1] = C;
        for (int i = Y + 1; i < Y + B + 1; i++)
            ans[X][i] = ans[X + A + 1][i] = C;
        C = compose(A, B, A * B / 4, X + 1, Y + 1, ++C);
        C = compose(A + 2, M - B - 2, (A + 2) * (M - B - 2) / 4, X, Y + B + 2, C);
        C = compose(N - A - 2, M, (N - A - 2) * M / 4, X + A + 2, Y, C);
    } else if (N * M / 4 - (N + M) / 2 + 1 == K) {
        if (N >= M) {
            for (int i = X; i < X + N - 2; i++)
                ans[i][Y] = ans[i][Y + M - 1] = C;
            for (int i = Y + 1; i < Y + M - 1; i++)
                ans[X][i] = ans[X + N - 3][i] = C;
            C = compose(N - 4, M - 2, K - 1 - 2 * M / 4, X + 1, Y + 1, ++C);
            C = compose(2, M, 2 * M / 4, X + N - 2, Y, C);
        } else {
            for (int i = X; i < X + N; i++)
                ans[i][Y] = ans[i][Y + M - 3] = C;
            for (int i = Y + 1; i < Y + M - 3; i++)
                ans[X][i] = ans[X + N - 1][i] = C;
            C = compose(N - 2, M - 4, K - 1 - 2 * N / 4, X + 1, Y + 1, ++C);
            C = compose(N, 2, 2 * N / 4, X, Y + M - 2, C);
        }
    } else {
        for (int i = X; i < X + N; i++)
            ans[i][Y] = ans[i][Y + M - 1] = C;
        for (int i = Y + 1; i < Y + M - 1; i++)
            ans[X][i] = ans[X + N - 1][i] = C;
        C = compose(N - 2, M - 2, K - 1, X + 1, Y + 1, ++C);
    }

    return C;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, K;
    bool res;
    cin >> T;

    while (T--) {
        cin >> N >> M >> K, res = true;
        if ((N & 1) || (M & 1))
            res = false;
        if (K == N * M / 4 - 1)
            res = false;
        if (K * 2 < max(N, M) || K * 4 > N * M)
            res = false;
        if (N == M && K == N / 2 + 1)
            res = false;

        if (!res)
            cout << "NO\n";
        else {
            cout << "YES\n";
            ans.clear(), ans.resize(N, vector<int>(M, 0));
            compose(N, M, K, 0, 0, 1);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++)
                    cout << ans[i][j] << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}