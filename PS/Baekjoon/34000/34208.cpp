#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 3> tp;

const int MAX = 1000001;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct Node {
    int S = 0;
    vector<tp> left_hull, right_hull, ans_hull;

    Node() {}
};

int A[MAX];

int ceil_div(int X, int Y) {
    if (Y < 0)
        X = -X, Y = -Y;
    if (X >= 0)
        return (X + Y - 1) / Y;
    return X / Y;
}

vector<tp> merge(vector<tp> X, vector<tp> Y) {
    vector<tp> res;
    int XP = 0, YP = 0;

    res.reserve(X.size() + Y.size());

    while (XP < X.size() || YP < Y.size()) {
        if (XP == X.size() || (YP < Y.size() && (X[XP][0] > Y[YP][0] || (X[XP][0] == Y[YP][0] && X[XP][1] < Y[YP][1]))))
            swap(X, Y), swap(XP, YP);

        if (!res.empty() && res.back()[0] == X[XP][0]) {
            XP++;
            continue;
        }

        while (!res.empty()) {
            X[XP][2] = ceil_div(res.back()[1] - X[XP][1], X[XP][0] - res.back()[0]);
            if (res.back()[2] < X[XP][2])
                break;
            res.pop_back();
        }
        res.push_back(X[XP++]);
    }

    return res;
}

Node dnc(int l, int r) {
    Node res, lv, rv;
    vector<tp> nleft_hull, nright_hull;
    int P;

    if (l == r) {
        res.S = A[l], res.ans_hull.push_back({1, A[l], -INF});
        res.left_hull.push_back({1, A[l], -INF}), res.right_hull.push_back({1, A[l], -INF});
        return res;
    }

    int m = l + r >> 1;
    lv = dnc(l, m), rv = dnc(m + 1, r);

    nleft_hull.reserve(lv.right_hull.size()), nright_hull.reserve(rv.left_hull.size());

    P = 0;
    for (tp i : lv.right_hull) {
        while (P + 1 < rv.left_hull.size() && rv.left_hull[P + 1][2] <= i[2])
            P++;
        nleft_hull.push_back({i[0] + rv.left_hull[P][0], i[1] + rv.left_hull[P][1], -INF});
    }

    P = 0;
    for (tp i : rv.left_hull) {
        while (P + 1 < lv.right_hull.size() && lv.right_hull[P + 1][2] <= i[2])
            P++;
        nright_hull.push_back({i[0] + lv.right_hull[P][0], i[1] + lv.right_hull[P][1], -INF});
    }

    res.ans_hull = merge(
        merge(lv.ans_hull, rv.ans_hull),
        merge(nleft_hull, nright_hull));

    res.S = lv.S + rv.S;
    for (int i = 0; i < lv.right_hull.size(); i++)
        lv.right_hull[i][0] += r - m, lv.right_hull[i][1] += rv.S;
    for (int i = 0; i < rv.left_hull.size(); i++)
        rv.left_hull[i][0] += m - l + 1, rv.left_hull[i][1] += lv.S;

    res.left_hull = merge(lv.left_hull, rv.left_hull);
    res.right_hull = merge(lv.right_hull, rv.right_hull);

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, V;
    Node res;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    res = dnc(1, N);

    while (Q--) {
        cin >> X, V = 0;
        for (int st = 0, en = (int)res.ans_hull.size() - 1, md; st <= en;) {
            md = st + en >> 1;
            if (res.ans_hull[md][2] <= X)
                st = md + 1, V = md;
            else
                en = md - 1;
        }
        cout << X * res.ans_hull[V][0] + res.ans_hull[V][1] << '\n';
    }

    return 0;
}