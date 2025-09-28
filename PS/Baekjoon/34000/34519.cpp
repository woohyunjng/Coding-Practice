#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400002;
const int INF = 0x3f3f3f3f3f3f3f3f;

int T[MAX], L[MAX], R[MAX], V[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> T[i];

    L[0] = INF, R[N + 1] = INF;
    for (int i = 1; i <= N; i++)
        L[i] = min(L[i - 1] + T[i] / 2, T[i]);
    for (int i = N; i >= 1; i--)
        R[i] = min(R[i + 1] + T[i] / 2, T[i]);

    for (int i = 1; i <= N; i++)
        ans = max(ans, min({L[i], R[i], max(L[i - 1], R[i + 1]) + T[i] / 4}));

    cout << ans << '\n';

    return 0;
}