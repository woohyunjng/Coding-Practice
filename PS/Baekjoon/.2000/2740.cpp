#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int A[MAX][MAX], B[MAX][MAX], ans[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    cin >> M >> K;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < K; j++)
            cin >> B[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            for (int k = 0; k < M; k++)
                ans[i][j] += A[i][k] * B[k][j];

    for (int i = 0; i < N; i++, cout << '\n')
        for (int j = 0; j < K; j++)
            cout << ans[i][j] << ' ';

    return 0;
}