#include "message.h"
#include <bits/stdc++.h>
using namespace std;

void send_message(vector<bool> M, vector<bool> C) {
    vector<vector<bool>> R(66, vector<bool>(31, 0));
    vector<int> nxt(31, -1);
    int X, S = M.size(), K = 0;
    M.push_back(!M.back());

    while (M.size() < 1025)
        M.push_back(M.back());

    for (int i = 0; i < 31; i++) {
        if (C[i])
            continue;
        for (X = 1; X < 31; X++)
            if (C[(i + X) % 31] == 0)
                break;
        R[X - 1][i] = 1;
        for (; X < 66; X++)
            R[X][i] = M[K++];
    }

    for (int i = 0; i < 66; i++)
        send_packet(R[i]);
}

vector<bool> receive_message(vector<vector<bool>> R) {
    vector<bool> res, vst(31, 0), C(31, 0);
    vector<int> nxt(31, -1);
    int X, K;

    for (int i = 0; i < 31; i++) {
        for (int j = 0; j < 66; j++)
            if (R[j][i]) {
                nxt[i] = j;
                break;
            }
    }

    for (int i = 0; i < 31; i++) {
        if (nxt[i] == -1)
            continue;
        X = (i + nxt[i] + 1) % 31, K = 1, vst[i] = 1;
        while (!vst[X] && nxt[X] != -1) {
            K++, X = (X + nxt[X] + 1) % 31;
            if (K > 16)
                break;
        }
        if (K == 16) {
            X = (i + nxt[i] + 1) % 31, C[i] = 1;
            while (X != i)
                C[X] = 1, X = (X + nxt[X] + 1) % 31;
            break;
        }
    }

    for (int i = 0; i < 31; i++) {
        if (!C[i])
            continue;
        for (int j = nxt[i] + 1; j < 66; j++)
            res.push_back(R[j][i]);
    }
    K = res.back();

    while (res.back() == K)
        res.pop_back();
    return res;
}