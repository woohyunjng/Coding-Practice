#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 20001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0, X = 1;
    string S;

    cin >> N >> K >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] == 'H' ? 1 : 0;

    for (int i = 1; i <= N; i++) {
        if (A[i] == 1) {
            X = max(X, i - K);
            for (int j = X; j <= min(N, i + K); j++) {
                if (A[j] == 0) {
                    ans++, X = j + 1;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}