#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;

int A[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];

    if (N % 2 == 1 && M % 2 == 1)
        cout << "No" << '\n';
    else {
        if (N % 2 == 0) {
            for (int i = 1; i <= N; i += 2)
                for (int j = 1; j <= M; j++)
                    swap(A[i][j], A[i + 1][j]);
        } else {
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= M; j += 2)
                    swap(A[i][j], A[i][j + 1]);
        }

        cout << "Yes" << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++)
                cout << A[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}