#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, X, Y;
    vector<int> arr;

    cin >> N;
    while (N--)
        cin >> X, arr.push_back(X);

    sort(arr.begin(), arr.end());

    cin >> M;
    while (M--) {
        cin >> X;
        Y = lower_bound(arr.begin(), arr.end(), X) - arr.begin();
        cout << (Y < arr.size() && arr[Y] == X) << '\n';
    }

    return 0;
}