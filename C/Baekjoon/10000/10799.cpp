#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string S;
    int res = 0;
    stack<int> st;

    cin >> S;

    for (int i = 0 ; i < S.size() ; i ++) {
        if (S[i] == '(')
            st.push(i);
        else {
            int p = st.top();
            st.pop();

            if (i - p == 1)
                res += st.size();
            else
                res += 1;
        }
    }

    cout << res;
}
