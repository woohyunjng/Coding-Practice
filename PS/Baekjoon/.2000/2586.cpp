#include <bits/stdc++.h>

using namespace std;
typedef array<int, 2> pr;

const int MAX = 400001;

vector<int> val[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<pr> arr;

    int P, F, X, ans = 0, S, V, D;

    cin >> P >> F, D = P + F;
    while (P--)
        cin >> X, arr.push_back({X, 0});
    while (F--)
        cin >> X, arr.push_back({X, 1});

    sort(arr.begin(), arr.end());

    for (pr i : arr) {
        if (i[1] == 0)
            val[D++].push_back(i[0]);
        else
            val[--D].push_back(i[0]);
    }

    for (int i = 0; i < MAX; i++) {
        V = 0;
        for (int j = 0; j + 1 < val[i].size(); j += 2)
            V += val[i][j + 1] - val[i][j];
        S = V;
        if (val[i].size() & 1) {
            for (int j = val[i].size() - 1; j >= 2; j -= 2) {
                V -= val[i][j - 1] - val[i][j - 2], V += val[i][j] - val[i][j - 1];
                S = min(S, V);
            }
        }
        ans += S;
    }

    cout << ans << '\n';

    return 0;
}