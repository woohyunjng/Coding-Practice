#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int F[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, L = 0, R = 0;
    string S;

    cin >> S, N = S.size();
    reverse(S.begin(), S.begin() + N);

    F[0] = N;
    for (int i = 1; i < N; i++) {
        if (i <= R)
            F[i] = min(R - i, F[i - L]);
        while (i + F[i] < N && S[F[i]] == S[i + F[i]])
            F[i]++;
        if (i > R)
            L = i;
        R = max(R, i + F[i] - 1);
    }

    cin >> Q;
    while (Q--) {
        cin >> X;
        cout << F[N - X] << '\n';
    }

    return 0;
}