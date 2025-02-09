#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cnt = 0, X;
    bool ans = true, chk = false;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], cnt += A[i] == 0;

    if (cnt == 0)
        ans = true;
    else if (cnt == N)
        ans = N % 4 == 0;
    else {
        X = N;
        while (X >= 1 && A[X] == 0)
            X--;
        for (int i = X; i >= 1; i--)
            A[i + N - X] = A[i];
        for (int i = X; i < N; i++)
            A[i - X + 1] = 0;

        X = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] == 0)
                break;
            X++;
        }

        for (int i = X + 1; i <= N; i++) {
            if (A[i]) {
                chk = true;
                continue;
            }

            if (B[i] == 0 || B[i] == 1) {
                B[i] = 1, B[i + 1] = 2, B[i + 2] = 3;
                if (i == N)
                    ans &= X >= 2 || (X == 1 && chk);
                else if (i == N - 1)
                    ans &= X >= 1 || chk;
                i++;
            } else if (B[i] == 3) {
                B[i + 1] = 2, B[i + 2] = 1;
                if (i == N)
                    ans &= X >= 2 || (X == 1 && (chk || B[2] == 1));
                else if (i == N - 1)
                    ans &= X >= 1 || chk;
                i++;
            } else if (B[i] == 2)
                ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}