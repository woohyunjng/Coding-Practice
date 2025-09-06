#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, X, S = 0;
    vector<int> arr;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> X, arr.push_back(X);

    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i < K; i++)
        S += arr[i];
    S -= K * (K - 1) / 2;

    cout << S << '\n';

    return 0;
}