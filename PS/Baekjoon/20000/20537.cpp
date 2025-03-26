#include "gap.h"

#include <bits/stdc++.h>
#define int long long

using namespace std;

int findGap(signed T, signed N) {
    int A, B, X, Y, K, ans = 0;

    if (T == 1) {
        vector<int> left, right, arr;
        A = 0, B = 1'000'000'000'000'000'000;
        for (int i = 0; i < N; i += 2) {
            MinMax(A, B, &X, &Y);
            left.push_back(X), right.push_back(Y);
            if (X == Y)
                right.pop_back();
            A = X + 1, B = Y - 1;
        }
        reverse(right.begin(), right.end());
        arr = left, arr.insert(arr.end(), right.begin(), right.end());

        for (int i = 0; i < N - 1; i++)
            ans = max(ans, arr[i + 1] - arr[i]);
    } else {
        MinMax(0, 1'000'000'000'000'000'000, &X, &Y);
        K = ans = (Y - X + N - 2) / (N - 1);

        vector<int> arr;

        for (int i = X; i <= Y; i += K + 1) {
            MinMax(i, i + K, &A, &B);
            if (A != -1) {
                if (!arr.empty())
                    ans = max(ans, A - arr.back());
                arr.push_back(B);
            }
        }
    }

    return ans;
}
