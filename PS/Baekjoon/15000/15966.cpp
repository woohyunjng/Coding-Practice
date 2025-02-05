#include <bits/stdc++.h>
#define int long long

#define MAX 2000000
using namespace std;

int A[MAX], val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, ans = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        val[A[i]] = max(val[A[i]], val[A[i] - 1] + 1), ans = max(ans, val[A[i]]);
    }

    cout << ans << '\n';

    return 0;
}