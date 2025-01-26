#include <bits/stdc++.h>
#define int long long

#define MAX 100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

int A[MAX], B[MAX];

void solve() {
    int N, X = 0, res = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], res += A[i];

    for (int i = N; i >= 2; i--) {
        res = max({res, max(A[i], A[1]) - min(A[1], A[i])});
        for (int j = i - 1; j >= 1; j--)
            B[j] = A[j + 1] - A[j];
        for (int j = 1; j < i; j++)
            A[j] = B[j];
    }

    cout << res << '\n';
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