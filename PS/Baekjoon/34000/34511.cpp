#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 101;

int A[MAX][MAX];
pr go[4] = {{1, 0}, {0, 1}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y, ans = 0;
    string _S;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> _S;
        for (int j = 1; j <= M; j++) {
            if (_S[j - 1] == 'X')
                A[i][j] = 1;
            else if (_S[j - 1] == 'Y')
                A[i][j] = 2;
            else
                A[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            for (pr k : go) {
                X = i + k[0], Y = j + k[1];
                if (X > N || Y > M || A[i][j] == A[X][Y] || A[i][j] == 0 || A[X][Y] == 0)
                    continue;
                ans++;
            }

    cout << ans << '\n';

    return 0;
}