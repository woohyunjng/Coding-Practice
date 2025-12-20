#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 2000002;
const int INF = 0x3f3f3f3f3f3f3f3f;

int X[MAX], V[MAX];

void solve() {
    int N, ans = 0, L = 0, R = INF, XL, XR;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> X[i];
    for (int i = 1; i < N; i++)
        V[i] = X[i + 1] - X[i];
    R = V[1];

    for (int i = 1; i < N; i++) {
        XL = max(0ll, V[i] - R), XR = min(V[i] - L, i + 1 == N ? INF : V[i + 1]);
        if (XL < XR)
            L = XL, R = XR, ans++;
        else
            R = max(0ll, min(V[i] - L, V[i + 1])), L = 0;
    }

    cout << ans << '\n';
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