#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, sm, X, st, en, mid, res, A;
    cin >> T;

    while (T--) {
        cin >> N >> K;

        sm = 0, X = 0;
        for (int i = 1; i <= N; i++) {
            cin >> A;
            sm += A, X = max(X, A);
        }

        for (int i = 1; i <= N; i++) {
            if (i * X < sm) {
                if (sm % i == 0 || (sm + K) % i == 0 || (int)(sm + K) / i > (int)sm / i)
                    res = i;
            } else if (i * X <= sm + K)
                res = i;
        }

        cout << res << '\n';
    }

    return 0;
}