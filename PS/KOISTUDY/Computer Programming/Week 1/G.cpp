#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;
    cout << min(N / 2, M) << '\n';

    return 0;
}