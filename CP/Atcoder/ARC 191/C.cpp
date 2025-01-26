#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, A, M, X;
    vector<int> arr;
    cin >> T;

    while (T--) {
        cin >> N;
        if (N == 1)
            A = 1, M = 2;
        else {
            arr.clear(), A = 1, M = N;
            for (int i = 2; i * i <= N; i++) {
                if (N % i)
                    continue;
                arr.push_back(i), X = 0;
                while (!(N % i))
                    N /= i, X++;
                if (i == 2) {
                    while (X--)
                        A *= 2, M *= 2;
                } else
                    A *= i, M *= i;
            }
            if (N > 1)
                arr.push_back(N), A *= N, M *= N;
            A++;
        }

        cout << A << ' ' << M << '\n';
    }

    return 0;
}