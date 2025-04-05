#include "Memory2_lib.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int V[MAX], P[MAX], Q[MAX][MAX];

int flip(int X, int Y) {
    if (Q[X][Y] != -1)
        return Q[X][Y];
    Q[X][Y] = Q[Y][X] = Flip(X, Y);
    return Q[X][Y];
}

void Solve(int T, int N) {
    if (N == 1) {
        Answer(0, 1, 0);
        return;
    }

    for (int i = 0; i < N * 2; i++) {
        P[i] = -1;
        for (int j = 0; j < N * 2; j++)
            Q[i][j] = -1;
    }

    vector<int> arr;
    set<int> st;

    arr.push_back(0), arr.push_back(1), arr.push_back(2);
    flip(0, 1), flip(0, 2), flip(1, 2);

    int X;

    for (int i = 3; i < N * 2; i++) {
        arr.push_back(i);
        for (int j = 0; j < 4; j++) {
            st.clear();
            for (int k = 0; k < 4; k++) {
                if (j == k)
                    continue;
                st.insert(flip(arr[j], arr[k]));
            }
            if (st.size() != 1)
                continue;
            V[arr[j]] = *st.begin(), arr.erase(arr.begin() + j);
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        st.clear();
        for (int j = 0; j < 3; j++) {
            if (i == j)
                continue;
            st.insert(flip(arr[i], arr[j]));
        }
        if (st.size() != 1)
            continue;
        V[arr[i]] = *st.begin(), arr.erase(arr.begin() + i);
        break;
    }
    V[arr[0]] = V[arr[1]] = flip(arr[0], arr[1]);

    for (int i = 0; i < N * 2; i++) {
        if (P[V[i]] != -1)
            Answer(P[V[i]], i, V[i]);
        else
            P[V[i]] = i;
    }

    return;
}
