#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, X, Y, K, A[5];
    bool ans;

    cin >> T;
    while (T--) {
        cin >> X >> Y, ans = false;
        for (int i = 0; i < 5; i++)
            cin >> A[i];

        for (int i = 0; i < (1 << 5); i++) {
            K = 0;
            for (int j = 0; j < 5; j++)
                if (i & (1 << j))
                    K += A[j];
            ans |= (X <= K && K <= Y);
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}