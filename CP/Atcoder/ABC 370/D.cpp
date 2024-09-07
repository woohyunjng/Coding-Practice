#include <bits/stdc++.h>
#define int long long

#define MAX 400100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

set<int> st_w[MAX], st_h[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, Q, R, C, res = 0;
    set<int>::iterator iter_w, iter_h;
    cin >> H >> W >> Q;

    res = H * W;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            st_w[i].insert(j);
            st_h[j].insert(i);
        }
    }

    while (Q--) {
        cin >> R >> C;
        iter_h = st_h[C].lower_bound(R);
        iter_w = st_w[R].lower_bound(C);

        if (iter_h != st_h[C].end() && *iter_h == R) {
            res--;
            st_h[C].erase(iter_h);
            st_w[R].erase(iter_w);
            continue;
        }

        iter_h = st_h[C].lower_bound(R);
        if (iter_h != st_h[C].begin()) {
            res--, iter_h--;
            iter_w = st_w[*iter_h].lower_bound(C);
            st_h[C].erase(iter_h);
            st_w[*iter_h].erase(iter_w);
        }

        iter_w = st_w[R].lower_bound(C);
        if (iter_w != st_w[R].begin()) {
            res--, iter_w--;
            iter_h = st_h[*iter_w].lower_bound(R);
            st_w[R].erase(iter_w);
            st_h[*iter_w].erase(iter_h);
        }

        iter_h = st_h[C].upper_bound(R);
        if (iter_h != st_h[C].end()) {
            res--;
            iter_w = st_w[*iter_h].lower_bound(C);
            st_h[C].erase(iter_h);
            st_w[*iter_h].erase(iter_w);
        }

        iter_w = st_w[R].upper_bound(C);
        if (iter_w != st_w[R].end()) {
            res--;
            iter_h = st_h[*iter_w].lower_bound(R);
            st_w[R].erase(iter_w);
            st_h[*iter_w].erase(iter_h);
        }
    }

    cout << res;

    return 0;
}