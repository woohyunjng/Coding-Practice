#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;

int ans[MAX][MAX];
char C[4] = {'a', 'b', 'c', 'd'};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    if (N % 4 != 0) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < N; i += 4)
        for (int j = 0; j < N; j += 4) {
            ans[i][j] = ans[i][j + 1] = ans[i][j + 2] = ans[i + 1][j + 1] = 0;
            ans[i][j + 3] = ans[i + 1][j + 2] = ans[i + 1][j + 3] = ans[i + 2][j + 3] = 1;
            ans[i + 2][j + 2] = ans[i + 3][j + 1] = ans[i + 3][j + 2] = ans[i + 3][j + 3] = 2;
            ans[i + 1][j] = ans[i + 2][j] = ans[i + 3][j] = ans[i + 2][j + 1] = 3;
        }

    for (int i = 0; i < N; i++, cout << '\n')
        for (int j = 0; j < N; j++)
            cout << C[ans[i][j]];

    return 0;
}