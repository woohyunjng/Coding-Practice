#include <bits/stdc++.h>
#define int long long
#define MAX 200100
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], cnt[MAX * 2 + 1];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, res = 0;
    string S;
    cin >> T;

    while (T--) {
        cin >> S;
        N = S.size();

        fill(arr, arr + N + 1, 0);
        fill(cnt, cnt + 2 * N + 1, 0);
        res = 0;

        for (int i = 1; i <= N; i++) {
            if (S[i - 1] == '1')
                arr[i] = arr[i - 1] + 1;
            else
                arr[i] = arr[i - 1] - 1;
        }

        for (int i = N; i >= 0; i--) {
            res = (res + (i + 1) * cnt[arr[i] + N]) % MOD;
            cnt[arr[i] + N] = (cnt[arr[i] + N] + (N + 1 - i)) % MOD;
        }

        cout << res << '\n';
    }

    return 0;
}