#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 200001;

int W[MAX], S[MAX];
bool chk[MAX];
vector<pr> arrX[MAX], arrY[MAX],
    lineX[MAX], lineY[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, D, V, X, Y, SX = 0, SY = 0, ans = 0;
    vector<pr> arr;

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> X >> Y >> W[i];
        arrX[X].push_back({Y, i}), arrY[Y].push_back({X, i});
        SX = max(SX, X), SY = max(SY, Y);
    }

    X = Y = 1;
    while (Q--) {
        cin >> D >> V;
        if (D == 0)
            lineY[Y].push_back({X + 1, X + V}), X += V;
        else if (D == 1)
            lineX[X].push_back({Y + 1, Y + V}), Y += V;
        else if (D == 2)
            lineY[Y].push_back({X - V, X - 1}), X -= V;
        else
            lineX[X].push_back({Y - V, Y - 1}), Y -= V;
    }

    for (int i = 1; i <= SX; i++) {
        sort(arrX[i].begin(), arrX[i].end()), V = arrX[i].size();
        for (int j = 1; j <= V; j++)
            S[j] = S[j - 1] + W[arrX[i][j - 1][1]];

        for (pr j : lineX[i]) {
            X = lower_bound(arrX[i].begin(), arrX[i].end(), pr{j[0], 0}) - arrX[i].begin();
            Y = upper_bound(arrX[i].begin(), arrX[i].end(), pr{j[1], MAX}) - arrX[i].begin();
            ans += S[Y] - S[X];
        }
    }

    for (int i = 1; i <= SY; i++) {
        sort(arrY[i].begin(), arrY[i].end()), V = arrY[i].size();
        for (int j = 1; j <= V; j++)
            S[j] = S[j - 1] + W[arrY[i][j - 1][1]];

        for (pr j : lineY[i]) {
            X = lower_bound(arrY[i].begin(), arrY[i].end(), pr{j[0], 0}) - arrY[i].begin();
            Y = upper_bound(arrY[i].begin(), arrY[i].end(), pr{j[1], MAX}) - arrY[i].begin();
            ans += S[Y] - S[X];
        }
    }

    cout << ans << '\n';

    return 0;
}