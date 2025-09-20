#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 400001;

int ans[MAX];

void solve() {
    int N, C, D;
    cin >> N, fill(ans, ans + N * 2 + 1, 0);

    C = (N + 1) / 2, D = N * 2 - N / 2;
    ans[C] = ans[C + N] = N;

    for (int i = 2; i < N; i += 2)
        ans[C - i / 2] = ans[C + i / 2] = i;
    for (int i = 3; i < N; i += 2)
        ans[D - 1 - i / 2] = ans[D + i / 2] = i;

    for (int i = 1; i <= N * 2; i++)
        cout << (ans[i] == 0 ? 1 : ans[i]) << ' ';
    cout << '\n';
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