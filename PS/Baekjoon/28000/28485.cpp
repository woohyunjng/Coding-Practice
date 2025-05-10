#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

const int MAX = 100001;

int min_prime_factor[MAX], V[MAX], tree[MAX], ans[MAX], L[MAX], R[MAX], C[MAX];
vector<int> primes;

int query(int idx) {
    int res = 0;
    while (idx > 0)
        res += tree[idx], idx -= (idx & -idx);
    return res;
}

void update(int idx, int val) {
    while (idx < MAX)
        tree[idx] += val, idx += (idx & -idx);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, Y, Z;
    vector<int> queries, arr;

    min_prime_factor[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (min_prime_factor[i] == 0)
            min_prime_factor[i] = i, primes.push_back(i);

        for (int p : primes) {
            if (i * p >= MAX)
                break;
            min_prime_factor[i * p] = p;
            if (i % p == 0)
                break;
        }
    }

    for (int i = 1; i < MAX; i++) {
        if (min_prime_factor[i] == i)
            V[i] = i + 1;
        else {
            X = min_prime_factor[i], V[i] = V[i / X], Y = 1, Z = i / X;
            while (Z % X == 0)
                Z /= X, Y = Y * X + 1;
            V[i] = V[i] / Y * (Y * X + 1);
        }
    }

    for (int i = 1; i < MAX; i++)
        V[i] -= i, arr.push_back(i);

    sort(arr.begin(), arr.end(), [](int x, int y) { return V[x] > V[y]; }), X = 0;

    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> L[i] >> R[i] >> C[i], queries.push_back(i);
    sort(queries.begin(), queries.end(), [](int x, int y) { return C[x] > C[y]; });

    for (int i : queries) {
        while (X < arr.size() && V[arr[X]] > C[i])
            update(arr[X], 1), X++;
        ans[i] = query(R[i]) - query(L[i] - 1);
    }

    for (int i = 1; i <= Q; i++)
        cout << ans[i] << '\n';

    return 0;
}