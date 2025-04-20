#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 200001;

int L[MAX], R[MAX];

void solve() {
    int N, K, ans = 1;
    vector<int> arr;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> L[i];
    for (int i = 1; i <= N; i++)
        cin >> R[i];

    for (int i = 1; i <= N; i++)
        arr.push_back(min(L[i], R[i])), ans += L[i] + R[i];

    sort(arr.begin(), arr.end());
    for (int i = 0; i < N - K + 1; i++)
        ans -= arr[i];

    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}