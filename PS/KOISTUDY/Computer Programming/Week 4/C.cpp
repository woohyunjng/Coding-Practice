#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0;
    bool flag = true;
    vector<char> ans;

    vector<int> st;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        while (X < A[i])
            st.push_back(++X), ans.push_back('+');
        if (st.empty() || st.back() != A[i]) {
            flag = false;
            break;
        }
        st.pop_back(), ans.push_back('-');
    }

    if (!flag)
        cout << "NO" << '\n';
    else
        for (char i : ans)
            cout << i << '\n';

    return 0;
}