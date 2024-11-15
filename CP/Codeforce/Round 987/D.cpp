#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], X[MAX], res[MAX];

void solve() {
    int N, K, Y, Z;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        X[i] = X[i - 1];
        if (A[i] > A[X[i]])
            X[i] = i;
    }

    K = N;
    while (K > 0) {
        Y = INF;
        for (int i = X[K]; i <= K; i++)
            res[i] = A[X[K]], Y = min(Y, A[i]);
        Z = A[X[K]];

        K = X[K] - 1;

        while (K > 0 && A[X[K]] > Y) {
            for (int i = X[K]; i <= K; i++)
                res[i] = Z, Y = min(Y, A[i]);
            K = X[K] - 1;
        }
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << ' ';
    cout << '\n';
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