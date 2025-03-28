#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;
const int MAX = 1001;

int X[MAX], Y[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int H, W, N, M, K, Z, st = 1, en, md, ans = INF;
    vector<int> arr;

    cin >> H >> W, en = H;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        arr.push_back(i);
        cin >> X[i] >> Y[i], st = max(st, X[i]);
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return Y[x] < Y[y]; });

    while (st <= en) {
        md = st + en >> 1, K = 0, Z = -INF;

        for (int i = 0; i < M; i++) {
            if (Y[arr[i]] - Z + 1 > md)
                K++, Z = Y[arr[i]];
        }

        if (K <= N)
            ans = min(ans, md), en = md - 1;
        else
            st = md + 1;
    }

    cout << ans << '\n';

    return 0;
}