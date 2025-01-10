#include "maximum.h"
#include <bits/stdc++.h>

#define K 3

using namespace std;

int get_maximum(int N) {
    int st, en, mid, res, cur;
    vector<int> A(N, 0), arr;

    for (int i = 0; i < N; i++)
        arr.push_back(i);

    random_shuffle(arr.begin(), arr.end());

    st = 0, en = N - 1;
    while (st <= en) {
        mid = st + en >> 1;
        if (query(arr[0], mid))
            en = mid - 1, A[arr[0]] = mid;
        else
            st = mid + 1;
    }

    cur = A[arr[0]];

    for (int i = 1; i < N; i++) {
        if (query(arr[i], cur))
            continue;
        for (int j = 1;; j++) {
            if (cur + K * j >= N || query(arr[i], cur + K * j)) {
                for (int k = 1; k < K; k++) {
                    if (cur + K * j - k >= N || query(arr[i], cur + K * j - k))
                        A[arr[i]] = cur + K * j - k;
                    else
                        break;
                }
                cur = A[arr[i]];
                break;
            }
        }
    }

    return cur;
}