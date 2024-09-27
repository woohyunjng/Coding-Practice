#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], sm[MAX], lft[MAX], rgh[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y, res = 0;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        rgh[N + 1] = INF, lft[0] = INF;
        for (int i = 1; i <= N; i++)
            lft[i] = min(lft[i - 1], arr[i]);
        for (int i = N; i >= 1; i--)
            rgh[i] = min(rgh[i + 1], arr[i]);

        fill(sm, sm + N + 1, 0);

        for (int i = 1; i <= N; i++) {
            X = min(N - i + 1, arr[i]);
            Y = min(i, arr[i]);
            if (lft[i - Y] > Y && rgh[i + X] > X) {
                sm[i - Y + 1]++;
                sm[i + X]--;
            }
        }

        res = 0;
        for (int i = 1; i <= N; i++) {
            sm[i] += sm[i - 1];
            if (sm[i] == N)
                res++;
        }

        cout << res << '\n';
    }

    return 0;
}