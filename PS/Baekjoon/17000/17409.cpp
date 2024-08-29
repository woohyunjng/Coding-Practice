#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], res[12][MAX];

class FenwickTree {
  public:
    int N;
    vector<int> arr, tree;

    FenwickTree(int n) : N(n), arr(n + 1, 0), tree(n + 1, 0) {}

    void build() {
        for (int i = 1; i <= N; i++) {
            tree[i] = (tree[i] + arr[i]) % MOD;
            if (i + (i & -i) <= N)
                tree[i + (i & -i)] = (tree[i + (i & -i)] + tree[i]) % MOD;
        }
    }

    void update(int n, int val) {
        arr[n] = (arr[n] + val) % MOD;
        while (n <= N) {
            tree[n] = (tree[n] + val) % MOD;
            n += n & -n;
        }
    }

    int query(int n) {
        int res = 0;
        while (n) {
            res = (res + tree[n]) % MOD;
            n -= n & -n;
        }
        return res;
    }

    int query(int l, int r) { return query(r) - query(l - 1); }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = 0;
    cin >> N >> K;

    FenwickTree ft(N);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        res[1][i] = 1;
    }

    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            res[i][j] = ft.query(1, arr[j] - 1);
            ft.update(arr[j], res[i - 1][j]);
        }

        for (int j = 1; j <= N; j++)
            ft.update(arr[j], -res[i - 1][j]);
    }

    for (int i = 1; i <= N; i++)
        ans = (ans + res[K][i]) % MOD;
    cout << ans;

    return 0;
}