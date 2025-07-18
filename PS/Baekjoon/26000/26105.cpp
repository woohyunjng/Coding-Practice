#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100001;

int A[MAX], S[MAX], V[MAX], dp[MAX], tree[MAX * 4];

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int mid = s + e >> 1;
        return max(query(n << 1, s, mid, l, r), query(n << 1 | 1, mid + 1, e, l, r));
    }
}

void update(int n, int s, int e, int x, int v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = max(tree[n], v);
    else {
        int mid = s + e >> 1;
        update(n << 1, s, mid, x, v), update(n << 1 | 1, mid + 1, e, x, v);
        tree[n] = max(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, V, X, ans = 3'000'000'000;
    vector<int> comp;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], S[i] = S[i - 1] + A[i];
        comp.push_back(S[i]);
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    C = comp.size();

    for (int i = 1; i <= N; i++) {
        V = lower_bound(comp.begin(), comp.end(), S[i]) - comp.begin() + 1;
        X = query(1, 1, C, 1, V), dp[i] = S[i] - S[X];
        V = lower_bound(comp.begin(), comp.end(), S[i] + dp[i]) - comp.begin() + 1;
        update(1, 1, C, V, i);

        ans = min(ans, max(S[N] - S[i], dp[i]));
    }

    cout << ans << '\n';

    return 0;
}