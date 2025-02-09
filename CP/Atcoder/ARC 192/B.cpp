#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K = 0;
    bool ans = true;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i], K += A[i] & 1;

    if (N == 1)
        ans = true;
    else if (N == 2)
        ans = false;
    else if (N == 3)
        ans = K >= 1;
    else
        ans = K % 2 == 1;

    cout << (ans ? "Fennec" : "Snuke") << '\n';

    return 0;
}