#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef array<int, 2> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, ans, X, Y;
    vector<pr> arr;

    cin >> N >> M, ans = M;

    while (N--) {
        cin >> X >> Y;
        if (X <= Y)
            continue;
        arr.push_back({Y, X});
    }

    sort(arr.begin(), arr.end()), X = -1, Y = -1;

    for (pr i : arr) {
        if (Y < i[0]) {
            if (Y != -1)
                ans += (Y - X) * 2;
            X = i[0], Y = i[1];
        } else
            Y = max(Y, i[1]);
    }

    if (Y != -1)
        ans += (Y - X) * 2;
    cout << ans << '\n';

    return 0;
}