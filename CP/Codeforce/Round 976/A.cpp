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

    int T, N, K, res;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        res = 0;

        if (K == 1) {
            cout << N << '\n';
            continue;
        }

        while (N) {
            res += N % K;
            N /= K;
        }

        cout << res << '\n';
    }

    return 0;
}