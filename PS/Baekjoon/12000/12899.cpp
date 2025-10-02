#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000000;

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

    int N, T, X;

    cin >> N;
    while (N--) {
        cin >> T >> X;
        if (T == 1)
            add(1, 1, MAX, X);
        else
            cout << remove(1, 1, MAX, X) << '\n';
    }

    return 0;
}