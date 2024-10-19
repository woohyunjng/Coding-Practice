#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int A[MAX], B[MAX];

class SegTree {
  public:
    int N;
    vector<pr> tree;

    SegTree(int n) : N(n), tree(n * 2 + 1, {0, 0}) {}

    pr query(int l, int r) {
        pr res = {0, 0};
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res.first += tree[l].first;
                res.second += tree[l++].second;
            }
            if (r & 1) {
                res.first += tree[--r].first;
                res.second += tree[r].second;
            }
        }
        return res;
    }

    void update(int pos, int val) {
        pos += N - 1;
        tree[pos] = {val, 1};

        for (; pos > 1; pos >>= 1)
            tree[pos >> 1] = {tree[pos].first + tree[pos ^ 1].first, tree[pos].second + tree[pos ^ 1].second};
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, res, st, en, md, Z;
    pr X;

    vector<tp> arr;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> A[i];
        for (int i = 1; i <= N; i++)
            cin >> B[i];

        for (int i = 1; i <= N; i++)
            arr.push_back((tp){A[i], B[i], 0ll});

        sort(arr.begin(), arr.end(), [](tp a, tp b) {
            return a[1] < b[1];
        });

        for (int i = 0; i < N; i++)
            arr[i][2] = i + 1;

        sort(arr.begin(), arr.end());

        SegTree tree(N);

        res = INF;
        for (int i = 0; i < N; i++) {
            tree.update(arr[i][2], arr[i][1]);
            if (i < K - 1)
                continue;

            st = K, en = N;
            while (st <= en) {
                md = st + en >> 1;
                X = tree.query(1, md);
                if (X.second >= K) {
                    en = md - 1;
                    Z = X.first;
                } else
                    st = md + 1;
            }
            res = min(res, arr[i][0] * Z);
        }

        cout << res << '\n';

        arr.clear();
    }

    return 0;
}