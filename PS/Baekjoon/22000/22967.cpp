#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 301;

bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V;

    set<pr> st;
    vector<int> ans;

    cin >> N;
    for (int i = 1; i < N; i++)
        for (int j = i + 1; j <= N; j++)
            st.insert({i, j});

    for (int i = 1; i < N; i++) {
        cin >> U >> V;
        if (V == 1)
            swap(U, V);
        if (U == 1)
            chk[V] = true;

        if (U > V)
            swap(U, V);
        if (N <= 4)
            st.erase({U, V});
    }

    if (N <= 4) {
        cout << st.size() << '\n';
        cout << 1 << '\n';
        for (pr i : st)
            cout << i[0] << ' ' << i[1] << '\n';
    } else {
        for (int i = 2; i <= N; i++)
            if (!chk[i])
                ans.push_back(i);
        cout << ans.size() << '\n';
        cout << 2 << '\n';
        for (int i : ans)
            cout << 1 << ' ' << i << '\n';
    }

    return 0;
}