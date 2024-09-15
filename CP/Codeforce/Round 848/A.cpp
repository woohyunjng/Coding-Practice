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

    int T, N, sm, res;
    cin >> T;

    while (T--) {
        cin >> N;
        sm = 0, res = -INF;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            sm += arr[i];
        }

        for (int i = 1; i < N; i++) {
            res = max(res, sm - (arr[i] + arr[i + 1]) * 2);
        }

        cout << res << '\n';
    }

    return 0;
}