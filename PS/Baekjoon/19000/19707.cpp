#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class SegTree {
  public:
    int N;
    vector<int> arr, tree;

    SegTree(int n) : N(n), arr(n + 1, 0), tree(n * 2 + 1, INF) {}

    void init() {
        for (int i = 1; i <= N; i++)
            tree[i + N - 1] = arr[i];

        for (int i = N - 1; i > 0; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    int query(int l, int r) {
        int res = INF;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res = min(res, tree[l++]);
            if (r & 1)
                res = min(res, tree[--r]);
        }
        return res;
    }

    int query(int pos) { return query(pos, pos); }
    void update(int pos, int val) {
        for (tree[pos += N - 1] = val; pos > 1; pos >>= 1)
            tree[pos >> 1] = min(tree[pos], tree[pos ^ 1]);
    }
};

pr arr[MAX][2];
tp query[MAX];
int res[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, L, R, A;
    bool check = true;

    cin >> N >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> L >> R >> A;
        L++, R++, A++;
        query[i] = {L, R, A};

        if (arr[A][0].first == 0)
            arr[A][0] = {L, R}, arr[A][1] = {L, R};
        else {
            arr[A][0] = {min(arr[A][0].first, L), max(arr[A][0].second, R)};
            arr[A][1] = {max(arr[A][1].first, L), min(arr[A][1].second, R)};
        }
    }

    queue<int> q;
    for (int i = N; i >= 1; i--) {
        if (arr[i][0].first == 0) {
            q.push(i);
            continue;
        }

        for (int j = arr[i][1].first; j <= arr[i][0].second; j++) {
            if (!res[j]) {
                res[j] = i;
                break;
            }
        }

        for (int j = arr[i][0].first; j <= arr[i][0].second; j++) {
            if (res[j])
                continue;
            if (q.empty())
                break;
            res[j] = q.front(), q.pop();
        }
    }

    SegTree tree(N);
    for (int i = 1; i <= N; i++) {
        if (!res[i] && !q.empty())
            res[i] = q.front(), q.pop();
        tree.arr[i] = res[i];
    }
    tree.init();

    check = true;
    for (int i = 1; i <= Q; i++)
        check = check && (tree.query(query[i][0], query[i][1]) == query[i][2]);

    if (!check)
        for (int i = 1; i <= N; i++)
            res[i] = 0;

    for (int i = 1; i <= N; i++)
        cout << res[i] - 1 << ' ';

    return 0;
}