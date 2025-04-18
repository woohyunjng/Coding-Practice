#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 21;

long double dis(int dx, int dy) { return sqrt(dx * dx + dy * dy); }

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y;
    long double ans;

    cin >> T;
    while (T--) {
        cin >> N, ans = 2147483647;

        for (int i = 0; i < N; i++)
            cin >> A[i] >> B[i];

        for (int i = 0; i < (1 << N); i++) {
            if (__builtin_popcount(i) != N / 2)
                continue;
            X = 0, Y = 0;
            for (int j = 0; j < N; j++)
                if (i & (1 << j))
                    X += A[j], Y += B[j];
                else
                    X -= A[j], Y -= B[j];

            ans = min(ans, dis(X, Y));
        }

        cout << fixed << setprecision(6) << ans << '\n';
    }

    return 0;
}