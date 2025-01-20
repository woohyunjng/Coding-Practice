#include <bits/stdc++.h>
#define int long long

#define MAX 600100
using namespace std;

int N, X[MAX], Y[MAX], W[MAX], H[MAX], tree[MAX * 4];
vector<int> arr;

int merge(int A, int B) {
    if (H[A] > H[B])
        return B;
    return A;
}

void init(int n, int s, int e) {
    if (s == e)
        tree[n] = s;
    else {
        int m = s + e >> 1;
        init(n << 1, s, m), init(n << 1 | 1, m + 1, e);
        tree[n] = merge(tree[n << 1], tree[n << 1 | 1]);
    }
}

int query(int n, int s, int e, int l, int r) {
    if (r < s || e < l)
        return 0;
    else if (l <= s && e <= r)
        return tree[n];
    else {
        int m = s + e >> 1;
        return merge(
            query(n << 1, s, m, l, r),
            query(n << 1 | 1, m + 1, e, l, r));
    }
}

int dnc(int l, int r, int v) {
    if (l > r)
        return 0;

    int X = query(1, 1, N, l, r), L = W[r] - W[l - 1], lv, rv;

    lv = dnc(l, X - 1, H[X]), rv = dnc(X + 1, r, H[X]);
    if (lv < rv)
        swap(lv, rv);
    arr.push_back(rv);
    return (H[X] - v) * L + lv;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int K, res = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];
    N >>= 1, --N;

    H[0] = 2000000000;
    for (int i = 1; i <= N; i++)
        W[i] = X[2 * i], H[i] = Y[2 * i];
    init(1, 1, N);

    arr.push_back(dnc(1, N, 0));
    sort(arr.begin(), arr.end(), greater<int>());

    cin >> K;
    for (int i = 0; i < K; i++)
        res += arr[i];
    cout << res << '\n';

    return 0;
}