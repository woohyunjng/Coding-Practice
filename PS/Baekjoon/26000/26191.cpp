#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 100001;

int N, M, K, P[MAX], C[4][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, V, X = 0;
    string S;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dis(1, 1e9);

    cin >> N >> M >> K;

    vector<vector<int>> A(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++) {
        cin >> S, P[i] = dis(mt), X += P[i];
        for (int j = 0; j < M; j++) {
            A[i][j] = S[j] - 'A';
            C[A[i][j]][j] += P[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        V = 0;
        for (int j = 0; j < M; j++)
            V += C[A[i][j]][j] - P[i];
        if (V == (X - P[i]) * (M - K))
            cout << i << '\n';
    }

    return 0;
}