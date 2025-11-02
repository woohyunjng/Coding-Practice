#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 3> tp;

const int INF = 1e9 + 1;

int sq(int X) { return X * X; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int G, N, X, Y, T, ans = 0, A;
    bool flag;
    vector<tp> arr;

    cin >> G >> N;
    while (G--) {
        cin >> X >> Y >> T;
        arr.push_back({T, X, Y});
    }

    sort(arr.begin(), arr.end());

    while (N--) {
        cin >> X >> Y >> T, flag = true;
        A = lower_bound(arr.begin(), arr.end(), tp{T, -INF, -INF}) - arr.begin();
        if (A < arr.size())
            flag &= sq(arr[A][1] - X) + sq(arr[A][2] - Y) <= sq(arr[A][0] - T);
        if (A > 0)
            flag &= sq(arr[A - 1][1] - X) + sq(arr[A - 1][2] - Y) <= sq(T - arr[A - 1][0]);
        ans += !flag;
    }

    cout << ans << '\n';

    return 0;
}