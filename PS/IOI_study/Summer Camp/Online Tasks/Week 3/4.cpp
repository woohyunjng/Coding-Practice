#include <bits/stdc++.h>
#define int long long

#define MAX 2100
using namespace std;

int sm[3][MAX][MAX], arr[MAX][MAX];

int calc(int T, int A, int B, int C, int D) { return sm[T][C][D] - sm[T][A - 1][D] - sm[T][C][B - 1] + sm[T][A - 1][B - 1]; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q, A, B, C, D, res;
    string S;
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++)
            arr[i][j] = S[j - 1] - '0';
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            sm[0][i][j] = arr[i][j] + sm[0][i - 1][j] + sm[0][i][j - 1] - sm[0][i - 1][j - 1];
            sm[1][i][j] = (arr[i - 1][j] && arr[i][j]) + sm[1][i - 1][j] + sm[1][i][j - 1] - sm[1][i - 1][j - 1];
            sm[2][i][j] = (arr[i][j - 1] && arr[i][j]) + sm[2][i - 1][j] + sm[2][i][j - 1] - sm[2][i - 1][j - 1];
        }

    while (Q--) {
        cin >> A >> B >> C >> D;
        res = calc(0, A, B, C, D) - calc(1, A + 1, B, C, D) - calc(2, A, B + 1, C, D);
        cout << res << '\n';
    }

    return 0;
}