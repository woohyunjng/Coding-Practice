#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, T, ans = -1, L, R;
    vector<pr> arr, tmp;

    cin >> N >> T, arr.push_back({1, 1});
    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 1; i <= T; i++) {
        cin >> L >> R, tmp = arr, arr.clear();
        for (pr j : tmp) {
            j[0] = max(j[0] - 1, 1), j[1] = min(j[1] + 1, N);
            if (!arr.empty() && arr.back()[1] >= j[0])
                arr[arr.size() - 1][1] = max(arr.back()[1], j[1]);
            else
                arr.push_back(j);
        }
        if (!arr.empty() && arr.back()[1] == N && ans == -1)
            ans = i;

        tmp = arr, arr.clear();
        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j][0] < L && tmp[j][1] >= L)
                arr.push_back({tmp[j][0], L - 1});
            if (tmp[j][1] > R && tmp[j][0] <= R)
                arr.push_back({R + 1, tmp[j][1]});
            if (tmp[j][0] > R || tmp[j][1] < L)
                arr.push_back(tmp[j]);
        }
    }
    if (ans == -1 && !arr.empty())
        ans = T + N - arr.back()[1];

    cout << ans << '\n';

    return 0;
}