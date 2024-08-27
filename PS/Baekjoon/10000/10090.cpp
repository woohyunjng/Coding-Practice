#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long

#define MAX 1001000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res = 0;
    cin >> N;

    ordered_set os;
    for (int i = 1; i <= N; i++) {
        cin >> X;
        res += (i - 1) - os.order_of_key(X + 1);
        os.insert(X);
    }

    cout << res;

    return 0;
}