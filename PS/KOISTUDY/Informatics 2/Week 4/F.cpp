#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K;
    string S;

    stack<int> st;

    cin >> N >> S;

    st.push(N);

    for (char i : S) {
        K = st.top(), st.pop();
        if (i == '-') {
            st.push(K >> 1);
            st.push(K >> 1);
        } else
            cout << string(K, i);
    }

    return 0;
}