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

    int T, N, mn, bef, res;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        mn = 0, bef = 0, res = 0;

        for (int i = 1; i <= N; i++) {
            if (bef <= arr[i])
                bef = arr[i];
            else {
                mn = max(mn, bef - arr[i]);
                res += bef - arr[i];
            }
        }

        cout << res + mn << '\n';
    }

    return 0;
}