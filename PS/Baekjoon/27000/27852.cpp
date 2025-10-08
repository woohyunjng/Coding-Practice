#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, V;
    bool ans, flag;

    cin >> T;
    while (T--) {
        cin >> N >> K, V = 0, ans = false;
        for (int i = 0; i < N; i++) {
            cin >> A[i], B[i] = 0;
            if (N == 1)
                B[i] = 1, A[i]--;

            for (;; B[i]++, A[i]--) {
                flag = false;
                for (int k = 2; k * k <= A[i]; k++)
                    if (A[i] % k == 0) {
                        flag = true;
                        break;
                    }
                if (!flag)
                    break;
            }
            V ^= B[i] % (K + 1), ans |= B[i] <= K;
        }

        ans |= V != 0;
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}