#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<string> arr;
    string X, ans = "";

    int N;

    cin >> N;
    while (N--)
        cin >> X, arr.push_back(X);

    sort(arr.begin(), arr.end(), [&](string a, string b) { return a.size() < b.size(); });

    for (string i : arr)
        ans += i;
    cout << ans << '\n';

    return 0;
}