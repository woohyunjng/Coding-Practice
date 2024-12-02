#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int C[MAX], cnt[MAX];

void solve() {
    int N, res = 0, K = 0, X = 0, Y = 0;
    cin >> N;

    fill(cnt, cnt + N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> C[i], cnt[C[i]]++;

    for (int i = 1; i <= N; i++) {
        if (cnt[i] == 1)
            X++;
        else if (cnt[i] > 1)
            Y++;
    }

    res = (X + 1) / 2 * 2 + Y;
    cout << res << '\n';
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