#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0, V;
    vector<int> arr[4];

    cin >> N;
    while (N--) {
        cin >> X;
        if (X > 1)
            arr[0].push_back(X);
        else if (X < 0)
            arr[1].push_back(X);
        else if (X == 0)
            arr[2].push_back(X);
        else if (X == 1)
            arr[3].push_back(X);
    }

    sort(arr[0].begin(), arr[0].end()), sort(arr[1].begin(), arr[1].end(), greater<int>());
    for (int i = 0; i < 2; i++) {
        while (arr[i].size() > 1) {
            V = arr[i].back(), arr[i].pop_back();
            V *= arr[i].back(), arr[i].pop_back();
            ans += V;
        }
    }

    if (arr[1].size() == 1 && arr[2].size() != 0)
        arr[1].pop_back();
    if (arr[0].size() == 1)
        ans += arr[0][0];
    if (arr[1].size() == 1)
        ans += arr[1][0];
    ans += arr[3].size();

    cout << ans << '\n';

    return 0;
}