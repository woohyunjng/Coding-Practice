#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

int mx_bit(int X) {
    for (int i = 40; i >= 0; i--)
        if (X & (1ll << i))
            return i;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int V[4], X, Y, Z, Q;
    vector<int> arr;
    vector<pr> ans;

    for (int i = 1; i <= 3; i++)
        cin >> V[i], arr.push_back(i);
    X = 1, Y = 2, Z = 3;

    while (V[X]) {
        Q = V[Y] / V[X];
        for (int i = 0; i <= mx_bit(Q); i++) {
            if (Q & (1ll << i))
                ans.push_back({Y, X}), V[Y] -= V[X], V[X] <<= 1;
            else
                ans.push_back({Z, X}), V[Z] -= V[X], V[X] <<= 1;
        }
        sort(arr.begin(), arr.end(), [&](int x, int y) { return V[x] < V[y]; });
        X = arr[0], Y = arr[1], Z = arr[2];
    }

    cout << ans.size() << '\n';
    for (pr i : ans)
        cout << i[0] << ' ' << i[1] << '\n';

    return 0;
}