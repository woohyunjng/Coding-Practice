#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0, X = -1, Y = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], ans += A[i];

    sort(A + 1, A + N + 1);

    for (int i = N; i >= 1; i--) {
        if ((X + 1) * (Y + A[i]) >= X * Y)
            X++, Y += A[i];
    }
    ans += X * Y;

    cout << ans << '\n';

    return 0;
}