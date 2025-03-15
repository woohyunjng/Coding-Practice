#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int P, F, X, ans = 10000000, val;

    cin >> P >> F;
    for (int i = 0; i < P; i++)
        cin >> A[i];
    for (int i = 0; i < F; i++)
        cin >> B[i];

    for (int i = 0; i < (1 << P); i++) {
        if (__builtin_popcount(i) != F)
            continue;
        X = 0, val = 0;
        for (int j = 0; j < P; j++) {
            if (!(i & (1 << j)))
                continue;
            val += abs(A[j] - B[X++]);
        }
        ans = min(ans, val);
    }

    cout << ans << '\n';

    return 0;
}