#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int l = -1, r = -1, p = -1,
        cnt = 1, sum = 0, val = 0,
        mx = 0, mn = 0;
    bool dummy = false, flipped = false;

    Node(int val = 0, int p = -1) : val(val), sum(val), mx(val), mn(val), p(p) {}
};

vector<Node> spt;
int rt, P[MAX], A[MAX];

void upd(int node) {
    spt[node].cnt = 1, spt[node].sum = spt[node].mn = spt[node].mx = spt[node].val;
    if (spt[node].l != -1) {
        spt[node].cnt += spt[spt[node].l].cnt, spt[node].sum += spt[spt[node].l].sum;
        spt[node].mn = min(spt[node].mn, spt[spt[node].l].mn), spt[node].mx = max(spt[node].mx, spt[spt[node].l].mx);
    }
    if (spt[node].r != -1) {
        spt[node].cnt += spt[spt[node].r].cnt, spt[node].sum += spt[spt[node].r].sum;
        spt[node].mn = min(spt[node].mn, spt[spt[node].r].mn), spt[node].mx = max(spt[node].mx, spt[spt[node].r].mx);
    }
}

void push(int node) {
    if (!spt[node].flipped)
        return;
    swap(spt[node].l, spt[node].r);
    if (spt[node].l != -1)
        spt[spt[node].l].flipped ^= 1;
    if (spt[node].r != -1)
        spt[spt[node].r].flipped ^= 1;
    spt[node].flipped = false;
}

void rotate(int node) {
    int p = spt[node].p, b = -1;
    if (p == -1)
        return;
    push(p), push(node);
    if (node == spt[p].l)
        spt[p].l = b = spt[node].r, spt[node].r = p;
    else
        spt[p].r = b = spt[node].l, spt[node].l = p;

    spt[node].p = spt[p].p, spt[p].p = node;
    if (b != -1)
        spt[b].p = p;
    (spt[node].p != -1 ? (spt[spt[node].p].l == p ? spt[spt[node].p].l : spt[spt[node].p].r) : rt) = node;
    upd(p), upd(node);
}

void splay(int node, int g = -1) {
    int p, y;
    while (spt[node].p != g) {
        p = spt[node].p;
        if (spt[p].p == g) {
            rotate(node);
            break;
        }
        y = spt[p].p;
        if ((spt[p].l == node) == (spt[y].l == p))
            rotate(p);
        else
            rotate(node);
        rotate(node);
    }
    if (g == -1)
        rt = node;
}

void find_kth(int k) {
    int x = rt;
    push(x);

    while (true) {
        while (spt[x].l != -1 && spt[spt[x].l].cnt > k)
            x = spt[x].l, push(x);
        if (spt[x].l != -1)
            k -= spt[spt[x].l].cnt;
        if (!k--)
            break;
        x = spt[x].r, push(x);
    }
    splay(x);
}

int gather(int l, int r) {
    find_kth(r + 1);
    int x = rt;
    find_kth(l - 1), splay(x, rt);
    return spt[spt[rt].r].l;
}

void flip(int l, int r) {
    int x = gather(l, r);
    spt[x].flipped ^= 1;
}

void print(int node) {
    push(node);
    if (spt[node].l != -1)
        print(spt[node].l);
    if (!spt[node].dummy)
        cout << spt[node].val << ' ';
    if (spt[node].r != -1)
        print(spt[node].r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, Q, T, L, R, X;

    cin >> N >> Q;

    rt = X = spt.size(), spt.push_back(Node());
    spt[X].dummy = true, spt[X].mn = INF, spt[X].mx = -INF;

    for (int i = 1; i <= N; i++) {
        P[i] = spt[X].r = spt.size();
        spt.push_back(Node(i, X)), X = spt[X].r;
    }

    spt[X].r = spt.size(), spt.push_back(Node(0, X));
    X = spt[X].r, spt[X].dummy = true;
    spt[X].mn = INF, spt[X].mx = -INF;

    for (int i = N; i >= 1; i--)
        upd(P[i]);
    splay(P[(N + 1) >> 1]);

    while (Q--) {
        cin >> T;
        if (T == 1) {
            cin >> L >> R, flip(L, R);
            X = gather(L, R);
            cout << spt[X].mn << ' ' << spt[X].mx << ' ' << spt[X].sum << '\n';
        } else if (T == 2) {
            cin >> L >> R >> K;
            X = gather(L, R);
            cout << spt[X].mn << ' ' << spt[X].mx << ' ' << spt[X].sum << '\n';
            if (K >= 0) {
                K %= (R - L + 1);
                if (K)
                    flip(L, R), flip(L, L + K - 1), flip(L + K, R);
            } else {
                K = (-K) % (R - L + 1);
                if (K)
                    flip(L, R), flip(R - K + 1, R), flip(L, R - K);
            }
        } else if (T == 3) {
            cin >> X;
            find_kth(X);
            cout << spt[rt].val << '\n';
        } else {
            cin >> X;
            splay(P[X]);
            cout << spt[spt[rt].l].cnt << '\n';
        }
    }

    print(rt), cout << '\n';

    return 0;
}