#include "grid_encoding.h"
#include <bits/stdc++.h>

#define MAX 600

int LST[2][MAX], cnt[2][MAX], H[MAX], go[2][MAX], val[2][MAX], vst[2][MAX];
bool chk[2][MAX], aing = false;

using namespace std;

void send(vector<vector<int>> A) {
    int N = A.size(), P, Q;

    for (int i = 0; i < N; i++) {
        LST[0][i] = LST[1][i] = i;
        cnt[0][i] = cnt[1][i] = 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cnt[0][i] += A[i][j], cnt[1][j] += A[i][j];

    sort(LST[0], LST[0] + N, [&](int x, int y) { return cnt[0][x] > cnt[0][y]; });
    sort(LST[1], LST[1] + N, [&](int x, int y) { return cnt[1][x] > cnt[1][y]; });

    P = 0, Q = N - 1;
    while (P < N && Q >= 0) {
        select(LST[0][P], LST[1][Q]);
        if (A[LST[0][P]][LST[1][Q]])
            P++;
        else
            Q--;
    }
}

vector<vector<int>> reconstruct(vector<vector<int>> B) {
    int N = B.size(), X, K;
    vector<int> arr;
    queue<int> q;

    for (int i = 0; i < N; i++) {
        chk[0][i] = chk[1][i] = false, H[i] = go[0][i] = go[1][i] = -1;
        vst[0][i] = vst[1][i] = val[0][i] = val[1][i] = 0;
    }

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < N; i++) {
            K = 0;
            for (int j = 0; j < N; j++) {
                X = k == 0 ? B[i][j] : B[j][i];
                K += X != -1;
            }
            chk[k][i] = K > 1;
        }
    }

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                X = k == 0 ? B[i][j] : B[j][i];
                if (X != -1)
                    arr.push_back(j);
            }
            sort(arr.begin(), arr.end(), [&](int x, int y) {
                int xval = k == 0 ? B[i][x] : B[x][i], yval = k == 0 ? B[i][y] : B[y][i];
                if (xval != yval)
                    return xval == 1;
                else {
                    if (k == 0) {
                        if (!chk[1][x] && !chk[1][y])
                            return x < y;
                        return !chk[1][x];
                    } else {
                        if (!chk[0][x] && !chk[0][y])
                            return x < y;
                        return chk[0][x];
                    }
                }
            });
            for (int j = 0; j < (int)arr.size() - 1; j++) {
                vst[k][arr[j]] = max(vst[k][arr[j]], 1);
                go[k][arr[j]] = arr[j + 1], vst[k][arr[j + 1]] = 2;
            }
            arr.clear();
        }

        for (int i = 0; i < N; i++)
            if (vst[k][i] == 1)
                q.push(i), vst[k][i] = 3;

        if (q.empty()) {
            K = N;
            for (int i = 0; i < N; i++) {
                X = k == 0 ? B[N - 1][i] : B[i][N - 1];
                if (X == 1)
                    K = i;
                else if (X == 0)
                    K = -i;
            }
            arr.push_back(abs(K));
            for (int i = 0; i < N; i++)
                if (i != abs(K))
                    arr.push_back(i);
            reverse(arr.begin(), arr.end());
        } else {
            if (k == 0)
                for (int i = 0; i < N; i++)
                    if (!vst[k][i])
                        arr.push_back(i), vst[k][i] = 3;
            while (!q.empty()) {
                X = q.front(), q.pop(), arr.push_back(X);
                if (go[k][X] != -1)
                    q.push(go[k][X]), vst[k][go[k][X]] = 3;
            }
            if (k == 1)
                for (int i = 0; i < N; i++)
                    if (!vst[k][i])
                        arr.push_back(i), vst[k][i] = 3;
            for (int i = 0; i < N; i++)
                if (vst[k][i] != 3)
                    arr.push_back(i);
        }
        for (int i = 0; i < N; i++)
            val[k ^ 1][arr[i]] = i;
        arr.clear();
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] != 1)
                continue;
            for (int k = 0; k <= val[1][j]; k++)
                H[k] = max(H[k], val[0][i]);
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i][j] = val[0][i] <= H[val[1][j]];

    return B;
}