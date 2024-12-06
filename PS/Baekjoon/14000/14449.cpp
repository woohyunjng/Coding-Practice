#include <bits/stdc++.h>

#define MAX 100100

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

int L[MAX], R[MAX], A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, X, Y;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    ordered_set tree;
    for (int i = 1; i <= N; i++) {
        L[i] = tree.order_of_key(-A[i]);
        tree.insert(-A[i]);
    }

    tree.clear();
    for (int i = N; i >= 1; i--) {
        R[i] = tree.order_of_key(-A[i]);
        tree.insert(-A[i]);
    }

    for (int i = 1; i <= N; i++) {
        X = min(L[i], R[i]), Y = max(L[i], R[i]);
        res += Y > 2 * X;
    }

    cout << res << '\n';

    return 0;
}