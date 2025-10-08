#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, S;
    bool ans;

    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            cin >> A[i];

        while (true) {
            S = accumulate(A, A + N, 0ll);
            if (S % 2 == 1 || K == 1)
                break;

            for (int i = 0; i < N; i++)
                A[i] >>= 1;
            K >>= 1;
        }

        ans = K == 1 ? S % 2 == 1 : true;
        cout << (ans ? 1 : 0);
    }

    cout << '\n';

    return 0;
}