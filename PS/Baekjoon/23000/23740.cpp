#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, E, X, K = -1, A, B;

    vector<tp> arr;
    vector<tp> ans;

    cin >> N;
    while (N--) {
        cin >> S >> E >> X;
        arr.push_back({S, E, X});
    }

    sort(arr.begin(), arr.end());
    for (tp i : arr) {
        if (K < i[0]) {
            if (K != -1)
                ans.push_back({A, K, B});
            A = i[0], K = i[1], B = i[2];
        } else
            K = max(K, i[1]), B = min(B, i[2]);
    }
    ans.push_back({A, K, B});

    cout << ans.size() << '\n';
    for (tp i : ans)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

    return 0;
}