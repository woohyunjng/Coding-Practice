#include <bits/stdc++.h>
#define int long long

#define MAX 10100
using namespace std;

vector<int> adj[MAX];
int res = 0;

int dfs(int node, int par, int mx) {
    multiset<int> v;
    multiset<int>::iterator it1, it2;
    vector<int> fail;

    int X, Y;

    for (int i : adj[node]) {
        if (i == par)
            continue;
        X = dfs(i, node, mx);
        if (X == -1)
            return -1;
        if (X != 0)
            v.insert(X);
    }

    while (!v.empty()) {
        it1 = prev(v.end()), X = mx - *it1, v.erase(it1);
        it2 = v.upper_bound(X);
        if (it2 == v.begin())
            fail.push_back(mx - X);
        else
            v.erase(prev(it2)), res++;
    }

    if (fail.size() > 2)
        return -1;
    else if (fail.size() == 2) {
        if (fail[0] > mx)
            return -1;
        if (node == 1)
            return -1;
        return fail[1] + 1;
    } else if (fail.empty())
        return node == 1 ? 0 : 1;
    else {
        if (fail[0] > mx)
            return -1;
        return fail[0] + 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y, st, en, mid, ans_res, ans_mx;
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> X >> Y;
        adj[X].push_back(Y), adj[Y].push_back(X);
    }

    res += dfs(1, 0, N) > 0;
    ans_res = res;

    st = 1, en = N;
    while (st <= en) {
        mid = st + en >> 1;
        X = dfs(1, 0, mid);
        if (X == -1)
            st = mid + 1;
        else
            en = mid - 1, ans_mx = mid;
    }

    cout << ans_res << ' ' << ans_mx << '\n';

    return 0;
}