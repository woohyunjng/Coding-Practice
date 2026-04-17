#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;
const int INF = 1e9;

int XL[MAX], XR[MAX], tree[MAX * 4], lazy[MAX * 4];
vector<int> arr[MAX];

void init(int n, int s, int e) {
    tree[n] = INF, lazy[n] = INF;
    if (s ^ e) {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

void lazy_update(int n, int s, int e) {
    if (lazy[n] == INF)
        return;
    tree[n] = min(tree[n], lazy[n]);
    if (s ^ e) {
        lazy[n << 1] = min(lazy[n << 1], lazy[n]);
        lazy[n << 1 | 1] = min(lazy[n << 1 | 1], lazy[n]);
    }
}

int query(int n, int s, int e, int x) {
    lazy_update(n, s, e);
    if (x < s || e < x)
        return INF;
    else if (s == e)
        return tree[n];
    else {
        int m = s + e >> 1;
        return min(query(n << 1, s, m, x), query(n << 1 | 1, m + 1, e, x));
    }
}

void update(int n, int s, int e, int l, int r, int v) {
    lazy_update(n, s, e);
    if (r < s || e < l)
        return;
    else if (l <= s && e <= r)
        lazy[n] = min(lazy[n], v), lazy_update(n, s, e);
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, l, r, v), update(n << 1 | 1, m + 1, e, l, r, v);
        tree[n] = min(tree[n << 1], tree[n << 1 | 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, L = 0, R = INF, S, ans = 0, K, X, V;
    vector<int> comp;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K >> XL[i] >> XR[i], L = max(L, XL[i]), R = min(R, XR[i]);
        while (K--)
            cin >> X, arr[i].push_back(X);
    }

    comp.push_back(L), comp.push_back(R);

    for (int i = 0; i < N; i++) {
        while (!arr[i].empty() && XR[i] - arr[i].back() >= R)
            XR[i] -= arr[i].back(), arr[i].pop_back();
        reverse(arr[i].begin(), arr[i].end());
        while (!arr[i].empty() && arr[i].back() + XL[i] <= L)
            XL[i] += arr[i].back(), arr[i].pop_back();
        reverse(arr[i].begin(), arr[i].end()), K = 0;
        for (int j : arr[i])
            K += j, comp.push_back(max(L, XL[i] + K)), comp.push_back(max(L, XL[i] + K - 1));
    }

    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end()), S = comp.size();
    init(1, 0, S - 1), update(1, 0, S - 1, 0, S - 1, R);

    function<int(int)> getid = [&](int x) {
        return lower_bound(comp.begin(), comp.end(), x) - comp.begin();
    };

    for (int i = 0; i < N; i++) {
        if (arr[i].empty())
            continue;

        K = V = 0;
        for (int j : arr[i])
            K += j;
        update(1, 0, S - 1, getid(L), getid(XL[i] + arr[i].front() - 1), XR[i] - K);
        arr[i].push_back(R);

        for (int j = 0; j < arr[i].size(); j++) {
            V += arr[i][j];
            update(1, 0, S - 1, getid(XL[i] + V), getid((j + 1 == arr[i].size()) ? R : XL[i] + V + arr[i][j + 1] - 1), XR[i] - K + V);
        }
    }

    for (int i = 0; i < S; i++)
        ans = max(ans, query(1, 0, S - 1, i) - comp[i]);

    cout << ans << '\n';

    return 0;
}