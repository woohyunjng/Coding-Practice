#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define INF 0x7f7f7f7f7f7f7f7f

using namespace std;

map<int, vector<int>> val;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    multiset<int> st;
    multiset<int>::iterator it;
    vector<int> arr;

    int N, K, A, B, res = -INF;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        arr.push_back(A), val[A].push_back(B);
    }
    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i : arr) {
        for (int j : val[i])
            st.insert(j);
    }

    for (int i : arr) {
        for (int j : val[i])
            st.erase(st.find(j));
        for (int j : val[i]) {
            it = st.upper_bound(K - j);
            if (it != st.begin())
                res = max(res, j + *prev(it));
        }
        for (int j : val[i])
            st.insert(j);
    }

    if (res == -INF)
        cout << "NO\n";
    else
        cout << res << '\n';

    return 0;
}