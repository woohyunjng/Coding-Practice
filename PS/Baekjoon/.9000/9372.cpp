#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, A, B;

    cin >> T;
    while (T--) {
        cin >> N >> M;
        while (M--)
            cin >> A >> B;
        cout << N - 1 << '\n';
    }

    return 0;
}