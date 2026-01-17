#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int A[MAX], S[MAX][2];

void solve() {
    int N;
    bool ans = true;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    sort(A + 1, A + N + 1);

    set<int> st;

    for (int i = 0; i <= N; i++)
        st.insert(i);
    for (int i = 1; i <= N; i++) {
        if (st.find(A[i]) != st.end())
            st.erase(A[i]);
        S[i][0] = *st.begin();
    }

    for (int i = 0; i <= N; i++)
        st.insert(i);
    for (int i = N; i >= 1; i--) {
        if (st.find(A[i]) != st.end())
            st.erase(A[i]);
        S[i][1] = *st.begin();
    }

    for (int i = 1; i + 1 <= N; i++)
        ans &= S[i][0] != S[i + 1][1];
    cout << (ans ? "YES" : "NO") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}