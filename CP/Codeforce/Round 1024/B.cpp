#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX = 200001;

int A[MAX], ans[MAX], idx[MAX];

ordered_set st;

int get_inv(vector<int> &arr) {
    int res = 0;
    for (int i : arr)
        res += st.size() - st.order_of_key(i), st.insert(i);
    st.clear();
    return res;
}

void solve() {
    int N, X, Y;

    priority_queue<int, vector<int>, greater<int>> pq[2];
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i], pq[i & 1].push(A[i]), idx[A[i]] = i;

    for (int i = 1; i <= N; i++)
        ans[i] = pq[i & 1].top(), pq[i & 1].pop();

    arr.clear();
    for (int i = 2; i <= N; i += 2)
        arr.push_back(A[i]);
    X = get_inv(arr);

    arr.clear();
    for (int i = 1; i <= N; i += 2)
        arr.push_back(A[i]);
    Y = get_inv(arr);

    if ((X & 1) != (Y & 1))
        swap(ans[N - 2], ans[N]);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
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