#include <bits/stdc++.h>
#define int long long

#define MAX 2000
using namespace std;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, R[2], C[2];
    string S;
    bool res = true;

    cin >> H >> W;
    R[0] = H + 1, R[1] = 0, C[0] = W + 1, C[1] = 0;

    for (int i = 1; i <= H; i++) {
        cin >> S;
        for (int j = 1; j <= W; j++) {
            if (S[j - 1] == '.')
                A[i][j] = 0;
            else if (S[j - 1] == '#') {
                A[i][j] = 1;
                R[0] = min(R[0], i), R[1] = max(R[1], i);
                C[0] = min(C[0], j), C[1] = max(C[1], j);
            } else
                A[i][j] = 2;
        }
    }

    for (int i = R[0]; i <= R[1]; i++)
        for (int j = C[0]; j <= C[1]; j++)
            res &= A[i][j] != 0;

    cout << (res ? "Yes" : "No") << '\n';

    return 0;
}