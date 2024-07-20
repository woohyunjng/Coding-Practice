#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, cur = 1, val = 9, K;
    cin >> N;

    if (N-- == 1) {
        cout << 0;
        return 0;
    }

    stack<int> st;

    while (N > val) {
        N -= val;
        cur++;
        if (cur % 2)
            val *= 10;
    }

    if (cur == 1) {
        cout << N;
        return 0;
    }

    K = (N + val / 9 - 1) / (val / 9);
    N %= val / 9;
    cout << K;
    st.push(K);
    val /= 9;
    cur -= 2;

    while (cur > 0) {
        K = (((N + val / 10 - 1) / (val / 10) - 1) + 10) % 10;
        N %= val / 10;
        cout << K;
        if (cur != 1)
            st.push(K);
        val /= 10;
        cur -= 2;
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}