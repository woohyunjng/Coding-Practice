#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

map<string, int> cs;
vector<int> arr[10];
int A[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, Q, X, Y, res, K;
    string S;
    cin >> T;

    cs["BG"] = 1, cs["BR"] = 2, cs["BY"] = 3, cs["GR"] = 4, cs["GY"] = 5, cs["RY"] = 6;

    while (T--) {
        cin >> N >> Q;

        for (int i = 1; i <= N; i++) {
            cin >> S;
            A[i] = cs[S];
            arr[A[i]].push_back(i);
        }

        while (Q--) {
            res = INF;
            cin >> X >> Y;

            if (A[X] + A[Y] != 7)
                res = abs(X - Y);
            else {
                res = INF;
                for (int i = 1; i <= 6; i++) {
                    if (i == A[X] || i == A[Y])
                        continue;
                    if (arr[i].empty())
                        continue;

                    K = lower_bound(arr[i].begin(), arr[i].end(), X) - arr[i].begin();
                    if (K < arr[i].size())
                        res = min(res, abs(arr[i][K] - X) + abs(arr[i][K] - Y));
                    if (K) {
                        K--;
                        res = min(res, abs(arr[i][K] - X) + abs(arr[i][K] - Y));
                    }
                }
                if (res == INF)
                    res = -1;
            }

            cout << res << '\n';
        }

        for (int i = 1; i <= 6; i++)
            arr[i].clear();
    }

    return 0;
}