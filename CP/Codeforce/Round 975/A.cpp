#include <bits/stdc++.h>
#define int long long

#define MAX 110
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

    int T, N, res = 0;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        res = 0;

        for (int i = 1; i <= N; i++)
            res = max(arr[i] + (i - 1) / 2 + (N - i) / 2 + 1, res);

        cout << res << '\n';
    }

    return 0;
}