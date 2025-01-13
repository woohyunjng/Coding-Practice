#include "squirrel.h"

#include <bits/stdc++.h>
#define int long long

#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef pair<int, int> pr;

int fly(vector<signed> D, vector<signed> H, vector<signed> W, signed L, signed R) {
    int N = D.size(), res, C = 0, X = 0, K, A, Z;
    deque<pr> dq, temp;
    bool flag = true;

    for (int i = 0; i < N - 1; i++)
        flag &= D[i + 1] - D[i] <= H[i];
    if (!flag)
        return -1;

    dq.push_front({0, 0}), dq.push_back({L, W[0]}), dq.push_back({
                                                        H[0],
                                                        INF,
                                                    });
    for (int i = 1; i < N; i++) {
        X += D[i] - D[i - 1], A = 0;
        while (!dq.empty() && dq.front().first < X) {
            A = dq.front().second, Z = dq.front().first, dq.pop_front();
            C += A * (min(X, dq.front().first) - Z);
        }
        dq.push_front({X, A});

        A = H[i] + X;
        if (dq.back().first >= A) {
            while (!dq.empty() && dq.back().first >= A)
                dq.pop_back();
            dq.push_back({A, INF});
        }

        while (!dq.empty() && dq.back().second >= W[i])
            A = dq.back().first, dq.pop_back();
        if (A != H[i] + X)
            dq.push_back({
                A,
                W[i],
            });
        dq.push_back({H[i] + X, INF});
    }

    X += R;
    while (!dq.empty() && dq.front().first < X) {
        A = dq.front().second, Z = dq.front().first, dq.pop_front();
        C += A * (min(X, dq.front().first) - Z);
    }
    res = C;

    return res;
}