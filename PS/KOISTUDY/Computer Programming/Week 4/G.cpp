#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    vector<char> st;

    cin >> S;

    for (char i : S) {
        if (i == '(')
            st.push_back('(');
        else if (i == ')') {
            while (!st.empty() && st.back() != '(')
                cout << st.back(), st.pop_back();
            st.pop_back();
        } else if (i == '+' || i == '-') {
            while (!st.empty() && st.back() != '(')
                cout << st.back(), st.pop_back();
            st.push_back(i);
        } else if (i == '*' || i == '/') {
            while (!st.empty() && (st.back() == '*' || st.back() == '/'))
                cout << st.back(), st.pop_back();
            st.push_back(i);
        } else
            cout << i;
    }

    while (!st.empty())
        cout << st.back(), st.pop_back();
    cout << '\n';

    return 0;
}