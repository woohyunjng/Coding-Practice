#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 500001;

int N, tree[MAX], A[MAX];

void update(int n) {
    for (; n <= N; n += n & -n)
        tree[n]++;
}

int query(int n) {
    int res = 0;
    for (; n; n -= n & -n)
        res += tree[n];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int X, ans = 0;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i], arr.push_back(A[i]);

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        X = lower_bound(arr.begin(), arr.end(), A[i]) - arr.begin() + 1;
        ans += i - query(X), update(X);
    }

    cout << ans << '\n';

    return 0;
}