#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;

int N, A[MAX];

int get(int X, int Y, int idx) {
    if (idx > N)
        return 0;
    return min(
        get(X, A[idx], idx + 1) + abs(Y - A[idx]),
        get(A[idx], Y, idx + 1) + abs(X - A[idx]));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, P, Q;

    cin >> X >> P >> Q >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    cout << get(P, Q, 1) << '\n';

    return 0;
}