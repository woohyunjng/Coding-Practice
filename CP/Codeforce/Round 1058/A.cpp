#include <bits/stdc++.h>
using namespace std;

const int MAX = 601;

int ans[MAX];

int query(vector<int> &arr) {
    cout << "? " << arr.size() << ' ';
    for (int i : arr)
        cout << i << ' ';
    cout << '\n', cout.flush();

    int res;
    cin >> res;
    return res;
}

void solve() {
    int N, X;
    vector<int> arr;

    cin >> N, fill(ans, ans + N * 2 + 1, 0);

    for (int i = 1; i <= N * 2; i++) {
        arr.push_back(i), X = query(arr);
        if (X != 0)
            ans[i] = X, arr.pop_back();
    }

    arr.clear();
    for (int i = N * 2; i >= 1; i--) {
        arr.push_back(i);
        if (ans[i] != 0)
            continue;

        X = query(arr);
        if (X != 0)
            ans[i] = X, arr.pop_back();
    }

    cout << "! ";
    for (int i = 1; i <= N * 2; i++)
        cout << ans[i] << ' ';
    cout << '\n', cout.flush();
}

signed main() {
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}