#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int gcd(int X, int Y) { return Y == 0 ? X : gcd(Y, X % Y); }

int A[MAX];

void solve() {
    int N, G;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    G = A[0];
    for (int i = 1; i < N; i++)
        G = gcd(G, A[i]);

    for (int j = 2;; j++) {
        if (gcd(G, j) != 1)
            continue;
        cout << j << '\n';
        return;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}