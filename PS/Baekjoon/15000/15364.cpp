#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 300000;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX];
pr tree[2][MAX * 4];

void init(int t, int n, int s, int e) {
    tree[t][n] = {0, 0};
    if (s ^ e) {
        int m = s + e >> 1;
        init(t, n << 1, s, m), init(t, n << 1 | 1, m + 1, e);
    }
}

pr sm(pr A, pr B) { return {A[0] + B[0], A[1] + B[1]}; }

void update(int t, int n, int s, int e, int x, int v1, int v2) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[t][n][0] += v1, tree[t][n][1] += v2;
    else {
        int m = s + e >> 1;
        update(t, n << 1, s, m, x, v1, v2), update(t, n << 1 | 1, m + 1, e, x, v1, v2);
        tree[t][n] = sm(tree[t][n << 1], tree[t][n << 1 | 1]);
    }
}

pr query(int t, int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0};
    else if (l <= s && e <= r)
        return tree[t][n];
    else {
        int m = s + e >> 1;
        return sm(query(t, n << 1, s, m, l, r), query(t, n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, X, Y, Z, ans = INF, st, en, md;
    pr K;

    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    comp.clear();
    for (int i = 1; i <= N; i++)
        comp.push_back(A[i] + i), comp.push_back(A[i] - i);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();

    for (int i = 1; i <= N; i++) {
        X = lower_bound(comp.begin(), comp.end(), A[i] + i) - comp.begin() + 1;
        update(1, 1, 1, S, X, 1, A[i] + i);
    }

    for (int i = 1; i <= N; i++) {
        st = max(i, N - i + 1), en = 2000000000, X = st;
        while (st <= en) {
            md = st + en >> 1, Z = 0;
            Y = upper_bound(comp.begin(), comp.end(), md - i) - comp.begin(), Z += query(0, 1, 1, S, 1, Y)[0];
            Y = upper_bound(comp.begin(), comp.end(), md + i) - comp.begin(), Z += query(1, 1, 1, S, 1, Y)[0];

            if (Z >= (N + 1) / 2)
                en = md - 1, X = md;
            else
                st = md + 1;
        }

        Z = 0;

        Y = upper_bound(comp.begin(), comp.end(), X - i) - comp.begin();
        K = query(0, 1, 1, S, 1, Y), Z += (X - i) * K[0] - K[1];
        K = query(0, 1, 1, S, Y + 1, S), Z += K[1] - (X - i) * K[0];

        Y = upper_bound(comp.begin(), comp.end(), X + i) - comp.begin();
        K = query(1, 1, 1, S, 1, Y), Z += (X + i) * K[0] - K[1];
        K = query(1, 1, 1, S, Y + 1, S), Z += K[1] - (X + i) * K[0];

        ans = min(ans, Z);

        X = lower_bound(comp.begin(), comp.end(), A[i] + i) - comp.begin() + 1;
        update(1, 1, 1, S, X, -1, -A[i] - i);
        X = lower_bound(comp.begin(), comp.end(), A[i] - i) - comp.begin() + 1;
        update(0, 1, 1, S, X, 1, A[i] - i);
    }

    cout << ans << '\n';

    return 0;
}