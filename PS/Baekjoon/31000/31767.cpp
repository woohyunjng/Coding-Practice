#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][3], res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> len, klen;
    ordered_set left, right;

    int N, L, R, K, X;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> L >> R >> K;
        arr[i][0] = L, arr[i][1] = R, arr[i][2] = K;
        len.push_back(i);
        klen.push_back(i);
    }

    sort(len.begin(), len.end(), [&](int a, int b) {
        if (arr[a][1] - arr[a][0] == arr[b][1] - arr[b][0])
            return arr[a][2] > arr[b][2];
        return arr[a][1] - arr[a][0] < arr[b][1] - arr[b][0];
    });
    sort(klen.begin(), klen.end(), [&](int a, int b) {
        if (arr[a][2] == arr[b][2])
            return arr[a][1] - arr[a][0] < arr[b][1] - arr[b][0];
        return arr[a][2] < arr[b][2];
    });

    X = N - 1;

    for (int i = N - 1; i >= 0; i--) {
        while (X >= 0 && arr[len[X]][1] - arr[len[X]][0] >= arr[klen[i]][2]) {
            left.insert(arr[len[X]][0]);
            right.insert(arr[len[X]][1]);
            X--;
        }

        K = N - X - 2;
        K -= left.size() - left.order_of_key(arr[klen[i]][1] - arr[klen[i]][2] + 1);
        K -= right.order_of_key(arr[klen[i]][0] + arr[klen[i]][2]);

        res[klen[i]] = K;
    }

    for (int i = 1; i <= N; i++)
        cout << res[i] << '\n';

    return 0;
}