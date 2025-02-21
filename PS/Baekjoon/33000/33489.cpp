#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 40;

int F[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, X, Y, st, en, mid, A, B;
    cin >> T;

    F[1] = F[2] = 1;
    for (int i = 3; i < MAX; i++)
        F[i] = F[i - 1] + F[i - 2];

    while (T--) {
        cin >> X >> Y;
        st = 1, en = MAX - 1;
        while (st <= en) {
            mid = st + en >> 1;
            if (F[mid] <= X)
                st = mid + 1, A = mid;
            else
                en = mid - 1;
        }

        st = 1, en = MAX - 1;
        while (st <= en) {
            mid = st + en >> 1;
            if (F[mid] <= Y)
                st = mid + 1, B = mid;
            else
                en = mid - 1;
        }

        if (B >= A - 1)
            B = A - 1;
        else
            A = B + 1;
        cout << F[A] << ' ' << F[B] << '\n';
    }

    return 0;
}