#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX];
vector<int> bit[32];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, res = 0;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 0; i < 20; i++)
            bit[i].clear();

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
            for (int j = 0; j < 20; j++) {
                if (arr[i] & (1 << j)) {
                    bit[j].push_back(i);
                }
            }
        }

        res = 1;
        for (int i = 0; i < 20; i++) {
            if (!bit[i].empty()) {
                res = max(res, bit[i].front());
                res = max(res, N - bit[i].back() + 1);
            }

            for (int j = 1; j < bit[i].size(); j++)
                res = max(res, bit[i][j] - bit[i][j - 1]);
        }

        cout << res << '\n';
    }

    return 0;
}