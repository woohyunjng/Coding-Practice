#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;

string S[MAX], ans[MAX];
int C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z, K;
    string P;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
    cin >> P, K = P.size();

    for (int i = 0; i < N; i++) {
        for (X = Y = 0; X < S[i].size() && Y < K; X++) {
            if (S[i][X] != P[Y])
                ans[Y] += S[i][X];
            else
                C[Y] = 1, Y++;
        }

        if (Y == K) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    for (int i = 0; i < K; i++) {
        cout << ans[i];
        if (C[i] > 0)
            cout << P[i];
    }

    return 0;
}