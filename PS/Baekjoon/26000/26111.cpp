#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, ans = 0;
    string S;

    vector<int> arr;

    cin >> S, N = S.size();
    for (int i = 0; i < N; i++) {
        if (S[i] == '(')
            arr.push_back(i);
        else {
            X = arr.back(), arr.pop_back();
            if (X + 1 == i)
                ans += arr.size();
        }
    }

    cout << ans << '\n';

    return 0;
}