#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, M, L, R, X;
    char K;

    cin >> T;

    while (T--) {
        cin >> N >> M;
        X = 0;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            X = max(X, arr[i]);
        }

        while (M--) {
            cin >> K >> L >> R;
            if (K == '+') {
                if (L <= X && X <= R)
                    X++;
            } else {
                if (L <= X && X <= R)
                    X--;
            }

            cout << X << ' ';
        }
        cout << '\n';
    }

    return 0;
}