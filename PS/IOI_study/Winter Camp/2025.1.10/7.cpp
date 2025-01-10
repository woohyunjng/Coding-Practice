#include "moon.h"
#include <bits/stdc++.h>
using namespace std;

#define MAX 1010

int N, A[MAX], st[MAX][MAX], en[MAX][MAX];

void divide_and_conquer(int L, int R) {
    if (L > R)
        return;
    if (L == R) {
        st[L][L] = A[L];
        return;
    }

    int mid = L + R >> 1, X = A[mid];
    st[mid][mid] = X;
    for (int i = mid + 1; i <= R; i++)
        X = moon(X, A[i]), st[mid][i] = X;
    if (mid > L) {
        X = A[mid - 1], en[mid][mid - 1] = X;
        for (int i = mid - 2; i >= L; i--)
            X = moon(A[i], X), en[mid][i] = X;
    }

    divide_and_conquer(L, mid - 1), divide_and_conquer(mid + 1, R);
}

int query_dnc(int L, int R, int X, int Y) {
    if (L >= R)
        return -1;

    int mid = L + R >> 1, A, B;
    if (X <= mid && mid <= Y) {
        if (X == mid)
            return st[mid][Y];
        return moon(en[mid][X], st[mid][Y]);
    }

    A = query_dnc(L, mid - 1, X, Y), B = query_dnc(mid + 1, R, X, Y);
    if (A == -1)
        return B;
    return A;
}

void init(int n, vector<int> a) {
    N = n;
    for (int i = 0; i < N; i++)
        A[i] = a[i];
    divide_and_conquer(0, N - 1);
}

int query(int L, int R) {
    if (L == R)
        return A[L];
    return query_dnc(0, N - 1, L, R);
}
