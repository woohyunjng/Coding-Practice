#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

void solve() {
    int N, M, X;
    bool swapped = false;

    string _S;

    cin >> N >> M;

    vector<vector<int>> A(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        cin >> _S;
        for (int j = 1; j <= M; j++)
            A[i][j] = _S[j - 1] - '0';
    }

    if (N > M) {
        swap(N, M), swapped = true;
        vector<vector<int>> B(N + 1, vector<int>(M + 1, 0));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                B[i][j] = A[j][i];
        A = B, B.clear();
    }

    vector<vector<int>> ans(N + 1, vector<int>(M + 1, N * M + 1));
    vector<int> V(M + 1);

    for (int i = 1; i <= N; i++) {
        fill(V.begin(), V.end(), N * M + 1);
        for (int j = 1; j < i; j++) {
            X = 0;
            for (int k = 1; k <= M; k++) {
                if (A[i][k] != 1 || A[j][k] != 1)
                    continue;
                if (X != 0) {
                    for (int l = X; l <= k; l++)
                        V[l] = min(V[l], (k - X + 1) * (i - j + 1));
                }
                X = k;
            }
            for (int k = 1; k <= M; k++)
                ans[j][k] = min(ans[j][k], V[k]);
        }
        for (int j = 1; j <= M; j++)
            ans[i][j] = min(ans[i][j], V[j]);
    }

    if (swapped) {
        vector<vector<int>> B(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                B[j][i] = ans[i][j];
        ans = B, B.clear(), swap(N, M);
    }

    for (int i = 1; i <= N; i++, cout << '\n')
        for (int j = 1; j <= M; j++)
            cout << (ans[i][j] == N * M + 1 ? 0 : ans[i][j]) << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}