#include <bits/stdc++.h>
using namespace std;

const int MAX = 300001;

int A[MAX], V[MAX], uf[MAX];

int find(int X) { return uf[X] == X ? X : uf[X] = find(uf[X]); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, T, X, Y;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (V[A[i]] == 0)
            V[A[i]] = i;
        uf[i] = V[A[i]];
    }

    cin >> M;
    while (M--) {
        cin >> T;
        if (T == 1) {
            cin >> X >> Y;
            if (V[X] == 0 || X == Y)
                continue;
            else if (V[Y] == 0)
                V[Y] = V[X];
            A[V[Y]] = Y, uf[V[X]] = V[Y], V[X] = 0;
        } else {
            cin >> X;
            cout << A[find(X)] << '\n';
        }
    }

    return 0;
}