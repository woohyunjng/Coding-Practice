#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], Q[MAX], P_index[MAX], Q_index[MAX];

int comb(int N) { return (N * (N + 1)) / 2; }

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, P_one, Q_one, res, l, r, x_l, x_r;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        P_index[P[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        cin >> Q[i];
        Q_index[Q[i]] = i;
    }

    if (P_index[1] > Q_index[1])
        swap(P_index[1], Q_index[1]);

    res = comb(P_index[1] - 1) + comb(N - Q_index[1]) + comb(Q_index[1] - P_index[1] - 1);
    l = P_index[1], r = Q_index[1];

    for (int i = 2; i <= N; i++) {
        if (P_index[i] > Q_index[i])
            swap(P_index[i], Q_index[i]);
        x_l = P_index[i], x_r = Q_index[i];

        if (x_r < l)
            res += (l - x_r) * (N - r + 1);
        else if (r < x_l)
            res += (x_l - r) * l;
        else if (x_l < l && r < x_r)
            res += (l - x_l) * (x_r - r);

        l = min(l, x_l), r = max(r, x_r);
    }

    cout << res + 1 << '\n';

    return 0;
}