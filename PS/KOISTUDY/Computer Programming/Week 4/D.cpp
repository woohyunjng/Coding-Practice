#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0;
    string S;

    bool flag = true;
    vector<char> ans;

    vector<int> st;

    cin >> N >> S;
    for (int i = 1; i <= N; i++)
        A[S[i - 1] - '0'] = i;

    for (int i = 1; i <= N; i++) {
        while (X < A[i])
            st.push_back(++X), ans.push_back(1);
        if (st.empty() || st.back() != A[i]) {
            flag = false;
            break;
        }
        st.pop_back(), ans.push_back(0);
    }

    if (!flag)
        cout << -1 << '\n';
    else
        for (int i : ans)
            cout << (i ? "push" : "pop") << '\n';

    return 0;
}