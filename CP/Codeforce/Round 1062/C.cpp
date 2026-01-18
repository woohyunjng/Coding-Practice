#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int A[MAX];

void solve() {
    int N, C[2] = {0, 0};

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i], C[A[i] & 1]++;

    if (C[0] > 0 && C[1] > 0)
        sort(A, A + N);
    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}