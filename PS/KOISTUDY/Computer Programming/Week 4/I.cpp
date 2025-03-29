#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S, ans = "";
    vector<char> st;
    char X;

    cin >> S;
    for (char i : S) {
        X = i;
        while (!st.empty() && st.back() == X)
            X = (X - 'a' + 1) % 3 + 'a', st.pop_back();
        st.push_back(X);
    }

    for (char i : st)
        ans += i;

    cout << ans << '\n';

    return 0;
}