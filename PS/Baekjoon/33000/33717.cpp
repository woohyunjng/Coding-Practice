#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;

int A[MAX], V[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X;
    bool flag = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    K = N - A[N];

    V[1] = 1, V[N] = 0;

    for (int i = 2; i <= K; i++) {
        if (A[i] - A[i - 1] == 0)
            V[i] = V[i - 1];
        else if (A[i] - A[i - 1] == K - (i - 1))
            flag &= V[i - 1] == 0, V[i] = 1;
        else if (A[i] - A[i - 1] == (i - 1) - K)
            flag &= V[i - 1] == 1, V[i] = 0;
        else
            flag = false;
    }

    for (int i = N - 1; i >= K + 1; i--) {
        if (A[i + 1] - A[i] == 0)
            V[i] = V[i + 1];
        else if (A[i + 1] - A[i] == K - i)
            flag &= V[i + 1] == 1, V[i] = 0;
        else if (A[i + 1] - A[i] == i - K)
            flag &= V[i + 1] == 0, V[i] = 1;
        else
            flag = false;
    }

    for (int i = 1; i <= N; i++) {
        B[i] = B[i - 1] + (V[i] == 0);
        if (V[i])
            flag &= B[i] == K - A[i];
        else
            flag &= B[i] == i - A[i];
    }

    if (!flag)
        cout << -1 << '\n';
    else {
        for (int i = 1; i <= N; i++)
            cout << V[i] << ' ';
        cout << '\n';
    }

    return 0;
}