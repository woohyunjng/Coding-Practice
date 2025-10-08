#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, V;

    cin >> T;
    while (T--) {
        cin >> N, V = 0;
        for (int i = 0; i < N; i++)
            cin >> A[i];

        if (N & 1) {
            V ^= A[0];
            for (int i = 1; i < N; i += 2)
                V ^= A[i + 1] - A[i];
        } else
            for (int i = 0; i < N; i += 2)
                V ^= A[i + 1] - A[i];

        cout << (V ? "TAK" : "NIE") << '\n';
    }

    return 0;
}