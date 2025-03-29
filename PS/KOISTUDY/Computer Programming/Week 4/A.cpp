#include <bits/stdc++.h>
using namespace std;

signed main() {
    string S;
    int X = 0;
    bool ans = true;

    cin >> S;

    for (char i : S) {
        if (i == '(')
            X++;
        else
            ans &= --X >= 0;
    }
    ans &= X == 0;

    cout << (ans ? "YES" : "NO") << '\n';
}