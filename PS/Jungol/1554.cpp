#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2000;

int tree[MAX][MAX], S;

void update(int X, int Y, int W) {
    for (int i = X; i <= S; i += i & -i)
        for (int j = Y; j <= S; j += j & -j)
            tree[i][j] += W;
}

int query(int X, int Y) {
    int res = 0;
    for (int i = X; i > 0; i -= i & -i)
        for (int j = Y; j > 0; j -= j & -j)
            res += tree[i][j];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, X, Y, A, L, B, R, T;

    cin >> K >> S;

    while (true) {
        cin >> K;
        if (K == 3)
            break;
        else if (K == 1) {
            cin >> X >> Y >> A, X++, Y++;
            update(X, Y, A);
        } else {
            cin >> L >> B >> R >> T, L++, B++, R++, T++;
            cout << query(R, T) + query(L - 1, B - 1) - query(L - 1, T) - query(R, B - 1) << '\n';
        }
    }

    return 0;
}