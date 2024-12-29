#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res = 0;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> A[i], sm[i] = sm[i - 1] + A[i];
        res = 0;
        for (int i = 0; i <= N / 2 - 1; i++)
            res = max(res, sm[i] + sm[N] - sm[N - (N / 2 - 1 - i)]);
        cout << sm[N] - res << ' ' << res << '\n';
    }

    return 0;
}