#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    string S, ans;

    vector<pr> arr;

    cin >> N >> M >> S;

    for (int i = 0; i < N; i++)
        arr.push_back({S[i] - 'a', i});
    sort(arr.begin(), arr.end());
    arr.erase(arr.begin(), arr.begin() + M);

    sort(arr.begin(), arr.end(), [&](pr x, pr y) { return x[1] < y[1]; });
    for (pr i : arr)
        ans += i[0] + 'a';
    cout << ans << '\n';

    return 0;
}