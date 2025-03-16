#include <bits/stdc++.h>
using namespace std;

const int MAX = 200;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, ans;

    cin >> T;
    while (T--) {
        cin >> N, ans = 0;
        for (int i = 1; i <= N; i++) {
            cin >> A[i], ans++;
            if (ans == A[i])
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}