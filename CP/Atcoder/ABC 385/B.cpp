#include <bits/stdc++.h>
#define int long long

#define MAX 110
using namespace std;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, X, Y, res = 0;
    string S, T;
    cin >> H >> W >> X >> Y;

    fill(&A[0][0], &A[MAX - 1][MAX], -1);
    for (int i = 1; i <= H; i++) {
        cin >> S;
        for (int j = 1; j <= W; j++) {
            if (S[j - 1] == '#')
                A[i][j] = -1;
            else if (S[j - 1] == '.')
                A[i][j] = 0;
            else if (S[j - 1] == '@')
                A[i][j] = 1;
        }
    }

    cin >> T;
    for (char i : T) {
        if (i == 'U') {
            if (A[X - 1][Y] != -1)
                X--, res += A[X][Y], A[X][Y] = 0;
        }
        if (i == 'D') {
            if (A[X + 1][Y] != -1)
                X++, res += A[X][Y], A[X][Y] = 0;
        }
        if (i == 'L') {
            if (A[X][Y - 1] != -1)
                Y--, res += A[X][Y], A[X][Y] = 0;
        }
        if (i == 'R') {
            if (A[X][Y + 1] != -1)
                Y++, res += A[X][Y], A[X][Y] = 0;
        }
    }

    cout << X << ' ' << Y << ' ' << res << '\n';

    return 0;
}