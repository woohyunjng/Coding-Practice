#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    if (N == 2)
        cout << 1 << '\n';
    else if (N == 3)
        cout << 3 << '\n';
    else
        cout << (N - 2) * 2 + N << '\n';

    return 0;
}