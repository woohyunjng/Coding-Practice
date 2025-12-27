#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> pr;

const int MAX = 101;

pr R[MAX][3], ans[MAX];
map<pr, bool> chk;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, S;
    vector<int> arrX, arrY;

    cin >> N, S = (N + 1) / 2;
    for (int i = 1; i <= S; i++)
        arrX.push_back(i);
    for (int i = S + 1; i <= N; i++)
        arrY.push_back(i);

    for (int i = 0; i < S; i++) {
        cout << "? " << 3 << ' ' << arrX[i] << ' ' << arrY[i % arrY.size()] << ' ' << arrY[(i + 1) % arrY.size()] << '\n', cout.flush();
        cin >> X;
        for (int j = 0; j < 3; j++)
            cin >> R[i][j][0] >> R[i][j][1];
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++) {
                if (R[i][j] != R[(i - 1 + S) % S][k])
                    continue;
                ans[arrY[i % arrY.size()]] = R[i][j], chk[R[i][j]] = true;
            }
    }

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < 3; j++) {
            if (chk[R[i][j]])
                continue;
            ans[arrX[i]] = R[i][j], chk[R[i][j]] = true;
        }
    }

    cout << "! ";
    for (int i = 1; i <= N; i++)
        cout << ans[i][0] << ' ' << ans[i][1] << ' ';
    cout << '\n', cout.flush();

    return 0;
}