#include <bits/stdc++.h>
using namespace std;

signed main() {
    int N, C[5] = {0}, X;

    cin >> N;
    while (N--)
        cin >> X, C[X - 1]++;

    cout << (*min_element(C, C + 5) == 0 ? "YES" : "NO") << '\n';

    return 0;
}