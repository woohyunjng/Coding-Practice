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

    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        if (N <= 5)
            cout << -1 << '\n';
        else if (N & 1) {
            cout << 4 << '\n';
            cout << 1 << ' ' << (N - 1) / 2 << ' ' << (N + 1) / 2 << ' ' << N - 2 << '\n';
        } else {
            cout << 3 << '\n';
            cout << 1 << ' ' << N / 2 << ' ' << N - 2 << '\n';
        }
    }

    return 0;
}