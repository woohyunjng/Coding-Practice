#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

int A[MAX][MAX], C[MAX], V[MAX];
bool chk[MAX];
vector<int> arr[MAX], row[MAX], val;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    bool flag = false;

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j], C[A[i][j]]++, row[A[i][j]].push_back(i);

    for (int i = 2; i <= N << 1; i++)
        arr[C[i]].push_back(i);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            if (C[A[i][j]] == 1)
                val.push_back(i), chk[i] = true;
        }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (C[A[i][j]] == N) {
                V[A[i][j]] = N + 1;
                continue;
            }

            V[A[i][j]] = C[A[i][j]] + 1;
            for (int k : row[A[i][j]]) {
                if (!chk[k])
                    continue;
                for (int l = 1; l <= N; l++)
                    V[A[k][l]] = C[A[k][l]] + 1;
                break;
            }
            flag = true;
            break;
        }
        if (flag)
            break;
    }

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (!V[A[i][j]])
                V[A[i][j]] = (N << 1) + 1 - C[A[i][j]];

    for (int i = 1; i <= N; i++, cout << '\n')
        for (int j = 1; j <= N; j++)
            cout << V[A[i][j]] << ' ';

    return 0;
}