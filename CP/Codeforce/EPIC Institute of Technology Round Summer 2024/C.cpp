#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res, bef, val;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        res = 0, val = 0, bef = 0;
        for (int i = N; i >= 1; i--) {
            val = max(val + 1, arr[i]);
            res = max(res, val);
        }

        cout << res << '\n';
    }

    return 0;
}