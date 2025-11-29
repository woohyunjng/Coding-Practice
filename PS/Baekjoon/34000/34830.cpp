#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    if (N & 1)
        cout << N * (N - 1) / 2 << '\n';
    else
        cout << N * N / 2 - 1 << '\n';

    return 0;
}