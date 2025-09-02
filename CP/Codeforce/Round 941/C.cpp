#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

void solve() {
    int N, X = 1, ans = 1, B = -1;
    bool flipped = false;

    vector<int> st;
    deque<int> dq;
    string S;

    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        st.push_back(S[i - 1] - '0');
        if (st.size() >= 3 && st[(int)st.size() - 3] == st[(int)st.size() - 2] && st[(int)st.size() - 2] == st[(int)st.size() - 1])
            st.pop_back(), st.pop_back();
    }

    for (int i : st) {
        if (B == -1)
            B = i;
        else if (B == i)
            flipped = !flipped;
        else {
            if (!flipped)
                ans = max(ans, ++X);
            else {
                X--;
                if (X <= 0)
                    ans++, X = 1;
            }
        }
        B = i;
    }

    cout << ans << '\n';
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