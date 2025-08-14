#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;

vector<vector<int>> ans, arr;

int L[MAX + 1], R[MAX + 1], G[MAX + 1];

vector<vector<int>> devise_strategy(int N) {
    ans.resize(MAX + 1, vector<int>(N + 1, 0));
    int X, Y, Z, K;

    arr.resize(9, vector<int>());

    L[0] = 1, R[0] = 5000, G[0] = 0, arr[0].push_back(0);

    for (int i = 1; i <= 6; i++) {
        G[i * 3 - 2] = G[i * 3 - 1] = G[i * 3] = i;
        arr[i].push_back(i * 3 - 2), arr[i].push_back(i * 3 - 1), arr[i].push_back(i * 3);

        X = R[(i - 1) * 3] - L[(i - 1) * 3] - 1;
        L[i * 3 - 2] = 1, R[i * 3 - 2] = X / 3, L[i * 3 - 1] = X / 3 + 1, R[i * 3 - 1] = X / 3 * 2, L[i * 3] = X / 3 * 2 + 1, R[i * 3] = X;

        if (X % 3 == 2)
            R[i * 3 - 1]++, L[i * 3]++;
    }

    X = R[18] - L[18] - 1;
    G[19] = 7, G[20] = 7, arr[7].push_back(19), arr[7].push_back(20);

    L[19] = 1, R[19] = X / 2, L[20] = X / 2 + 1, R[20] = X;

    for (int i = 0; i <= MAX; i++) {
        X = G[i], ans[i][0] = X % 2;
        ans[i][1] = ans[i][0] == 0 ? -1 : -2;
        if (N == 5000)
            ans[i][N] = ans[i][0] == 0 ? -2 : -1;

        for (int j = 2; j <= min(5000 - 1, N); j++) {
            K = j;
            for (int k = 0; k < X; k++) {
                for (int l : arr[k])
                    if (L[l] <= K && K <= R[l]) {
                        K -= L[l];
                        break;
                    }
            }
            if (K < 1) {
                ans[i][j] = ans[i][0] == 0 ? -1 : -2;
                continue;
            } else if (K > R[arr[X].back()]) {
                ans[i][j] = ans[i][0] == 0 ? -2 : -1;
                continue;
            }

            for (int k : arr[X])
                if (L[k] <= K && K <= R[k]) {
                    Y = k;
                    break;
                }

            if (Y < i || (Y == i && K == L[Y]))
                ans[i][j] = ans[i][0] == 0 ? -1 : -2;
            else if (Y > i || (Y == i && K == R[Y]))
                ans[i][j] = ans[i][0] == 0 ? -2 : -1;
            if (ans[i][j] < 0)
                continue;

            K -= L[Y], Y = 0;
            for (int k : arr[X + 1]) {
                if (L[k] <= K && K <= R[k]) {
                    Y = k;
                    break;
                }
            }
            ans[i][j] = Y;
        }
    }

    return ans;
}