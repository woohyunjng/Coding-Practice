#include "network.h"
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int D[MAX];
vector<int> arr[MAX];

void findRoute(int N, int A, int B) {
    for (int i = 1; i <= N; i++) {
        D[i] = A == i ? 0 : ping(A, i);
        arr[D[i]].push_back(i);
    }

    int X;
    for (int i = 0; i < D[B]; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            X = arr[i][j];
            if (X == A)
                continue;
            if (j + 1 == arr[i].size() || (ping(A, X) == 0 && ping(B, X) + D[X] + 1 == D[B])) {
                travelTo(X), A = X;
                break;
            }
        }
    }
    travelTo(B);
}