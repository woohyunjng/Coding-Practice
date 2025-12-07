#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;
typedef array<int, 3> tp; // max, length, 오른쪽 자식에 추가되는 length

int A[MAX];
tp tree[2][MAX * 4];

int spread(int t, int n, int s, int e, int v) { // [s, e]에서 v보다 큰 숫자 개수 세기
    if (s == e)
        return tree[t][n][0] > v ? 1 : 0;
    else {
        int m = s + e >> 1;
        if (tree[t][n << 1][0] > v)
            return spread(t, n << 1, s, m, v) + tree[t][n][2];
        else
            return spread(t, n << 1 | 1, m + 1, e, v);
    }
}

void update(int t, int n, int s, int e, int x, int v) {
    if (s == e)
        tree[t][n] = {v, 1, 0};
    else {
        int m = s + e >> 1;
        if (x <= m)
            update(t, n << 1, s, m, x, v);
        else
            update(t, n << 1 | 1, m + 1, e, x, v);

        tree[t][n][2] = spread(t, n << 1 | 1, m + 1, e, tree[t][n << 1][0]);
        tree[t][n][1] = tree[t][n << 1][1] + tree[t][n][2];
        tree[t][n][0] = max(tree[t][n << 1][0], tree[t][n << 1 | 1][0]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, T, X, Y;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i], update(0, 1, 1, N, i, A[i]), update(1, 1, 1, N, N - i + 1, A[i]);

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> X >> Y;
            update(0, 1, 1, N, X, Y), update(1, 1, 1, N, N - X + 1, Y);
        } else
            cout << N * 2 - tree[0][1][1] - tree[1][1][1] << '\n';
    }

    return 0;
}