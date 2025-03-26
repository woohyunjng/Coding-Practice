#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;

int val[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, N, T, X = 0, Y, Z, ans;

    for (int i = 0; i < (1 << 12); i++) {
        if (__builtin_popcount(i) != 6)
            continue;
        val[X++] = i;
    }

    cin >> K >> N >> T;
    while (T--) {
        cin >> X >> Y, X = val[X];

        if (K == 1) {
            Y = val[Y];
            for (int i = 11; i >= 0; i--) {
                if ((X & (1 << i)) && !(Y & (1 << i)))
                    ans = i + 1;
            }
            cout << ans << '\n';
        } else {
            if (X & (1 << (Y - 1)))
                cout << "yes" << '\n';
            else
                cout << "no" << '\n';
        }
    }
}