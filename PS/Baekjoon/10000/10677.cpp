#include <bits/stdc++.h>
#define int long long

using namespace std;

int val(string S, int K) { return (S[0] - '0') * K * K + (S[1] - '0') * K + (S[2] - '0'); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, A, B, VX, VY;
    string X, Y;
    cin >> T;

    while (T--) {
        cin >> X >> Y;
        A = B = 10;

        while (A <= 15000 && B <= 15000) {
            VX = val(X, A), VY = val(Y, B);
            if (VX == VY) {
                cout << A << " " << B << '\n';
                break;
            } else if (VX < VY) {
                A++;
            } else {
                B++;
            }
        }
    }

    return 0;
}