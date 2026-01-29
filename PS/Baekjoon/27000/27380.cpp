#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;
const int MAX_LOG = 60;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, Z;
    bool ans_chk = true;

    cin >> N;
    for (int i = 1; i < N; i++)
        cin >> A[i];

    A[0] = A[N] = B[0] = B[N + 1] = (1ll << MAX_LOG) - 1;
    for (int i = 1; i <= N; i++)
        B[i] = A[i - 1] & A[i];

    for (int i = MAX_LOG - 1; i >= 0; i--)
        for (int j = 1; j <= N; j++) {
            X = B[j - 1] >> i, Y = B[j] >> i, Z = B[j + 1] >> i;
            if ((X < Y || j == 1) && Y == Z && (Y & 1)) {
                B[j] ^= 1ll << i;
                if ((B[j - 1] | B[j]) != A[j - 1] || (B[j] | B[j + 1]) != A[j])
                    B[j] ^= 1ll << i;
            }
        }

    for (int i = 1; i < N; i++)
        ans_chk &= B[i] <= B[i + 1] && (B[i] | B[i + 1]) == A[i];

    if (ans_chk) {
        cout << "Yes" << '\n';
        for (int i = 1; i <= N; i++)
            cout << B[i] << ' ';
        cout << '\n';
    } else
        cout << "No" << '\n';

    return 0;
}