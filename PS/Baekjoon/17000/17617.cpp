#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 3000000;

int A[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, R, M, ans = 0, X = 0;
    cin >> N >> R >> M;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1), A[N + 1] = A[1] + M;

    for (int i = 1; i <= N; i++)
        V[i] = V[i + N] = A[i + 1] - A[i] - R * 2;
    for (int i = 1; i <= 2 * N; i++)
        X = max(0ll, X + V[i]), ans = max(ans, X);

    ans = (ans + 1) / 2;
    cout << ans << '\n';

    return 0;
}