#include <bits/stdc++.h>
#define int long long

#define MAX 10100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX];

void solve() {
    int N, X, K = 0, Y;
    cin >> N;

    for (int i = 2; i < N; i++) {
        cout << "? " << 1 << ' ' << i << endl;
        cout.flush();

        cin >> X;
        if (X == 0) {
            P[i] = 1;
            K = 1;
            Y = i + 1;
            break;
        }
        P[i] = 0;
    }

    for (int i = Y; i < N; i++) {
        while (++K) {
            cout << "? " << K << ' ' << i << endl;
            cout.flush();

            cin >> X;
            if (X == 0) {
                P[i] = K;
                break;
            }
        }
    }

    cout << "! ";
    for (int i = 1; i < N; i++)
        cout << P[i] << ' ';
    cout << '\n';
    cout.flush();
}

signed main() {
    int T, N;
    cin >> T;

    while (T--)
        solve();

    return 0;
}