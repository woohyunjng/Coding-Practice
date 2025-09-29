#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, S[2], ans = 0, V;
    vector<int> arr[2], res[2];

    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> V, arr[i < N / 2].push_back(V);

    for (int i = 0; i < 2; i++) {
        S[i] = arr[i].size();
        for (int j = 0; j < (1 << S[i]); j++) {
            V = 0;
            for (int k = 0; k < S[i]; k++)
                if (j & (1 << k))
                    V += arr[i][k];
            if (V <= C)
                res[i].push_back(V);
        }
        sort(res[i].begin(), res[i].end());
    }

    V = (int)res[0].size() - 1;
    for (int i : res[1]) {
        while (V >= 0 && res[0][V] + i > C)
            V--;
        ans += V + 1;
    }

    cout << ans << '\n';

    return 0;
}