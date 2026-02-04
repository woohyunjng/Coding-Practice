#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 21;

int A[1 << MAX], L, dp[2][1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y, C[3], ans;
    string _S, S;

    vector<int> arr;

    cin >> L >> Q >> _S;
    for (int i = 0; i < (1 << L); i++) {
        A[i] = _S[i] - '0', dp[0][i] = A[i];
        X = ((1 << L) - 1) ^ i, dp[1][X] = A[i];
    }

    for (int i = 0; i < L; i++)
        for (int j = (1 << L); j >= 0; j--) {
            dp[0][j] = dp[0][j] + (j & (1 << i) ? dp[0][j ^ (1 << i)] : 0);
            dp[1][j] = dp[1][j] + (j & (1 << i) ? dp[1][j ^ (1 << i)] : 0);
        }

    while (Q--) {
        cin >> S, X = Y = ans = 0, arr.clear(), C[0] = C[1] = C[2] = 0;
        for (int i = 0; i < L; i++) {
            X <<= 1, Y <<= 1, Y ^= 1;
            if (S[i] == '0')
                C[0]++;
            else if (S[i] == '1')
                X |= 1, C[1]++;
            else
                Y ^= 1, arr.push_back(L - i - 1), C[2]++;
        }

        if (C[2] <= L / 3) {
            for (int i = 0; i < (1 << arr.size()); i++) {
                Y = X;
                for (int j = 0; j < arr.size(); j++)
                    if (i & (1 << j))
                        Y |= 1 << arr[j];
                ans += A[Y];
            }
        } else if (C[1] <= L / 3) {
            Y = X;
            for (int i : arr)
                Y |= 1 << i;
            arr.clear();
            for (int i = 0; i < L; i++)
                if (X & (1 << i))
                    arr.push_back(i);
            for (int i = 0; i < (1 << arr.size()); i++) {
                X = Y;
                for (int j = 0; j < arr.size(); j++)
                    if (!(i & (1 << j)))
                        X ^= 1 << arr[j];
                if (__builtin_popcount(i) % 2)
                    ans -= dp[0][X];
                else
                    ans += dp[0][X];
            }
        } else if (C[0] <= L / 3) {
            X = Y = 0;
            for (int i = 0; i < L; i++)
                X = X << 1 | (S[i] == '0');
            Y = X;
            for (int i : arr)
                Y |= 1 << i;
            arr.clear();
            for (int i = 0; i < L; i++)
                if (X & (1 << i))
                    arr.push_back(i);
            for (int i = 0; i < (1 << arr.size()); i++) {
                X = Y;
                for (int j = 0; j < arr.size(); j++)
                    if (!(i & (1 << j)))
                        X ^= 1 << arr[j];
                if (__builtin_popcount(i) % 2)
                    ans -= dp[1][X];
                else
                    ans += dp[1][X];
            }
        }
        cout << abs(ans) << '\n';
    }

    return 0;
}