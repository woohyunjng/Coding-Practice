#include <bits/stdc++.h>
using namespace std;

const int MAX = 2001;

map<string, int> mp;
int S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, U, V, K = 0, ans = 0;
    string A, B;

    cin >> N;

    mp["ChongChong"] = ++K, S[K] = 1;
    ans++;

    while (N--) {
        cin >> A >> B;
        if (!mp.count(A))
            mp[A] = ++K;
        if (!mp.count(B))
            mp[B] = ++K;
        U = mp[A], V = mp[B];

        ans -= S[U] + S[V];
        S[U] |= S[V], S[V] = S[U];
        ans += S[U] + S[V];
    }

    cout << ans << '\n';

    return 0;
}