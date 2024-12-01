#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

void solve() {
    int N, M, K, cnt = 0, res = 0;
    string S;

    cin >> N >> M >> K >> S;

    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == '1') {
            cnt = 0;
            continue;
        }
        cnt++;
        if (cnt == M) {
            i += K - 1;
            cnt = 0, res++;
        }
    }

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