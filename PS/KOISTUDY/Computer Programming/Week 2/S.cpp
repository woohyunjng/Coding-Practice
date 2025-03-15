#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;

int M, A[MAX];

int get(int X, int Y, int K) {
    if (K == M)
        return 0;
    return min(abs(A[K + 1] - X) + get(A[K + 1], Y, K + 1), abs(A[K + 1] - Y) + get(X, A[K + 1], K + 1));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;

    cin >> N >> X >> Y >> M;
    for (int i = 1; i <= M; i++)
        cin >> A[i];

    cout << get(X, Y, 0) << '\n';

    return 0;
}