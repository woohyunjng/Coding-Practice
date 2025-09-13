#include <bits/stdc++.h>
using namespace std;

const int MAX = 2002;

int V[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, ans = 0;
    string S;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++)
            V[i][j] = S[j - 1] - '0';
    }

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++) {
            X = max({V[j - 1][i - 1], V[j][i - 1], V[j + 1][i - 1]});
            ans = max(ans, X), V[j][i] += X;
        }

    cout << ans << '\n';

    return 0;
}