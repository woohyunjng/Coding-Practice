#include <bits/stdc++.h>
#define int long long

#define MAX 1000100

using namespace std;
typedef pair<int, int> pr;

int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    vector<pr> arr;
    set<int> st;
    set<int>::iterator iter, it1, it2;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr.push_back({A[i], i});
    sort(arr.begin(), arr.end());

    st.insert(0), st.insert(N + 1);

    for (pr i : arr) {
        iter = st.insert(i.second).first;
        it1 = next(iter), it2 = prev(iter);

        if (*it1 != N + 1)
            res = max(res, (A[*it1] + i.first) * (*next(it1) - *it2 - 1));
        if (*it2 != 0)
            res = max(res, (A[*it2] + i.first) * (*it1 - *prev(it2) - 1));
    }

    cout << res << '\n';

    return 0;
}