#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX];

void solve() {
    int N, mx = 0, mn = INF;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        mx = max(mx, A[i]), mn = min(mn, A[i]);
    }

    cout << (mx - mn) * (N - 1) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}