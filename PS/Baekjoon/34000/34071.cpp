#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int X[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, mn = 1001, mx = -1;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
        mn = min(mn, X[i]), mx = max(mx, X[i]);
    }

    if (X[1] == mn)
        cout << "ez\n";
    else if (X[1] == mx)
        cout << "hard\n";
    else
        cout << "?\n";

    return 0;
}