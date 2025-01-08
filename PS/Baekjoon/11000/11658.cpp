#include <bits/stdc++.h>
#define int long long

#define MAX 2010
using namespace std;

int A[MAX][MAX], val[MAX][MAX], N;

void update(int X, int Y, int W) {
    for (int i = X; i <= N; i += i & -i)
        for (int j = Y; j <= N; j += j & -j)
            A[i][j] += W;
}

int query(int X, int Y) {
    int res = 0;
    for (int i = X; i > 0; i -= i & -i)
        for (int j = Y; j > 0; j -= j & -j)
            res += A[i][j];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, A, B, C, D;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> val[i][j], update(i, j, val[i][j]);

    while (Q--) {
        cin >> T;
        if (T == 0) {
            cin >> A >> B >> C;
            update(A, B, C - val[A][B]), val[A][B] = C;
        } else {
            cin >> A >> B >> C >> D;
            cout << query(C, D) - query(A - 1, D) - query(C, B - 1) + query(A - 1, B - 1) << '\n';
        }
    }

    return 0;
}