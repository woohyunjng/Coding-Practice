#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int cnt[30];

void solve() {
    int N, L = 0, R = 0, X;
    string S, res;

    cin >> S;
    N = S.size();

    if (N == 1)
        cout << -1 << '\n';
    else if (S[0] == S[1])
        cout << S[0] << S[1] << '\n';
    else if (N == 2)
        cout << -1 << '\n';
    else {
        if (S[2] == S[1])
            cout << S[1] << S[2] << '\n';
        else if (S[0] == S[2]) {
            for (int i = 3; i < N; i++) {
                if (S[i] == S[i - 1]) {
                    cout << S[i - 1] << S[i] << '\n';
                    return;
                } else if (S[i] != S[i - 2]) {
                    cout << S[i - 2] << S[i - 1] << S[i] << '\n';
                    return;
                }
            }
            cout << -1 << '\n';
        } else
            cout << S[0] << S[1] << S[2] << '\n';
    }
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