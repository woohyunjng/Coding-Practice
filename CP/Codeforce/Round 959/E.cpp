#include <bits/stdc++.h>
#define int long long
#define MAX_LOG 20

using namespace std;
int arr[MAX_LOG];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, K, N, res, cur, X, Y;
    cin >> T;

    while (T--) {
        cin >> K;
        res = 0;

        fill(arr, arr + MAX_LOG, 0);

        for (int i = 1; i <= K; i++) {
            cin >> N;
            for (int i = 2; i <= N; i++)
                cin >> X;
            for (int j = 0, k = 1; k <= N; j++, k <<= 1) {
                if (N & k)
                    arr[j]++;
            }
        }

        for (int j = MAX_LOG - 1; j >= 0; j--) {
            if (arr[j] > 1) {
                res += (1 << (j + 1)) - 1;
                break;
            } else if (arr[j] == 1)
                res += 1 << j;
        }

        cout << res << '\n';
    }

    return 0;
}