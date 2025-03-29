#include <bits/stdc++.h>
using namespace std;

signed main() {
    string S;
    vector<char> st;

    bool ans = true;

    cin >> S;

    for (char i : S) {
        if (i == '(')
            st.push_back(i);
        else if (i == '[')
            st.push_back(i);
        else if (i == '{')
            st.push_back(i);
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
        } else if (i == '}') {
            if (st.empty() || st.back() != '{') {
                ans = false;
                break;
            }
            st.pop_back();
        }
    }
    ans &= st.empty();

    cout << (ans ? "O" : "X") << '\n';
}