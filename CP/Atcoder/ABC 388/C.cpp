#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, res = 0;
    vector<int> arr;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X, arr.push_back(X);
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
        res += upper_bound(arr.begin(), arr.end(), arr[i] / 2) - arr.begin();

    cout << res << '\n';

    return 0;
}