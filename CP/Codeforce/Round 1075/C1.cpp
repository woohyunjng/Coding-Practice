#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int ans[MAX];
bool chk[MAX];

void solve() {
    int N;

    cin >> N;
    fill(chk + 1, chk + N + 1, false);
    fill(ans + 1, ans + N + 1, 0);

    for (int i = 2; i < N; i++)
        ans[i] = i ^ 1, chk[ans[i]] = true;
    for (int i = 1; i <= N; i++) {
        if (chk[i])
            continue;
        if (ans[N] == 0)
            ans[N] = i, chk[i] = true;
        else
            ans[1] = i, chk[i] = true;
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
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