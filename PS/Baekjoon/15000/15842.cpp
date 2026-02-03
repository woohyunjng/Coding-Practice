#include "koala.h"
#include <bits/stdc++.h>
using namespace std;

int minValue(int N, int W) {
    int B[N], R[N];
    fill(B, B + N, 0), B[0] = 1, playRound(B, R);
    for (int i = 0; i < N; i++)
        if (!R[i])
            return i;
}

int maxValue(int N, int W) {
    int B[N], R[N], X;
    vector<int> arr;

    for (int i = 0; i < N; i++)
        arr.push_back(i);
    while (arr.size() > 1) {
        fill(B, B + N, 0), X = W / arr.size();
        for (int i : arr)
            B[i] = X;
        playRound(B, R), arr.clear();
        for (int i = 0; i < N; i++)
            if (R[i] > X)
                arr.push_back(i);
    }
    return arr[0];
}

int greaterValue(int N, int W) {
    int B[N], R[N];
    fill(B, B + N, 0);

    B[0] = B[1] = 4, playRound(B, R);
    if (R[0] > 4 && R[1] > 4) {
        B[0] = B[1] = 8, playRound(B, R);
        if (R[0] <= 8 && R[1] <= 8)
            B[0] = B[1] = 6, playRound(B, R);
    } else if (R[0] <= 4 && R[1] <= 4) {
        B[0] = B[1] = 2, playRound(B, R);
        if (R[0] > 2 && R[1] > 2)
            B[0] = B[1] = 3, playRound(B, R);
        else if (R[0] <= 2 && R[1] <= 2)
            B[0] = B[1] = 1, playRound(B, R);
    }
    return R[0] < R[1];
}

bool compare(int X, int Y, int N) {
    int B[N], R[N];
    fill(B, B + N, 0), B[X] = B[Y] = N, playRound(B, R);
    return R[X] < R[Y];
}

vector<int> merge_sort(vector<int> arr, int N) {
    if (arr.size() == 1)
        return arr;
    vector<int> lv, rv, res;
    int l = 0, r = 0;

    for (int i = 0; i < arr.size() / 2; i++)
        lv.push_back(arr[i]);
    for (int i = arr.size() / 2; i < arr.size(); i++)
        rv.push_back(arr[i]);
    lv = merge_sort(lv, N), rv = merge_sort(rv, N);

    while (l < lv.size() || r < rv.size()) {
        if (l == lv.size())
            res.push_back(rv[r++]);
        else if (r == rv.size())
            res.push_back(lv[l++]);
        else if (compare(lv[l], rv[r], N))
            res.push_back(lv[l++]);
        else
            res.push_back(rv[r++]);
    }
    return res;
}

void dnc(vector<int> arr, int l, int r, int N, int *P) {
    if (arr.size() == 1)
        P[arr[0]] = l;
    else {
        int B[N], R[N], X = min((int)sqrt(2 * l), N / (r - l + 1));
        vector<int> lv, rv;

        fill(B, B + N, 0);
        for (int i : arr)
            B[i] = X;
        playRound(B, R);
        for (int i : arr)
            (R[i] <= X ? lv : rv).push_back(i);
        dnc(lv, l, l + lv.size() - 1, N, P), dnc(rv, l + lv.size(), r, N, P);
    }
}

void allValues(int N, int W, int *P) {
    vector<int> arr;
    for (int i = 0; i < N; i++)
        arr.push_back(i);
    if (W == (N << 1)) {
        arr = merge_sort(arr, N);
        for (int i = 0; i < N; i++)
            P[arr[i]] = i + 1;
    } else
        dnc(arr, 1, N, N, P);
}