#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef array<int, 2> pr;
typedef array<int, 3> tp;

const int MAX = 1000001;
const int VAL = 10007;

vector<int> A[MAX];
map<pr, int> mp;

int T[2][MAX], B[MAX], MOD[2] = {1'000'000'007, 998'244'353};
tp tree[MAX * 4];

tp merge(tp X, tp Y) { return {(X[0] + Y[0] * T[0][X[2]]) % MOD[0], (X[1] + Y[1] * T[1][X[2]]) % MOD[1], X[2] + Y[2]}; }

void update(int n, int s, int e, int x, tp v) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n] = v;
    else {
        int m = s + e >> 1;
        update(n << 1, s, m, x, v), update(n << 1 | 1, m + 1, e, x, v);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

tp query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return {0, 0, 0};
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(query(n << 1, s, m, l, r), query(n << 1 | 1, m + 1, e, l, r));
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, M, N, Y, X[2], S[2] = {0, 0};
    vector<int> arr, comp;

    cin >> K >> M >> N, T[0][0] = 1, T[1][0] = 1;
    for (int i = 1; i <= K; i++) {
        T[0][i] = (T[0][i - 1] * VAL) % MOD[0], S[0] = (S[0] + T[0][i - 1]) % MOD[0];
        T[1][i] = (T[1][i - 1] * VAL) % MOD[1], S[1] = (S[1] + T[1][i - 1]) % MOD[1];
    }

    for (int i = 0; i < M; i++) {
        arr.clear(), arr.resize(K, 0);
        for (int j = 0; j < K; j++)
            cin >> Y, A[i].push_back(Y), arr[Y - 1] = j + 1;
        X[0] = 0, X[1] = 0;
        for (int j = 0; j < K; j++)
            X[0] = (X[0] + arr[j] * T[0][j]) % MOD[0], X[1] = (X[1] + arr[j] * T[1][j]) % MOD[1];
        mp[{X[0], X[1]}] = i;
    }

    for (int i = 1; i <= N; i++)
        cin >> B[i], comp.push_back(B[i]);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 1; i <= N; i++)
        B[i] = lower_bound(comp.begin(), comp.end(), B[i]) - comp.begin() + 1;

    for (int i = 1; i < K; i++)
        update(1, 1, N, B[i], {i, i, 1});
    for (int i = K; i <= N; i++) {
        update(1, 1, N, B[i], {i, i, 1});
        X[0] = (query(1, 1, N, 1, N)[0] - (i - K) * S[0] % MOD[0] + MOD[0]) % MOD[0];
        X[1] = (query(1, 1, N, 1, N)[1] - (i - K) * S[1] % MOD[1] + MOD[1]) % MOD[1];
        if (mp.find({X[0], X[1]}) != mp.end()) {
            Y = mp[{X[0], X[1]}];
            for (int j : A[Y])
                cout << j << ' ';
            cout << '\n';
            return 0;
        }
        update(1, 1, N, B[i - K + 1], {0, 0, 0});
    }

    cout << 0 << '\n';

    return 0;
}