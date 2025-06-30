#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, ans = 0;
    vector<int> arr, val;
    set<int> st;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X, arr.push_back(X);

    sort(arr.begin(), arr.end()), arr.erase(unique(arr.begin(), arr.end()), arr.end()), N = arr.size();
    X = arr[0] / 4;

    if (N <= 3)
        ans = X * (X + 1) / 2;
    else {
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++) {
                Y = arr[j] - arr[i];
                for (int k = 1; k * k <= Y; k++) {
                    if (Y % k == 0)
                        val.push_back(k), val.push_back(Y / k);
                }
            }

        sort(val.begin(), val.end()), val.erase(unique(val.begin(), val.end()), val.end());
        for (int i : val) {
            if (i > X)
                continue;
            for (int j : arr)
                st.insert(j % i);
            if (st.size() <= 3)
                ans += i;
            st.clear();
        }
    }

    cout << ans << '\n';

    return 0;
}