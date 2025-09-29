#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int D[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N, fill(D, D + N + 1, MAX);
    D[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (i % 3 == 0)
            D[i] = min(D[i], D[i / 3] + 1);
        if (i % 2 == 0)
            D[i] = min(D[i], D[i / 2] + 1);
        D[i] = min(D[i], D[i - 1] + 1);
    }

    cout << D[N] << '\n';
    while (N != 1) {
        cout << N << ' ';
        if (N % 3 == 0 && D[N] == D[N / 3] + 1)
            N /= 3;
        else if (N % 2 == 0 && D[N] == D[N / 2] + 1)
            N /= 2;
        else
            N--;
    }
    cout << 1 << '\n';

    return 0;
}