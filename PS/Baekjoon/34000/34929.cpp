#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1);

    if (N == 1)
        cout << A[1] << '\n';
    else {
        cout << A[N - 1] << '\n', X = A[1];
        for (int i = 2; i <= N - 3; i += 2)
            cout << X << ' ' << A[i] << ' ' << A[i + 1] << '\n', X = A[i];
        cout << X << ' ' << A[N - 1] << ' ' << A[N] << '\n';
    }

    return 0;
}