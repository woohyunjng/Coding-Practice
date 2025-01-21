#include <bits/stdc++.h>
#define int long long

#define MAX 200000
using namespace std;

int S[MAX], T[MAX], K[MAX];
vector<int> tree[3][MAX * 4], A[3][MAX];

void init(int t, int sz) {
    for (int i = 1; i <= sz; i++) {
        tree[t][i + sz - 1] = A[t][i];
        sort(tree[t][i + sz - 1].begin(), tree[t][i + sz - 1].end());
    }
    for (int i = sz - 1; i > 0; i--) {
        tree[t][i].resize(tree[t][i << 1].size() + tree[t][i << 1 | 1].size());
        merge(tree[t][i << 1].begin(), tree[t][i << 1].end(), tree[t][i << 1 | 1].begin(), tree[t][i << 1 | 1].end(), tree[t][i].begin());
    }
}

int query(int t, int sz, int l, int r, int k, bool upper) {
    int res = 0;
    for (l += sz - 1, r += sz; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            if (upper)
                res += tree[t][l].end() - lower_bound(tree[t][l].begin(), tree[t][l].end(), k), l++;
            else
                res += lower_bound(tree[t][l].begin(), tree[t][l].end(), k) - tree[t][l].begin(), l++;
        }
        if (r & 1) {
            if (upper)
                --r, res += tree[t][r].end() - lower_bound(tree[t][r].begin(), tree[t][r].end(), k);
            else
                --r, res += lower_bound(tree[t][r].begin(), tree[t][r].end(), k) - tree[t][r].begin();
        }
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, X, Y, Z, res;
    bool flag;
    vector<int> Scomp, Tcomp, Kcomp;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> T[i], K[i] = S[i] + T[i];
        Scomp.push_back(S[i]), Tcomp.push_back(T[i]), Kcomp.push_back(S[i] + T[i]);
    }

    sort(Scomp.begin(), Scomp.end()), Scomp.erase(unique(Scomp.begin(), Scomp.end()), Scomp.end());
    sort(Tcomp.begin(), Tcomp.end()), Tcomp.erase(unique(Tcomp.begin(), Tcomp.end()), Tcomp.end());
    sort(Kcomp.begin(), Kcomp.end()), Kcomp.erase(unique(Kcomp.begin(), Kcomp.end()), Kcomp.end());

    for (int i = 1; i <= N; i++) {
        S[i] = lower_bound(Scomp.begin(), Scomp.end(), S[i]) - Scomp.begin() + 1;
        T[i] = lower_bound(Tcomp.begin(), Tcomp.end(), T[i]) - Tcomp.begin() + 1;
        K[i] = lower_bound(Kcomp.begin(), Kcomp.end(), K[i]) - Kcomp.begin() + 1;

        A[0][K[i]].push_back(S[i]), A[1][K[i]].push_back(T[i]);
        A[2][S[i]].push_back(T[i]);
    }
    init(0, Kcomp.size()), init(1, Kcomp.size()), init(2, Scomp.size());

    while (Q--) {
        cin >> X >> Y >> Z, res = 0;
        flag = Z > X + Y;

        X = lower_bound(Scomp.begin(), Scomp.end(), X) - Scomp.begin() + 1;
        Y = lower_bound(Tcomp.begin(), Tcomp.end(), Y) - Tcomp.begin() + 1;
        Z = lower_bound(Kcomp.begin(), Kcomp.end(), Z) - Kcomp.begin() + 1;
    
        if (flag) {
            res = query(0, Kcomp.size(), Z, Kcomp.size(), X, true);
            res -= query(1, Kcomp.size(), Z, Kcomp.size(), Y, false);
        } else
            res = query(2, Scomp.size(), X, Scomp.size(), Y, true);

        cout << res << '\n';
    }

    return 0;
}