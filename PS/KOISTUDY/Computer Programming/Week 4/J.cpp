#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ansX = -1, ansY = 0;
    vector<int> st;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X;
        while (!st.empty() && st.back() <= X)
            st.pop_back();
        if ((int)st.size() > ansY)
            ansX = i, ansY = st.size();
        st.push_back(X);
    }

    cout << ansX << ' ' << ansY << '\n';

    return 0;
}