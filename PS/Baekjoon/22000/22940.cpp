#include <bits/stdc++.h>
#define double long double
using namespace std;

const int MAX = 10;

double M[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    double D;

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= N; j++)
            cin >> M[i][j];

    for (int i = 0; i < N; i++) {
        D = M[i][i];
        for (int j = i; j <= N; j++)
            M[i][j] /= D;
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            D = -M[j][i];
            for (int k = 0; k <= N; k++)
                M[j][k] += M[i][k] * D;
        }
    }

    for (int i = 0; i < N; i++)
        cout << M[i][N] << ' ';
    cout << '\n';

    return 0;
}