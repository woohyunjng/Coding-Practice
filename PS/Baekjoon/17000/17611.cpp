#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int S[MAX], X[MAX], Y[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<pr> arr[2];
    vector<int> comp;

    int N, L, R, SZ, ans = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];

    for (int i = 0; i < N; i++) {
        if (X[i] == (X[(i + 1) % N]))
            arr[0].push_back({min(Y[i], Y[(i + 1) % N]), max(Y[i], Y[(i + 1) % N])});
        else
            arr[1].push_back({min(X[i], X[(i + 1) % N]), max(X[i], X[(i + 1) % N])});
    }

    for (int i = 0; i < 2; i++) {
        comp.clear();
        for (pr j : arr[i])
            comp.push_back(j[0]), comp.push_back(j[1]);

        sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
        SZ = comp.size(), fill(S, S + SZ + 1, 0);

        for (pr j : arr[i]) {
            L = lower_bound(comp.begin(), comp.end(), j[0]) - comp.begin() + 1;
            R = lower_bound(comp.begin(), comp.end(), j[1]) - comp.begin() + 1;
            S[L]++, S[R]--;
        }

        for (int i = 1; i <= SZ; i++)
            S[i] += S[i - 1], ans = max(ans, S[i]);
    }

    cout << ans << '\n';

    return 0;
}