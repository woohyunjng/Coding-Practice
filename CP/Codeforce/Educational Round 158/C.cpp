#include <bits/stdc++.h>
#define int long long
#define MAX 100100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, K, res, X;
    string S;

    stack<int> st;

    cin >> T;

    while (T--) {
        cin >> N;
        cin >> S;

        X = 0;
        for (int i = 1; i < N; i += 2) {
            if (S[i] == ')')
                X++;
        }

        res = 0;

        for (int i = 1; i < N; i += 2) {
            if (st.empty())
                st.push(i - 1);
            else
                res += (i - 1 - st.top()), st.pop();

            if (S[i] == ')') {
                K = st.top(), st.pop();
                res += (i - K);
            } else
                st.push(i);
        }

        cout << res << '\n';
    }

    return 0;
}