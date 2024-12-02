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
    int N, K, X = 0, Y = 0, res = 0;
    string S;

    priority_queue<int> pq;

    cin >> N >> K;
    cin >> S;

    for (int i = N - 1; i > 0; i--) {
        if (S[i] == '0')
            X++;
        else
            Y++;
        pq.push(Y - X);
    }

    Y = 0;

    while (!pq.empty()) {
        X = pq.top(), pq.pop();
        Y += X, res++;
        if (Y >= K) {
            cout << res + 1 << '\n';
            return;
        }
    }

    res = -1;
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