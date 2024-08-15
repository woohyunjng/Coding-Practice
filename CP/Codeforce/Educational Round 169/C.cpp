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
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, K, res;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        sort(arr + 1, arr + N + 1, greater<int>());

        res = 0;
        if (N & 1)
            res += arr[N];

        for (int i = 1; i + 1 <= N; i += 2) {
            if (arr[i] - arr[i + 1] <= K)
                K -= arr[i] - arr[i + 1];
            else if (K) {
                res += arr[i] - arr[i + 1] - K;
                K = 0;
            } else
                res += arr[i] - arr[i + 1];
        }

        cout << res << '\n';
    }

    return 0;
}