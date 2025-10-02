#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

int tree[MAX * 4];

void add(int n, int s, int e, int x) {
    if (x < s || e < x)
        return;
    else if (s == e)
        tree[n]++;
    else {
        int m = s + e >> 1;
        add(n << 1, s, m, x), add(n << 1 | 1, m + 1, e, x);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }
}

int remove(int n, int s, int e, int x) {
    if (s == e) {
        tree[n]--;
        return s;
    } else {
        int m = s + e >> 1, res;
        if (x <= tree[n << 1])
            res = remove(n << 1, s, m, x);
        else
            res = remove(n << 1 | 1, m + 1, e, x - tree[n << 1]);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
        return res;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, V = 1;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        add(1, 1, N, i);

    cout << '<';
    for (int i = 0; i < N; i++) {
        V = (V + K - 2) % (N - i) + 1;
        cout << remove(1, 1, N, V) << (i == N - 1 ? "" : ", ");
    }
    cout << ">\n";

    return 0;
}