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
int cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, res = 0;
    cin >> T;

    while (T--) {
        cin >> N;

        res = 0;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            cnt[arr[i]]++;
            res = max(res, cnt[arr[i]]);
        }

        cout << N - res << '\n';
        for (int i = 1; i <= N; i++) {
            cnt[arr[i]] = 0;
        }
    }

    return 0;
}