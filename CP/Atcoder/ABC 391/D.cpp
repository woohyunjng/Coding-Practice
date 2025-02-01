#include <bits/stdc++.h>
#define int long long

#define MAX 300000
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

typedef array<int, 2> pr;

int X[MAX], Y[MAX], val[MAX], mx[MAX];
vector<pr> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, W, Q, T, A, sz = INF;
    cin >> N >> W;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i], val[i] = INF;
        arr[X[i]].push_back({Y[i], i});
    }

    for (int i = 1; i <= W; i++) {
        sz = min(sz, (int)arr[i].size());
        sort(arr[i].begin(), arr[i].end());

        for (int j = 0; j < arr[i].size(); j++)
            mx[j] = max(mx[j], arr[i][j][0]);
    }

    for (int i = 1; i <= W; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (j < sz)
                val[arr[i][j][1]] = mx[j];
        }
    }

    cin >> Q;
    while (Q--) {
        cin >> T >> A;
        cout << (val[A] > T ? "Yes" : "No") << '\n';
    }

    return 0;
}