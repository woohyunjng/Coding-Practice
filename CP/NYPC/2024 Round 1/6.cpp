#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;
typedef array<int, 4> ftp;

class SegTree {
  public:
    int N;
    vector<int> arr, tree;

    SegTree(int n) : N(n), arr(n + 1, 0), tree(n * 2 + 1, 0) {}

    int query(int l, int r) {
        int res = 0;
        for (l += N - 1, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res += tree[l++];
            if (r & 1)
                res += tree[--r];
        }
        return res;
    }

    int query(int pos) { return query(pos, pos); }
    void update(int pos, int val) {
        for (tree[pos += N - 1] += val; pos > 1; pos >>= 1)
            tree[pos >> 1] = tree[pos] + tree[pos ^ 1];
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, A, B, C, res = 0;
    tp before;
    cin >> N >> K;

    res = N * N;

    vector<int> comp;
    vector<tp> X, Y;
    vector<ftp> events;

    while (K--) {
        cin >> A >> B >> C;
        X.push_back({B, max(A - C, 1ll), min(A + C, N)});
        Y.push_back({A, max(B - C, 1ll), min(B + C, N)});
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    before = {0, 0, 0};
    for (tp i : X) {
        if (before[0] == i[0] && before[2] >= i[1])
            before = {i[0], min(before[1], i[1]), max(before[2], i[2])};
        else {
            if (before[0] != 0) {
                events.push_back({before[0], 1, before[1], before[2]});
                comp.push_back(before[1]);
                comp.push_back(before[2]);
                res -= before[2] - before[1] + 1;
            }
            before = i;
        }
    }
    if (before[0] != 0) {
        events.push_back({before[0], 1, before[1], before[2]});
        comp.push_back(before[1]);
        comp.push_back(before[2]);
        res -= before[2] - before[1] + 1;
    }

    before = {0, 0, 0};
    for (tp i : Y) {
        if (before[0] == i[0] && before[2] >= i[1])
            before = {i[0], min(before[1], i[1]), max(before[2], i[2])};
        else {
            if (before[0] != 0) {
                events.push_back({before[1], 0, before[0], 0});
                events.push_back({before[2], 2, before[0], 0});
                comp.push_back(before[0]);
                res -= before[2] - before[1] + 1;
            }
            before = i;
        }
    }
    if (before[0] != 0) {
        events.push_back({before[1], 0, before[0], 0});
        events.push_back({before[2], 2, before[0], 0});
        comp.push_back(before[0]);
        res -= before[2] - before[1] + 1;
    }

    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    SegTree seg(comp.size());

    sort(events.begin(), events.end());

    for (ftp i : events) {
        if (i[1] == 0)
            seg.update(lower_bound(comp.begin(), comp.end(), i[2]) - comp.begin() + 1, 1);
        else if (i[1] == 1)
            res += seg.query(lower_bound(comp.begin(), comp.end(), i[2]) - comp.begin() + 1,
                             lower_bound(comp.begin(), comp.end(), i[3]) - comp.begin() + 1);
        else
            seg.update(lower_bound(comp.begin(), comp.end(), i[2]) - comp.begin() + 1, -1);
    }

    cout << res;

    return 0;
}