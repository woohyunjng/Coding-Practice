#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define SQRT_MAX 100100

using namespace std;

class SqrtDecomposition {
  public:
    int N, S, arr[MAX] = {}, sqrt_arr[SQRT_MAX] = {}, size;
    SqrtDecomposition(int n) : N(n) {}

    void init() {
        S = sqrt(N);
        size = N / S;
        if (N % S)
            size++;

        for (int i = 1; i <= N; i++)
            sqrt_arr[i / S] += arr[i];
    }

    void update(int pos, int val) {
        sqrt_arr[pos / S] += val - arr[pos];
        arr[pos] = val;
    }

    int query(int l, int r) {
        int res = 0;
        for (; l % S && l <= r; l++)
            res += arr[l];
        for (; (r + 1) % S && l <= r; r--)
            res += arr[r];
        for (; l <= r; l += S)
            res += sqrt_arr[l / S];
        return res;
    }
};