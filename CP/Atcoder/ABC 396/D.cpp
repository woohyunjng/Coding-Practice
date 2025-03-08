#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 11;
const int INF = 0x3f3f3f3f3f3f3f3f;

int N;
vector<pr> adj[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, X, Y, Z, ans = INF, val;
    bool flag;

    vector<int> arr;

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        arr.push_back(i);

    while (M--) {
        cin >> X >> Y >> Z;

        X--, Y--;
        adj[X].push_back({Y, Z});
        adj[Y].push_back({X, Z});
    }

    do {
        if (arr[0] != 0)
            continue;
        val = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i] == N - 1) {
                ans = min(ans, val);
                break;
            }
            flag = false;
            for (pr j : adj[arr[i]])
                if (j[0] == arr[i + 1])
                    val ^= j[1], flag = true;
            if (!flag)
                break;
        }
    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans << '\n';

    return 0;
}