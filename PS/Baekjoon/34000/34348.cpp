#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string _S;
    int N, Q, L, R, ans, X, K;
    bool flag;
    vector<int> arr[5];

    cin >> _S >> Q, N = _S.size();
    for (int i = 1; i <= N; i++) {
        if (_S[i - 1] == 's')
            S[i] = 0;
        else if (_S[i - 1] == 'n')
            S[i] = 1;
        else if (_S[i - 1] == 'u')
            S[i] = 2;
        else if (_S[i - 1] == 'p')
            S[i] = 3;
        else
            S[i] = 4;
        arr[S[i]].push_back(i);
    }

    while (Q--) {
        cin >> L >> R, ans = 0;
        for (int st = 1, en = (R - L + 1) / 5, md; st <= en;) {
            md = st + en >> 1, flag = true, X = L;
            for (int i = 0; i < 5 && flag; i++) {
                K = lower_bound(arr[i].begin(), arr[i].end(), X) - arr[i].begin();
                if (K + md - 1 >= arr[i].size() || arr[i][K + md - 1] > R)
                    flag = false;
                else
                    X = arr[i][K + md - 1] + 1;
            }

            if (flag)
                ans = md, st = md + 1;
            else
                en = md - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}