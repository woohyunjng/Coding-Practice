#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    bool flag;

    cin >> T;
    while (T--) {
        cin >> N, N++, flag = true;
        for (int i = 2; i * i <= N; i++)
            flag &= N % i != 0;

        if (!flag)
            cout << 0 << '\n';
        else {
            cout << 1 << '\n';
            cout << 1 << ' ' << N << '\n';
        }
    }

    return 0;
}