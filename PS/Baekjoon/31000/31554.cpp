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

    int T, N, st, en, mid, res, A, B, K;
    bool check;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        sort(arr + 1, arr + N + 1);

        res = min(arr[N], N * (N + 1) / 2);

        st = 1, en = N - 1;
        while (st <= en) {
            mid = st + en >> 1;
            K = mid * (mid + 1) / 2;
            check = false;

            for (int i = 0; i < min(mid, N); i++) {
                if (arr[N - i - 1] < K - i * (i + 1) / 2) {
                    check = true;
                    break;
                }
            }

            if (check) {
                res = min(res, K);
                en = mid - 1;
            } else
                st = mid + 1;
        }

        cout << res << '\n';
    }

    return 0;
}