#include <bits/stdc++.h>
#define int long long

using namespace std;

int ans[200001];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++)
        arr.push_back(i);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return x * (N - x + 1) > y * (N - y + 1); });

    for (int i = 1; i <= N; i++)
        ans[arr[i - 1]] = N - i + 1;

    for (int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}