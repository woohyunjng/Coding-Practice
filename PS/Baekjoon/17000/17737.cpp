#include <bits/stdc++.h>
#define int long long

#define MAX 300000

using namespace std;
typedef array<int, 2> pr;

int tree[MAX * 4], ans = 0, S, X[MAX], Y[MAX];

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return query(n << 1, s, m, l, r) + query(n << 1 | 1, m + 1, e, l, r);
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e) {
        tree[n] += v;
        return;
    } else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

void dnc(vector<int> &arr) {
    if (arr.size() <= 1)
        return;

    vector<int> upper, lower, st, hull;
    int M = arr.size() / 2, A = 1, B = 0;
    hull.push_back(0);

    sort(arr.begin(), arr.end(), [&](int x, int y) { return Y[x] != Y[y] ? Y[x] < Y[y] : X[x] > X[y]; });
    for (int i = 0; i < M; i++)
        lower.push_back(arr[i]);
    for (int i = M; i < arr.size(); i++)
        upper.push_back(arr[i]);

    sort(lower.begin(), lower.end(), [&](int x, int y) { return X[x] != X[y] ? X[x] < X[y] : Y[x] > Y[y]; });
    sort(upper.begin(), upper.end(), [&](int x, int y) { return X[x] != X[y] ? X[x] < X[y] : Y[x] > Y[y]; });

    for (int i = 0; i < upper.size(); i++) {
        while (B < lower.size() && X[lower[B]] < X[upper[i]]) {
            while (!st.empty() && Y[st.back()] < Y[lower[B]])
                update(1, 1, S, X[st.back()], -1), st.pop_back();
            st.push_back(lower[B]), update(1, 1, S, X[lower[B]], 1), B++;
        }

        while (Y[hull.back()] >= Y[upper[i]])
            hull.pop_back();
        ans += query(1, 1, S, X[hull.back()], X[upper[i]]), hull.push_back(upper[i]);
        if (i + 1 < upper.size() && X[upper[i + 1]] != X[upper[i]])
            A = X[upper[i]];
    }

    while (!st.empty())
        A = st.back(), st.pop_back(), update(1, 1, S, X[A], -1);
    dnc(upper), dnc(lower);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<int> arr, Xcomp;

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> X[i] >> Y[i], arr.push_back(i), Xcomp.push_back(X[i]);
    sort(Xcomp.begin(), Xcomp.end()), Xcomp.erase(unique(Xcomp.begin(), Xcomp.end()), Xcomp.end()), S = Xcomp.size();

    for (int i = 1; i <= N; i++)
        X[i] = lower_bound(Xcomp.begin(), Xcomp.end(), X[i]) - Xcomp.begin() + 1;

    dnc(arr);

    cout << ans << '\n';

    return 0;
}