#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int S[MAX];

void solve() {
    int N, M, C = 1, X;
    string _S;
    vector<int> ans;

    set<int> st;
    set<int>::iterator it;

    cin >> N >> M >> _S;
    for (int i = 1; i <= N; i++)
        S[i] = _S[i - 1] == 'B';

    for (int i = 1; i <= (N + M) * 3; i++)
        st.insert(i);

    for (int i = 1; i <= M; i++) {
        cin >> X, ans.push_back(X);
        if (st.find(X) == st.end())
            continue;
        st.erase(X);
    }

    for (int i = 1; i <= N; i++) {
        if (S[i] == 0)
            C++, ans.push_back(C), st.erase(C);
        else {
            X = *st.lower_bound(C + 1), ans.push_back(X);
            st.erase(X), C = *st.lower_bound(C + 1);
        }
    }

    sort(ans.begin(), ans.end()), ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
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