#include <iostream>
#include <algorithm>
#define INF 9000000000000000000
using namespace std;

struct Node{
    long long int lmax, rmax, mx, sm, lmax_len, rmax_len, mx_len, sm_len;
    Node(){
        lmax = rmax = mx = sm = -INF;
        lmax_len = rmax_len = mx_len = sm_len = 0;
    }

    void set(long long int x){
        lmax = rmax = mx = sm = x;
        lmax_len = rmax_len = mx_len = sm_len = 1;
    }
};

Node tree[1 << 20];
int N, P[500001] = {}, P_sm[500001] = {}, HALF = 1 << 19;

long long int get(long long int mx, long long int len, int X) {
    return len * X + mx;
}

Node merge(Node left, Node right, int X) {
    Node ret;

    if (get(left.lmax, left.lmax_len, X) <= get(left.sm, left.sm_len, X) + get(right.lmax, right.lmax_len, X)) {
        ret.lmax = left.sm + right.lmax;
        ret.lmax_len = left.sm_len + right.lmax_len;
    } else {
        ret.lmax = left.lmax;
        ret.lmax_len = left.lmax_len;
    }

    if (get(right.rmax, right.rmax_len, X) <= get(right.sm, right.sm_len, X) + get(left.rmax, left.rmax_len, X)) {
        ret.rmax = right.sm + left.rmax;
        ret.rmax_len = right.sm_len + left.rmax_len;
    } else {
        ret.rmax = right.rmax;
        ret.rmax_len = right.rmax_len;
    }

    if (get(left.mx, left.mx_len, X) >= get(right.mx, right.mx_len, X) && get(left.mx, left.mx_len, X) >= get(left.rmax, left.rmax_len, X) + get(right.lmax, right.lmax_len, X)) {
        ret.mx = left.mx;
        ret.mx_len = left.mx_len;
    } else if (get(right.mx, right.mx_len, X) >= get(left.mx, left.mx_len, X) && get(right.mx, right.mx_len, X) >= get(left.rmax, left.rmax_len, X) + get(right.lmax, right.lmax_len, X)) {
        ret.mx = right.mx;
        ret.mx_len = right.mx_len;
    } else {
        ret.mx = left.rmax + right.lmax;
        ret.mx_len = left.rmax_len + right.lmax_len;
    }

    ret.sm = left.sm + right.sm;
    ret.sm_len = left.sm_len + right.sm_len;

    return ret;
}

void build(int s, int e, int x){
    if (s == e){
        tree[x].set(P[s - 1]);
        return;
    }

    int mid = (int)((s + e) / 2);
    build(s, mid, x << 1);
    build(mid + 1, e, x << 1 | 1);

    tree[x] = merge(tree[x << 1], tree[x << 1 | 1], 0);
}

Node query(int l, int r, int s, int e, int x, int X){
    if (e < l || r < s) {
        return Node();
    }
    if (l <= s && e <= r) {
        return tree[x];
    }

    int mid = s + e >> 1;
    return merge(query(l, r, s, mid, x << 1, X), query(l, r, mid + 1, e, x << 1 | 1, X), X);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q, L, R, X;
    cin >> N >> Q;

    for (int i = 0 ; i < N ; i ++) {
        cin >> P[i];
        P_sm[i + 1] = P_sm[i] + P[i];
    }
    build(1, N, 1);

    while (Q --) {
        cin >> L >> R >> X;
        long long int res = (X - R) * P[X - 1] - (P_sm[X] - P_sm[R]);
        Node ret = query(L, R, 1, N, 1, 0);
        res += get(ret.mx, ret.mx_len, 0);
        res = max(res, (long long int)0);
        cout << get(ret.mx, ret.mx_len, 0) << " " << res << "\n";
    }
}
