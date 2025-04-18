#include <bits/stdc++.h>
#define int long long
#define ll __int128_t

using namespace std;

typedef array<int, 2> fr;

const int MAX = 2001;

int V[MAX][MAX], S[MAX];
fr D[MAX][MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L, S, X, Y;
    fr K;

    vector<int> P;

    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        S = X = Y = 0;
        for (int j = 1; j <= L; j++)
            cin >> V[i][j], S += V[i][j];
        for (int j = 1; j <= N - 1; j++) {
            while ((ll)S * j >= (ll)N * (Y + V[i][X + 1]))
                Y += V[i][++X];
            D[i][j] = {S * j - N * Y + X * N * V[i][X + 1], N * V[i][X + 1]};
        }
        D[i][N] = {0, 0};
    }

    for (int i = 1; i <= N; i++) {
        K = {MAX, 1}, X = -1;
        for (int j = 1; j <= N; j++) {
            if (chk[j])
                continue;
            if ((ll)D[j][i][0] * K[1] <= (ll)K[0] * D[j][i][1])
                K = D[j][i], X = j;
        }

        if (i < N)
            cout << K[0] << ' ' << K[1] << '\n';
        P.push_back(X), Y = K[1], chk[X] = true;
    }

    for (int i : P)
        cout << i << ' ';
    cout << '\n';

    return 0;
}