#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, T, X;
    vector<int> st;

    for (int i = 0; i < 100; i++)
        st.push_back(0);

    cin >> Q;
    while (Q--) {
        cin >> T;
        if (T == 1)
            cin >> X, st.push_back(X);
        else
            cout << st.back() << '\n', st.pop_back();
    }

    return 0;
}