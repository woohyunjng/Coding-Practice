#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 4101;

int N, M, K, P[MAX], A[MAX][MAX], C[4][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, V, X = 0;
    string S;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dis(1, 1e9);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> S, P[i] = dis(mt), X += P[i];
        for (int j = 0; j < M; j++) {
            if (S[j] == 'A')
                A[i][j] = 0;
            else if (S[j] == 'G')
                A[i][j] = 1;
            else if (S[j] == 'C')
                A[i][j] = 2;
            else
                A[i][j] = 3;
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