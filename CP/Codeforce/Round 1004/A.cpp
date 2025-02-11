#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int X[MAX], cnt[MAX], V[MAX];

void solve() {
    int N, A, B, K = 0;
    bool ans = true;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i], cnt[X[i]]++, V[X[i]] = i;
    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 0) {
            K = i;
            break;
        }
    }

    if (K != 0) {
        B = K == 1 ? 2 : 1;
        cout << "? " << K << ' ' << B << '\n', cout.flush(), cin >> A;
        ans = A == 0;
    } else {
        cout << "? " << V[1] << ' ' << V[N] << '\n', cout.flush(), cin >> A;
        cout << "? " << V[N] << ' ' << V[1] << '\n', cout.flush(), cin >> B;

        if (A < N - 1 || B < N - 1)
            ans = true;
        else
            ans = false;
    }

    cout << "! " << (ans ? 'A' : 'B') << '\n', cout.flush();

    for (int i = 1; i <= N; i++)
        cnt[i] = 0, V[i] = 0;
}

signed main() {
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}