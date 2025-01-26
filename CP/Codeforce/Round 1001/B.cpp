#include <bits/stdc++.h>
#define int long long

#define MAX 600000

using namespace std;

int A[MAX];

void solve() {
    int N, X = 0;
    vector<int> arr;
    bool res = true;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        res &= 2 * max(i - 1, N - i) < A[i];
    }

    cout << (res ? "YES" : "NO") << '\n';
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