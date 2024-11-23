#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void solve() {
    int N, M, res = 0, K = 0, X;
    cin >> N >> M;

    X = N;
    while (X)
        K++, X >>= 1;

    for (int i = 1; i < (1 << K); i++) {
        if ((N ^ i) > M || i == N)
            continue;

        if (N % i == 0 || (N ^ i) % i == 0)
            res++;
    }

    cout << res << '\n';
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