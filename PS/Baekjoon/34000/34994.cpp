#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

bool chk(string S) {
    vector<char> st;
    char K;

    for (char i : S) {
        if (i == '(' || i == '[' || i == '{')
            st.push_back(i);
        else {
            if (st.empty())
                return false;
            K = st.back(), st.pop_back();
            if ((i == ')' && K != '(') || (i == ']' && K != '[') || (i == '}' && K != '{'))
                return false;
        }
    }
    return st.empty();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    bool flag;
    string S, V;

    cin >> T;
    while (T--) {
        cin >> S, flag = false;
        if (chk(S))
            cout << "YES 0" << '\n';
        else {
            for (int i = 0; i < S.size(); i++) {
                for (char j : {'(', ')', '[', ']', '{', '}'}) {
                    V = S, V.erase(V.begin() + i), V.insert(V.begin() + i, j);
                    if (chk(V)) {
                        cout << "YES 1" << '\n';
                        cout << i + 1 << ' ' << j << '\n';
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
                cout << "NO" << '\n';
        }
    }

    return 0;
}