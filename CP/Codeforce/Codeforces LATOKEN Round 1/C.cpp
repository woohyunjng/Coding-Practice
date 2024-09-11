#include <bits/stdc++.h>
#define int long long

#define MAX 400100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX];
bool checked[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, K, res = 0;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> K;
            A[K] = i;
        }
        for (int i = 1; i <= N; i++)
            cin >> B[i];

        res = 1;
        for (int i = 1; i <= N; i++) {
            if (checked[i])
                continue;
            checked[i] = true;
            K = i;

            while (!checked[A[B[K]]]) {
                checked[A[B[K]]] = true;
                K = A[B[K]];
            }

            res = res * 2 % MOD;
        }

        cout << res << '\n';

        fill(checked, checked + N + 1, false);
    }

    return 0;
}