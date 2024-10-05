#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void solve() {
    int N, K, st, en, md, res, X, mx, A, B;
    cin >> N >> K;

    for (int i = N; i >= 1; i--) {
        cout << "? " << 1 << ' ' << i * N << '\n';
        cout.flush();

        cin >> X;
        if (X == N) {
            mx = i;
            break;
        }
    }

    for (int i = 1; i <= N / K; i++) {
        A = 1, B = 1;

        while (A <= N && B <= K) {
            cout << "? " << A << ' ' << i * mx << '\n';
            cout.flush();

            cin >> X;
            if (X == -1)
                break;

            A = X + 1;
            B++;
        }

        if (A == N + 1 && B == K + 1) {
            cout << "! " << i * mx << '\n';
            cout.flush();
            cin >> X;
            return;
        }
    }

    cout << "! " << -1 << '\n';
    cout.flush();
    cin >> X;
}

signed main() {
    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}