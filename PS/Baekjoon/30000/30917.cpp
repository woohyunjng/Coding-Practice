#include <bits/stdc++.h>
using namespace std;

signed main() {
    int A, B;

    for (int i = 1; i <= 9; i++) {
        cout << "? A " << i << '\n', cout.flush();
        cin >> A;
        if (A != 0) {
            A = i;
            break;
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << "? B " << i << '\n', cout.flush();
        cin >> B;
        if (B != 0) {
            B = i;
            break;
        }
    }

    cout << "! " << A + B << '\n', cout.flush();

    return 0;
}