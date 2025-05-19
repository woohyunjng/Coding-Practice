#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 502;

int V[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C, D, W;

    cin >> N >> Q;
    while (Q--) {
        cin >> A >> B >> C >> D >> W;
        V[A][B] += W, V[C + 1][B] -= W, V[A][D + 1] -= W, V[C + 1][D + 1] += W;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            V[i][j] += V[i - 1][j] + V[i][j - 1] - V[i - 1][j - 1];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cout << V[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}