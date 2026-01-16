#include "island.h"

#include <bits/stdc++.h>
using namespace std;

void solve(int N, int L) {
    vector<int> arr, V(N + 1, 0), par(N + 1, 0);
    int X;

    for (int i = 1; i < N; i++)
        arr.push_back(query(1, i)), V[arr.back()] = i;
    for (int i : arr) {
        if (par[i] != 0)
            continue;
        X = 1;
        while (true) {
            par[i] = query(i, X);
            if (V[par[i]] < V[i])
                break;
            par[par[i]] = i, X++;
        }
    }
    for (int i : arr)
        answer(i, par[i]);
}