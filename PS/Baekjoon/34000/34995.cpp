#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, T, V = "";
    int N;

    cin >> N >> S >> T;
    for (char i : S)
        V += i == '?' ? '9' : i;

    if (V.size() < T.size() || (V.size() == T.size() && V < T))
        cout << -1 << '\n';
    else
        cout << V << '\n';

    return 0;
}