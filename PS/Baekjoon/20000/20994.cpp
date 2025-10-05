#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define int long long

using namespace std;

typedef array<int, 2> pr;

const int MAX = 400001;

int N, T[MAX], tree[MAX], dp[MAX], P[MAX];
vector<int> V[2];

int query(int n) {
    int res = 0;
    for (; n > 0; n -= n & -n)
        res += tree[n];
    return res;
}

void update(int n) {
    for (; n <= N << 1; n += n & -n)
        tree[n]++;
}

int get(int K) {
    if (dp[K] != -1)
        return dp[K];

    for (int i = 1; i <= N << 1; i++)
        tree[i] = P[i] = 0;

    vector<pr> arr;
    int res = 0, A, B;

    for (int i = 0; i < N; i++) {
        A = V[0][i], B = V[1][(i + K) % N];
        if (A > B)
            swap(A, B);
        P[A] = B;
    }

    for (int i = 1; i <= N << 1; i++) {
        if (!P[i])
            continue;
        res += query(P[i]) - query(i), update(P[i]);
    }

    return dp[K] = res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int A, B, ans = 0, st, en, PA, PB;
    string _S;

    cin >> N >> _S;
    for (int i = 1; i <= N * 2; i++)
        T[i] = _S[i - 1] == 'B', V[T[i]].push_back(i), dp[i - 1] = -1;

    st = 1, en = N;
    while (en - st > 3) {
        A = st + (en - st) / 3, B = en - (en - st) / 3;
        PA = get(A), PB = get(B), ans = max({ans, PA, PB});
        if (PA < PB)
            st = A;
        else
            en = B;
    }

    for (int i = st; i <= en; i++)
        ans = max(ans, get(i));

    cout << ans << '\n';

    return 0;
}