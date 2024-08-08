#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    stack<int> st;

    cin >> S;

    for (char i : S) {
        if (i == '(')
            st.push(1);
        else if (i == '[')
            st.push(2);
        else if (i == ')') {
            if (st.empty() || st.top() != 1) {
                cout << "NO";
                return 0;
            }
            st.pop();
        } else {
            if (st.empty() || st.top() != 2) {
                cout << "NO";
                return 0;
            }
            st.pop();
        }
    }

    if (st.empty())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}