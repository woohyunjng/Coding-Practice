#include <bits/stdc++.h>

using namespace std;
typedef array<int, 2> pr;

const int MAX = 1000001;

set<pr> st;
vector<pr> in[MAX], out[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, L, R, C;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> L >> R >> C;
        in[L].push_back({i, C});
        out[R + 1].push_back({i, C});
    }

    for (int i = 1; i <= N; i++) {
        for (pr j : in[i])
            st.insert(j);
        for (pr j : out[i])
            st.erase(j);

        cout << (st.empty() ? 0 : (*st.rbegin())[1]) << ' ';
    }
    cout << '\n';

    return 0;
}