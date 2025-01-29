#include <bits/stdc++.h>
#define int long long

#define MAX 1000

using namespace std;

int val[MAX], D[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, N;
    bool flag;
    cin >> M >> N;

    while (N--) {
        for (int i = 1; i <= M; i++)
            cin >> val[i];

        for (int i = 1; i <= M; i++)
            for (int j = 1; j <= M; j++) {
                if (i == j)
                    continue;
                if (val[i] == val[j])
                    continue;
                if (val[j] == 0 || (val[i] != 0 && val[i] < val[j]))
                    D[i][j]++;
            }
    }

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= M; j++) {
            if (D[i][j] == D[j][i])
                D[i][j] = D[j][i] = 0;
            else if (D[i][j] < D[j][i])
                D[i][j] = 0;
            else
                D[j][i] = 0;
        }

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= M; j++)
            for (int k = 1; k <= M; k++)
                D[j][k] = max(D[j][k], min(D[j][i], D[i][k]));

    for (int i = 1; i <= M; i++) {
        flag = true;
        for (int j = 1; j <= M; j++)
            if (i != j && D[i][j] < D[j][i])
                flag = false;
        if (flag)
            cout << i << ' ';
    }
    cout << '\n';

    return 0;
}