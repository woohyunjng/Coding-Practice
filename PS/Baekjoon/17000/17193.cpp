#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    cin >> N >> K;

    cout << 2019201997 - 84 * (K - 1) - 48 * N << '\n';

    return 0;
}