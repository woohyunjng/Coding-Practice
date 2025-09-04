#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }
int lcm(int X, int Y) { return X / gcd(X, Y) * Y; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, V;

    cin >> T;
    while (T--) {
        cin >> N;

        if (N <= 4) {
            for (int i = 1; i <= N; i++)
                cout << i % N + 1 << ' ';
            cout << '\n';
            cout << 1 << ' ' << 2 << '\n';
        } else if (N == 6) {
            cout << 2 << ' ' << 1 << ' ' << 4 << ' ' << 5 << ' ' << 6 << ' ' << 4 << '\n';
            cout << 1 << ' ' << 3 << '\n';
        } else {
            X = V = 0;
            for (int i = 1; i < N; i++)
                if (lcm(i, N - i) > V)
                    V = lcm(i, N - i), X = i;

            for (int i = 1; i <= X; i++)
                cout << i % X + 1 << ' ';
            for (int i = X + 1; i <= N; i++)
                cout << (i - X) % (N - X) + X + 1 << ' ';
            cout << '\n';
            cout << 1 << ' ' << X + 1 << '\n';
        }
    }

    return 0;
}