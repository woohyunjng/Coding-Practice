#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, S, E, ans;

    vector<pr> arr;
    multiset<int> st;
    multiset<int>::iterator it;

    cin >> T;
    while (T--) {
        cin >> N, ans = 0, st.clear(), arr.clear();
        for (int i = 0; i < N; i++)
            cin >> S >> E, arr.push_back({S, E});

        sort(arr.begin(), arr.end());
        for (pr i : arr) {
            if (st.empty() || (*st.begin()) > i[0])
                ans -= i[0], st.insert(i[1]);
            else {
                it = prev(st.lower_bound(i[0] + 1));
                st.erase(it), st.insert(i[1]);
            }
        }

        for (int i : st)
            ans += i;
        cout << st.size() << ' ' << ans << '\n';
    }

    return 0;
}