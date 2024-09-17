#include "nile.h"
#include <bits/stdc++.h>
#define int long long

#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> parent, res, odd[2], even[2], sz, sum;

int find(int K) {
    if (parent[K] != K)
        parent[K] = find(parent[K]);
    return parent[K];
}

int calc(int X) {
    X = find(X);
    if (sz[X] & 1)
        res[X] = sum[X] + min(odd[1][X], even[0][X]);
    else
        res[X] = sum[X];
    return res[X];
}

int merge(int X, int Y) {
    X = find(X), Y = find(Y);
    int ret = -res[X] - res[Y];

    if (X > Y)
        swap(X, Y);

    if (sz[X] & 1) {
        odd[0][X] = min(odd[0][X], even[0][Y]);
        even[0][X] = min(even[0][X], odd[0][Y]);
        odd[1][X] = min(odd[1][X], even[1][Y]);
        even[1][X] = min(even[1][X], odd[1][Y]);
    } else {
        odd[0][X] = min(odd[0][X], odd[0][Y]);
        even[0][X] = min(even[0][X], even[0][Y]);
        odd[1][X] = min(odd[1][X], odd[1][Y]);
        even[1][X] = min(even[1][X], even[1][Y]);
    }

    sum[X] = sum[X] + sum[Y];
    parent[Y] = X;
    sz[X] += sz[Y];

    res[X] = calc(X);
    ret += res[X];

    return ret;
}

vector<int> calculate_costs(vector<signed> W, vector<signed> A,
                            vector<signed> B, vector<signed> E) {
    int Q = E.size(), N = W.size(), D, cur = 0, X, Y;
    vector<pr> queries, one, two;
    vector<tp> arr(N);

    parent.resize(N + 1), res.resize(N + 1), sz.resize(N + 1), sum.resize(N + 1);
    for (int i = 0; i < 2; i++)
        odd[i].resize(N + 1), even[i].resize(N + 1);

    for (int i = 0; i < N; i++)
        arr[i] = {W[i], A[i] - B[i], B[i]};
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        parent[i] = i;
        sz[i] = 1;

        res[i] = arr[i][1] + arr[i][2];
        cur += res[i];
        sum[i] = arr[i][2];

        odd[1][i] = arr[i][1];
        odd[0][i] = even[0][i] = even[1][i] = INF;
    }

    vector<int> R(Q, 0);

    for (int i = 1; i < N; i++)
        one.push_back({arr[i][0] - arr[i - 1][0], i});
    for (int i = 2; i < N; i++)
        two.push_back({arr[i][0] - arr[i - 2][0], i});
    sort(one.begin(), one.end(), greater<pr>());
    sort(two.begin(), two.end(), greater<pr>());

    for (int i = 0; i < Q; i++)
        queries.push_back({E[i], i});
    sort(queries.begin(), queries.end());

    for (pr i : queries) {
        D = i.first;

        while (!one.empty() && one.back().first <= D) {
            X = one.back().second, one.pop_back();
            cur += merge(X - 1, X);
        }

        while (!two.empty() && two.back().first <= D) {
            X = two.back().second - 1, two.pop_back();
            Y = find(X);
            cur -= res[Y];

            if ((X - Y) & 1)
                even[0][Y] = min(even[0][Y], arr[X][1]);
            else
                odd[0][Y] = min(odd[0][Y], arr[X][1]);

            cur += calc(Y);
        }

        R[i.second] = cur;
    }

    return R;
}