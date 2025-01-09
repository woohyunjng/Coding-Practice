#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A = 0, B = 1;
    cin >> N;

    while (N--)
        B = (A += B) - B;

    cout << A << '\n';

    return 0;
}