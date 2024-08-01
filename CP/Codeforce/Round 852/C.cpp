#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, cur_max, cur_min, l, r;
    pr res;

    cin >> T;

    while (T--) {
        cin >> N;
        cur_max = N, cur_min = 1;
        r = N, l = 1;

        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        while (r - l > 2) {
            if (arr[r] == cur_max) {
                r--;
                cur_max--;
            } else if (arr[l] == cur_max) {
                l++;
                cur_max--;
            } else if (arr[r] == cur_min) {
                r--;
                cur_min++;
            } else if (arr[l] == cur_min) {
                l++;
                cur_min++;
            } else {
                break;
            }
        }

        if (r - l > 2)
            cout << l << ' ' << r << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
