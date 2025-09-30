#include <bits/stdc++.h>
using namespace std;

signed main() {
    int A = 0, B = 0, C, D;

    for (int i = 1; i <= 9999; i++) {
        cout << "? A " << i << '\n', cout.flush();
        cin >> A;
        if (A != 0) {
            A = i;
            break;
        }
    }
    if (A == 0)
        A = 10000;

    random_device rd;
    mt19937 mt(rd());

    C = mt() % 10000 + 1, D = C == 10000 ? 9999 : 10000;

    for (int i = 1; i < D; i++) {
        if (i == C)
            continue;
        cout << "? B " << i << '\n', cout.flush();
        cin >> B;
        if (B != 0) {
            B = i;
            break;
        }
    }
    if (B == 0)
        B = D;

    cout << "! " << A + B << '\n', cout.flush();

    return 0;
}