#include "vision.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10001;

int D[MAX][2], CH[MAX][2], V[MAX][2], VN[MAX][2];

void construct_network(int H, int W, int K) {
    vector<int> arr;

    int X = H * W, SN, DN;
    for (int i = 0; i <= H + W - 2; i++) {
        for (int j = 0; j < H; j++)
            for (int k = 0; k < W; k++)
                if (j + k == i)
                    arr.push_back(j * W + k);
        add_or(arr), arr.clear(), D[i][0] = X++;
    }
    for (int i = 0; i + K <= H + W - 2; i++)
        add_and({D[i][0], D[i + K][0]}), CH[i][0] = X++;

    for (int i = 0; i <= H + W - 2; i++) {
        for (int j = 0; j < H; j++)
            for (int k = 0; k < W; k++)
                if (j - k + W - 1 == i)
                    arr.push_back(j * W + k);
        add_or(arr), arr.clear(), D[i][1] = X++;
    }
    for (int i = 0; i + K <= H + W - 2; i++)
        add_and({D[i][1], D[i + K][1]}), CH[i][1] = X++;

    for (int i = 0; i + K <= H + W - 2; i++)
        arr.push_back(CH[i][0]), arr.push_back(CH[i][1]);
    add_or(arr), arr.clear(), DN = X++;

    if (K + 1 <= H + W - 2) {
        for (int i = 0; i + K + 1 <= H + W - 2; i++) {
            for (int j = i + K + 1; j <= H + W - 2; j++)
                arr.push_back(D[j][0]);
            add_or(arr), arr.clear(), V[i][0] = X++;
        }
        for (int i = 0; i + K + 1 <= H + W - 2; i++)
            add_and({D[i][0], V[i][0]}), VN[i][0] = X++;

        for (int i = 0; i + K + 1 <= H + W - 2; i++) {
            for (int j = i + K + 1; j <= H + W - 2; j++)
                arr.push_back(D[j][1]);
            add_or(arr), arr.clear(), V[i][1] = X++;
        }
        for (int i = 0; i + K + 1 <= H + W - 2; i++)
            add_and({D[i][1], V[i][1]}), VN[i][1] = X++;

        for (int i = 0; i + K + 1 <= H + W - 2; i++)
            arr.push_back(VN[i][0]), arr.push_back(VN[i][1]);
        add_or(arr), arr.clear();
        add_not(X++), SN = X++;
        add_and({SN, DN});
    }
}