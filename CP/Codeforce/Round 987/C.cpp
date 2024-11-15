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
    int N;
    cin >> N;

    if (N & 1) {
        if (N < 27)
            cout << -1 << '\n';
        else {
            cout << "1 2 2 3 3 4 4 13 13 1 5 5 6 6 7 7 8 8 9 9 10 10 11 12 12 1 11 ";
            N -= 27;

            for (int i = 1; i <= N; i++)
                cout << (i + 1) / 2 + 13 << ' ';
            cout << '\n';
        }
    } else {
        for (int i = 1; i <= N; i++)
            cout << (i + 1) / 2 << ' ';
        cout << '\n';
    }
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