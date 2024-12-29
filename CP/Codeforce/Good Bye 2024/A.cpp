#include <bits/stdc++.h>
#define int long long

#define MAX 210
using namespace std;

int A[MAX];

void solve() {
    int N, X, Y;
    bool res = false;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N - 1; i++) {
        X = min(A[i], A[i + 1]), Y = max(A[i], A[i + 1]);
        res = res || (X * 2 > Y);
    }

    cout << (res ? "YES" : "NO") << '\n';
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