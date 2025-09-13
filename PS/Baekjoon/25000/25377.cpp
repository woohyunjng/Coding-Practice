#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, V = 1001;

    cin >> N;
    while (N--) {
        cin >> A >> B;
        if (A <= B)
            V = min(V, B);
    }
    cout << (V == 1001 ? -1 : V) << '\n';

    return 0;
}