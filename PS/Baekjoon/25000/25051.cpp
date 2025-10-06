#include <bits/stdc++.h>
#define int long long
#define double long double

using namespace std;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

double D[MAX];
int S[MAX], R[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, P, X, Y, K, ans = -INF;
    vector<int> val, arr;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y >> S[i], R[i] = X * X + Y * Y;
        D[i] = atan2(Y, X) * 180 / acos(-1);
        if (D[i] < 0)
            D[i] += 360;

        R[i + N] = R[i], D[i + N] = D[i] + 360, S[i + N] = S[i];
        val.push_back(i), val.push_back(i + N);
    }
    N <<= 1;

    sort(val.begin(), val.end(), [&](int x, int y) { return D[x] < D[y]; });

    while (M--) {
        cin >> P, arr.clear();
        for (int i : val)
            if (R[i] <= P)
                arr.push_back(i);

        X = K = 0, Y = -INF;
        for (int i : arr) {
            X += S[i];
            while (D[arr[K]] + 90 < D[i])
                X -= S[arr[K]], K++;
            Y = max(Y, X);
        }
        if (Y == -INF)
            Y = 0;

        ans = max(ans, Y - P);
    }

    cout << ans << '\n';

    return 0;
}