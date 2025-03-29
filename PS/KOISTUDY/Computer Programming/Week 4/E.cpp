#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> st;
    string S;

    int ans = 0, X = 1, N;
    bool flag = true;

    cin >> S, N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == '(')
            st.push_back(0), X *= 2;
        else if (S[i] == '[')
            st.push_back(1), X *= 3;
        else if (S[i] == ')') {
            if (st.empty() || st.back() != 0) {
                flag = false;
                break;
            }
            if (S[i - 1] == '(')
                ans += X;
            st.pop_back(), X /= 2;
        } else if (S[i] == ']') {
            if (st.empty() || st.back() != 1) {
                flag = false;
                break;
            }
            if (S[i - 1] == '[')
                ans += X;
            st.pop_back(), X /= 3;
        }
    }

    flag &= st.empty();
    if (!flag)
        ans = 0;
    cout << ans << '\n';

    return 0;
}