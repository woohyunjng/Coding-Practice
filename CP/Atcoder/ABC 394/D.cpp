#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    vector<char> st;

    bool ans = true;

    cin >> S;
    for (char i : S) {
        if (i == '(')
            st.push_back('(');
        else if (i == '[')
            st.push_back('[');
        else if (i == '<')
            st.push_back('<');
        else if (i == ')') {
            if (st.empty() || st.back() != '(') {
                ans = false;
                break;
            }
            st.pop_back();
        } else if (i == ']') {
            if (st.empty() || st.back() != '[') {
                ans = false;
                break;
            }
            st.pop_back();
        } else if (i == '>') {
            if (st.empty() || st.back() != '<') {
                ans = false;
                break;
            }
            st.pop_back();
        }
    }

    ans &= st.empty();
    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}