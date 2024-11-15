#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX];

void solve() {
    int N, X;
    bool res = true;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i];

    for (int i = 1; i <= N; i++) {
        if (P[i] != i) {
            if (P[i + 1] == i && P[i] == i + 1)
                swap(P[i], P[i + 1]);
            else
                res = false;
        }
    }

    cout << (res ? "YES" : "NO") << '\n';
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