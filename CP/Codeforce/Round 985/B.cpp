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
    int N, X = 0, Y = 0;
    string S, R;

    cin >> N >> S >> R;

    for (int i = 0; i < N; i++)
        X += S[i] == '1', Y += S[i] == '0';

    for (int i = 0; i < N - 1; i++) {
        if (!X || !Y) {
            cout << "NO\n";
            return;
        }
        X--, Y--;

        if (R[i] == '0')
            Y++;
        else
            X++;
    }

    cout << "YES\n";
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