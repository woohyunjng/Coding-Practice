#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[15];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, cnt = 0, res, mx, val, X;
    cin >> T;

    while (T--) {
        cin >> N;
        cnt = 0;
        for (int i = 1; i <= 7; i++) {
            cin >> A[i];
            cnt += A[i];
        }

        for (int i = 1; i <= 7; i++)
            A[i + 7] = A[i];

        res = (N - 1) / cnt * 7;
        N -= (N - 1) / cnt * cnt;

        mx = 7;
        for (int i = 1; i <= 7; i++) {
            val = 0, X = i;
            while (val < N)
                val += A[X++];
            mx = min(mx, X - i);
        }

        res += mx;
        cout << res << '\n';
    }

    return 0;
}