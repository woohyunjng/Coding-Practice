#include "squares.h"
#include <bits/stdc++.h>
using namespace std;

int X[1000], K = 1 << 8;

void dfs(int node, vector<int> &arr) {
    while (X[node] < 2)
        dfs((node % K) << 1 | (X[node]++), arr);
    if (arr.size() < 1000)
        arr.push_back(node & 1);
}

vector<int> paint(int N) {
    vector<int> ans;
    fill(X, X + 1000, 0), dfs(0, ans);
    while (ans.size() > N)
        ans.pop_back();
    ans.push_back(10);
    return ans;
}

int find_location(int N, vector<int> C) {
    if (C.back() == -1) {
        N -= C.size();
        while (!C.empty() && C.back() == -1)
            N++, C.pop_back();
        return N;
    }

    vector<int> arr;
    fill(X, X + 1000, 0), dfs(0, arr);

    int V = 0, K;
    for (int i : C)
        V = V << 1 | i;

    for (int i = 0; i + C.size() <= N; i++) {
        K = 0;
        for (int j = i; j < i + C.size(); j++)
            K = K << 1 | arr[j];
        if (K == V)
            return i;
    }
}