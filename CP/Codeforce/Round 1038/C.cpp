#include <bits/stdc++.h>
using namespace std;

const int MAX = 200001;

int X[MAX], Y[MAX], D[MAX][2];

void solve() {
    int N;

    vector<int> arrX, arrY, V[4];

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        arrX.push_back(i), arrY.push_back(i);
    }

    sort(arrX.begin(), arrX.end(), [&](int x, int y) { return X[x] < X[y]; });
    sort(arrY.begin(), arrY.end(), [&](int x, int y) { return Y[x] < Y[y]; });

    for (int i = 0; i < N; i++)
        D[arrX[i]][0] = i + 1, D[arrY[i]][1] = i + 1;

    for (int i = 1; i <= N; i++) {
        if (D[i][0] <= N / 2 && D[i][1] <= N / 2)
            V[0].push_back(i);
        else if (D[i][0] > N / 2 && D[i][1] <= N / 2)
            V[1].push_back(i);
        else if (D[i][0] <= N / 2 && D[i][1] > N / 2)
            V[2].push_back(i);
        else
            V[3].push_back(i);
    }

    for (int i = 0; i < V[0].size(); i++)
        cout << V[0][i] << ' ' << V[3][i] << '\n';
    for (int i = 0; i < V[1].size(); i++)
        cout << V[1][i] << ' ' << V[2][i] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}