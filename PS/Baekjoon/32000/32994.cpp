#include <bits/stdc++.h>
#define int long long

#define MAX 1100
using namespace std;

int res[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        if (i % 5 == 0)
            res[i][1] = 1;
        else if (i % 5 == 1)
            res[i][1] = 3;
        else if (i % 5 == 2)
            res[i][1] = 5;
        else if (i % 5 == 3)
            res[i][1] = 2;
        else if (i % 5 == 4)
            res[i][1] = 4;

        for (int j = 2; j <= M; j++)
            res[i][j] = res[i][j - 1] % 5 + 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++)
            cout << res[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
