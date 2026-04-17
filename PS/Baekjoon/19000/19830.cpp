#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    string S;

    cin >> S, N = S.size();

    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] - '0';

    if (A[1] == A[N])
        cout << 1 << ' ' << N - 1 << ' ' << 2 << ' ' << N << '\n';
    else {
        X = 1, Y = N;
        while (A[X + 1] == A[1] && X + 1 <= N)
            X++;
        while (A[Y - 1] == A[N] && Y - 1 >= 1)
            Y--;

        if (N - X - 1 >= Y - 2)
            cout << X + 1 << ' ' << N - 1 << ' ' << X + 2 << ' ' << N << '\n';
        else
            cout << 1 << ' ' << Y - 2 << ' ' << 2 << ' ' << Y - 1 << '\n';
    }

    return 0;
}
