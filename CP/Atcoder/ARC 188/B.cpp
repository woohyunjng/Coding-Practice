#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int gcd(int X, int Y) { return Y ? gcd(Y, X % Y) : X; }

void solve() {
    int N, K;
    cin >> N >> K;

    if (N == 2 && K == 1) {
        cout << "Yes\n";
        return;
    }

    if (N % 4 == 0 || K * 2 == N)
        cout << "No" << '\n';
    else if (N & 1) {
        if (gcd(N, K) != 1)
            cout << "No" << '\n';
        else
            cout << "Yes" << '\n';
    } else {
        if (gcd(N, K) != 1 && gcd(N, abs(N / 2 - K)) != 1)
            cout << "No" << '\n';
        else
            cout << "Yes" << '\n';
    }
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