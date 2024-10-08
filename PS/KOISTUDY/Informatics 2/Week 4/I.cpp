#include <bits/stdc++.h>
#define int long long

#define MAX 1500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K = 1, X = 10;
    cin >> N;

    if (N % 2 == 0 || N % 5 == 0) {
        cout << -1;
        return 0;
    }

    while (X % (9 * N) != 1) {
        X = X * 10 % (9 * N);
        K++;
    }

    cout << string(K, '1');

    return 0;
}