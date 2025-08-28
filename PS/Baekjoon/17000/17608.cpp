#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X;
    vector<int> st;

    cin >> N;
    while (N--) {
        cin >> X;
        while (!st.empty() && st.back() <= X)
            st.pop_back();
        st.push_back(X);
    }

    cout << st.size() << '\n';

    return 0;
}