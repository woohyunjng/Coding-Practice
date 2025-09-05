#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = MAX, V, X;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] == 'R' ? 1 : 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++)
            A[j] ^= 1;

        V = 0, X = 1;
        for (int j = 1; j <= N; j++) {
            if (A[j] == 0)
                V += X != j, X++;
        }
        ans = min(ans, V);

        V = 0, X = N;
        for (int j = N; j >= 1; j--) {
            if (A[j] == 0)
                V += X != j, X--;
        }
        ans = min(ans, V);
    }

    cout << ans << '\n';

    return 0;
}