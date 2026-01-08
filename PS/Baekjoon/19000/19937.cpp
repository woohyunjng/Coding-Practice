#include "mushrooms.h"
#include <bits/stdc++.h>
using namespace std;

int count_mushrooms(int N) {
    vector<int> val, arr[2];
    int ans, K, M, X, Y, C, T;

    if (N <= 227) {
        ans = 1;
        for (int i = 1; i < N; i++)
            ans += 1 - use_machine({0, i});
        return ans;
    }

    arr[0].push_back(0);
    for (int i = 1; i <= 2; i++)
        arr[use_machine({0, i})].push_back(i);

    T = arr[0].size() < arr[1].size();
    Y = 4 - use_machine({3, arr[T][0], 4, arr[T][1]}) - 1;
    arr[T ^ (Y & 1) ^ 1].push_back(3), arr[T ^ ((Y >> 1) & 1) ^ 1].push_back(4);

    X = 5, C = 86;
    for (int i = 1; i <= 86 && X + 4 < N; i++) {
        T = arr[0].size() < arr[1].size();
        Y = use_machine({arr[T][0], X, arr[T][1], X + 1, arr[T][2], X + 2});
        arr[T ^ (Y & 1)].push_back(X + 2), Y >>= 1;
        if (Y != 1) {
            Y >>= 1, arr[T ^ Y].push_back(X);
            arr[T ^ Y].push_back(X + 1), X += 3;
            continue;
        }

        if (arr[T ^ 1].size() < 2) {
            Y = use_machine({arr[T][0], X, arr[T][1], X + 3});
            arr[T ^ (Y & 1)].push_back(X + 3), Y >>= 1;
            arr[T ^ Y].push_back(X), arr[T ^ Y ^ 1].push_back(X + 1);
            X += 4, i++;
            continue;
        }

        Y = use_machine({arr[T ^ 1][0], X, arr[T ^ 1][1], arr[T][0], X + 1, arr[T][1], X + 3, arr[T][2], X + 4}) - 1;
        arr[T ^ (Y & 1)].push_back(X + 4), Y >>= 1;
        arr[T ^ (Y & 1)].push_back(X + 3), Y >>= 1;
        arr[T ^ Y].push_back(X + 1), arr[T ^ Y ^ 1].push_back(X);
        X += 5, i++;
    }
    ans = arr[0].size();

    while (X < N) {
        T = arr[0].size() < arr[1].size(), K = arr[T].size();
        M = min(K, N - X), val.clear();
        for (int j = 0; j < M; j++)
            val.push_back(X + j), val.push_back(arr[T][j]);
        Y = (M << 1) - use_machine(val) - 1;
        arr[T ^ (Y & 1) ^ 1].push_back(X), Y = Y / 2 + (Y & 1);
        ans += T == 0 ? Y : (M - Y), X += M;
    }

    return ans;
}