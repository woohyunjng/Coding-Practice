#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Y, C, P;

    cin >> Y >> C >> P;
    cout << min({Y, C / 2, P}) << '\n';

    return 0;
}