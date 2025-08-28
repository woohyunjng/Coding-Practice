#include <bits/stdc++.h>
#define int long long

using namespace std;

int query(int h, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return h & (-h);
    else {
        int m = s + e >> 1;
        return query(h - 1, s, m, l, r) ^ query(h - 1, m + 1, e, l, r);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, G, L, R;

    cin >> K >> G;
    while (G--) {
        cin >> L >> R;
        if (query(K, 1, 1ll << (K - 1), L, R))
            cout << "swlee0202" << '\n';
        else
            cout << "mj1000j" << '\n';
    }

    return 0;
}