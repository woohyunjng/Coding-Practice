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
    int N, K;
    cin >> N >> K;

    if (K & 1) {
        if (K == 1 || K == N) {
            if (N == 1) {
                cout << 1 << '\n';
                cout << 1 << '\n';
            } else
                cout << -1 << '\n';
        } else {
            cout << 3 << '\n';
            cout << 1 << ' ' << K - 1 << ' ' << K + 2 << '\n';
        }
    } else {
        cout << 3 << '\n';
        cout << 1 << ' ' << K << ' ' << K + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}