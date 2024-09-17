#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K, sm = 0, cur = 0, mn = 0, smn;
    vector<pair<string, int>> inp;
    string S;

    cin >> N >> M;
    while (M--) {
        cin >> S >> K;
        inp.push_back({S, K});
    }

    reverse(inp.begin(), inp.end());
    for (pair<string, int> i : inp) {
        S = i.first, K = i.second, cur = 0, smn = 0;

        for (int i = S.size() - 1; i >= 0; i--) {
            cur += (S[i] == 'F' ? 1 : -1);
            smn = min(smn, cur);
        }

        mn = min({mn, sm + smn, sm + cur * (K - 1) + smn});
        sm += cur * K;
    }

    if (sm < 0)
        cout << -1;
    else
        cout << max(0, -mn - 1);
}