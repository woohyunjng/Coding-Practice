#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int ans = 0, K[5], X, N;
    vector<int> arr, val;
    cin >> K[0] >> K[1] >> K[2] >> K[3] >> K[4];

    for (int i = 0; i < 5; i++)
        arr.push_back(i);

    do {
        X = 0;
        for (int i = 0; i < 5; i++)
            X = X * 10 + K[arr[i]];
        if (K[arr[0]] != 0)
            val.push_back(X);
    } while (next_permutation(arr.begin(), arr.end()));

    sort(val.begin(), val.end()), val.erase(unique(val.begin(), val.end()), val.end());
    N = val.size();

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            for (int k = j + 1; k < N; k++) {
                if (find(val.begin(), val.end(), val[i] + val[j] + val[k]) != val.end())
                    ans++;
            }

    cout << ans << '\n';

    return 0;
}