#include <bits/stdc++.h>
#define int long long

#define MAX 200000
#define MAX_M 20

using namespace std;

int A[MAX], B[MAX_M], V[MAX][MAX_M], C[1 << MAX_M];

void solve() {
    int N, M, K, S = 0, X, Y;
    vector<int> arr;

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i], S += A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];

    for (int i = 0; i < (1 << M); i++) {
        C[i] = (1ll << 30) - 1;
        for (int j = 0; j < M; j++)
            if (i & (1 << j))
                C[i] &= B[j];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++)
            V[i][j] = A[i];

        for (int j = 1; j < (1 << M); j++) {
            X = __builtin_popcount(j);
            V[i][X] = min(V[i][X], A[i] & C[j]);
        }

        for (int j = 0; j <= M; j++) {
            V[i][j] = A[i] - V[i][j];
            if (j > 0)
                arr.push_back(V[i][j] - V[i][j - 1]);
        }
    }

    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < K; i++)
        S -= arr[i];
    cout << S << '\n';
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