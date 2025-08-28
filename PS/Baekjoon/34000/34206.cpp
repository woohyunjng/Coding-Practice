#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300001;
const int MAX_LOG = 60;

int X[MAX], P[MAX],
    sparse[MAX][MAX_LOG][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, S, T, K;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i] >> P[i], arr.push_back(X[i]);

    for (int i = 1; i < N; i++) {
        for (S = 0; X[i] + P[i] * (1ll << S) < X[i + 1];)
            S++;
        T = X[i] + P[i] * (1ll << S);
        sparse[i][0][0] = upper_bound(arr.begin(), arr.end(), T) - arr.begin();
        sparse[i][0][1] = S + 1 + (S == 0 ? 0 : P[i] * ((1ll << S) - 1)) + T - X[sparse[i][0][0]];
    }
    sparse[N][0][0] = N;

    for (int i = 1; i < MAX_LOG; i++)
        for (int j = 1; j <= N; j++) {
            sparse[j][i][0] = sparse[sparse[j][i - 1][0]][i - 1][0];
            sparse[j][i][1] = sparse[sparse[j][i - 1][0]][i - 1][1] + sparse[j][i - 1][1];
        }

    cin >> Q;
    while (Q--) {
        cin >> S >> T;
        K = upper_bound(arr.begin(), arr.end(), S) - arr.begin();

        if (K == 0 || S - X[K] >= T) {
            cout << S - T << '\n';
            continue;
        }

        T -= S - X[K], S = K;
        for (int i = MAX_LOG - 1; i >= 0; i--) {
            if (sparse[S][i][1] <= T)
                T -= sparse[S][i][1], S = sparse[S][i][0];
        }
        if (sparse[S][0][1] <= T)
            T -= sparse[S][0][1], S = sparse[S][0][0];

        if (T == 0)
            cout << X[S] << '\n';

        K = X[S];
        for (int i = 0; T && i < MAX_LOG; i++) {
            T--;
            if (P[S] * (1ll << i) >= T)
                cout << X[S] + P[S] * (1ll << i) - T << '\n', T = 0;
            else
                T -= P[S] * (1ll << i);
        }
    }

    return 0;
}