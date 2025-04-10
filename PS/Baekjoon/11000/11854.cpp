#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 100001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int G[MAX], D[MAX], X[MAX], ans;

void dnc(int l, int r) {
    if (l == r)
        return;

    int m = l + r >> 1, V;
    vector<pr> arr, st;

    for (int i = l; i <= m; i++)
        arr.push_back({D[i - 1] - X[i], -G[i - 1]});

    sort(arr.begin(), arr.end());
    for (pr i : arr) {
        if (!st.empty() && st.back()[1] >= i[1])
            continue;
        st.push_back(i);
    }

    for (int i = m + 1; i <= r; i++) {
        V = lower_bound(st.begin(), st.end(), (pr){D[i] - X[i], INF}) - st.begin() - 1;
        if (V < 0)
            continue;
        ans = max(ans, G[i] + st[V][1]);
    }

    dnc(l, m), dnc(m + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> G[i] >> D[i], ans = max(ans, G[i]);
        G[i] += G[i - 1], D[i] += D[i - 1];
    }

    dnc(1, N);

    cout << ans << '\n';

    return 0;
}