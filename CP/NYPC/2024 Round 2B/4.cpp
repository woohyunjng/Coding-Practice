#include <bits/stdc++.h>
#define int long long

#define MAX 10001
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;
typedef array<int, 9> Node;

// H -> 1 / E -> 2 / G -> 3

Node mergeNode(Node &left, Node &right) {
    Node ret = {};

    if (right[6] == 0)
        return left;
    if (left[6] == 0)
        return right;

    ret[2] = left[2];
    ret[5] = right[5];

    if (left[8] == 1) {
        ret[0] = left[0];
        ret[1] = left[1];
    } else {
        ret[0] = left[0] + right[0];
        ret[1] = left[1] + right[1];
    }

    if (right[8] == 1) {
        ret[3] = right[3];
        ret[4] = right[4];
    } else {
        ret[3] = left[3] + right[3];
        ret[4] = left[4] + right[4];
    }

    ret[7] = min(left[3] + right[0], left[4] + right[1]) + left[7] - min(left[3], left[4]) + right[7] - min(right[0], right[1]);

    ret[6] = left[6] + right[6];
    ret[8] = left[8] || right[8];

    return ret;
}

int N, arr[MAX];
Node tree[MAX * 4 + 1];

void init(int n, int s, int e) {
    if (s == e) {
        tree[n] = {};

        tree[n][6] = 1;
        tree[n][2] = arr[s];
        tree[n][5] = arr[s];

        if (arr[s] == 1) {
            tree[n][8] = 1;
        } else if (arr[s] == 2) {
            tree[n][0] = 1;
            tree[n][3] = 1;
        } else {
            tree[n][1] = 1;
            tree[n][4] = 1;
        }
    } else {
        init(n << 1, s, (s + e) >> 1);
        init(n << 1 | 1, ((s + e) >> 1) + 1, e);
        tree[n] = mergeNode(tree[n << 1], tree[n << 1 | 1]);
    }
}

Node query(int n, int s, int e, int l, int r) {
    if (l <= s && e <= r)
        return tree[n];
    else if (r < s || e < l)
        return {};
    else {
        Node lv = query(n << 1, s, ((s + e) >> 1), l, r);
        Node rv = query(n << 1 | 1, ((s + e) >> 1) + 1, e, l, r);
        return mergeNode(lv, rv);
    }
}

void update(int n, int s, int e, int pos, int val) {
    if (pos < s || e < pos)
        return;
    else if (s == e) {
        tree[n] = {};

        tree[n][6] = 1;
        tree[n][2] = val;
        tree[n][5] = val;

        if (val == 1) {
            tree[n][8] = 1;
        } else if (val == 2) {
            tree[n][0] = 1;
            tree[n][3] = 1;
        } else {
            tree[n][1] = 1;
            tree[n][4] = 1;
        }
    } else {
        update(n << 1, s, (s + e) >> 1, pos, val);
        update(n << 1 | 1, ((s + e) >> 1) + 1, e, pos, val);
        tree[n] = mergeNode(tree[n << 1], tree[n << 1 | 1]);
    }
}

void init() { init(1, 1, N); }
Node query(int l, int r) { return query(1, 1, N, l, r); }
void update(int pos, int val) { update(1, 1, N, pos, val); }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, S, E;
    char K;
    string inp;

    cin >> N >> Q;
    cin >> inp;

    for (int i = 1; i <= N; i++) {
        if (inp[i - 1] == 'h')
            arr[i] = 1;
        else if (inp[i - 1] == 'e')
            arr[i] = 2;
        else
            arr[i] = 3;
    }
    init();

    while (Q--) {
        cin >> X >> K >> S >> E;
        update(X, K == 'h' ? 1 : K == 'e' ? 2
                                          : 3);
        cout << query(S, E)[7] << '\n';
    }

    return 0;
}