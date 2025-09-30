#include <bits/stdc++.h>
using namespace std;

int query(int T, int X) {
    int res;
    cout << "? " << (char)('A' + T) << ' ' << X << '\n', cout.flush();
    cin >> res;
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A = 1, B = 1;

    cin >> N;
    while (N >>= 1) {
        if (query(0, A + N - 1) < query(1, B + N - 1))
            A += N;
        else
            B += N;
    }

    cout << "!" << min(query(0, A), query(1, B)) << '\n', cout.flush();

    return 0;
}