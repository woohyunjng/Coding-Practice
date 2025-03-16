#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;

int A[1 << MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ansX = -1, ansY = -1;

    cin >> N;
    for (int i = 0; i < (1 << N); i++)
        cin >> A[i];

    for (int i = 0; i < (1 << N); i++)
        for (int j = 0; j < N; j++)
            for (int k = j + 1; k < N; k++) {
                if ((i & (1 << j)) || (i & (1 << k)))
                    continue;
                if (A[i ^ (1 << j)] + A[i ^ (1 << k)] < A[i] + A[i ^ (1 << j) ^ (1 << k)])
                    ansX = i ^ (1 << j), ansY = i ^ (1 << k);
            }

    if (ansX == -1)
        cout << -1 << '\n';
    else
        cout << ansX << ' ' << ansY << '\n';
}